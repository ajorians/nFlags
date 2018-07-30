#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#endif
#include "MainMenu.h"
#include "Replacements.h"
#include "ImageLoader.h"
#include "Thumbnail.h"
#include "SDL/SDL_gfxPrimitives.h"

#define MENU_SELECTOR_LINE_WIDTH (2)

#define MENU_FLAG_MAX_WIDTH   (72)
#define MENU_FLAG_MAX_HEIGHT  (50)

#define MENU_FLAG_SPACING_HORIZ  (15)
#define MENU_FLAG_SPACING_VERT   (22)

#define MENU_TITLE_TOP        (2)

void CreateMainMenu(struct MainMenu** ppMenu, struct Config* pConfig, struct SDL_Surface* pScreen)
{
   *ppMenu = malloc(sizeof(struct MainMenu));
   struct MainMenu* pMenu = (*ppMenu);

   pMenu->m_pConfig = pConfig;
   pMenu->m_pScreen = pScreen;

   pMenu->m_eChoice = ShowDetails;
   pMenu->m_eLastSelectedFlag = FLAGS_MAX;
   pMenu->m_eSelectedFlag = TheUnitedStates;

   pMenu->m_pFont = LoadFont("arial.ttf", NSDL_FONT_THIN, 255/*R*/, 0/*G*/, 0/*B*/, 16);

   CreateFlagInformation(&pMenu->m_pFlagInformation);

   int nNumFlags = GetNumberOfFlags(pMenu->m_pFlagInformation);

   const int nNumFlagRows       = (SCREEN_HEIGHT - MENU_TITLE_TOP - 15/*Height*/) / (MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT);
   const int nNumFlagColumns    = SCREEN_WIDTH / (MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ);

   const int nNumRowsNeeded     = min(max(1, (nNumFlags + nNumFlagRows) / nNumFlagRows), nNumFlagRows);
   const int nNumColsNeeded     = max(1, (nNumFlags + nNumRowsNeeded )/ nNumRowsNeeded );

   const int nFlagSurfaceHeight = nNumRowsNeeded * (MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT);
   const int nFlagSurfaceWidth  = nNumColsNeeded * (MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ);

   pMenu->m_nItemsPerRow = nNumColsNeeded;
   pMenu->m_nSrcScrollX = 0;
   pMenu->m_nScrollX = -1;

   pMenu->m_pFlagsSurface = SDL_CreateRGBSurface(0, nFlagSurfaceWidth, nFlagSurfaceHeight, SCREEN_BIT_DEPTH, 0, 0, 0, 0);
   SDL_FillRect(pMenu->m_pFlagsSurface, NULL, SDL_MapRGB(pMenu->m_pFlagsSurface->format, 255, 215, 139));
   int x = 0;
   int y = 0;
   for(int i=0; i<nNumFlags; i++)
   {
      DrawText(pMenu->m_pFlagsSurface, pMenu->m_pFont, x + 3, y, "Loading...", 0,0,0);
      x += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
      if (x >= pMenu->m_pFlagsSurface->w)
      {
         x = 0;
         y += MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT;
      }
   }

   pMenu->m_eNextFlagImageToLoad = Afghanistan;

#ifdef _TINSPIRE
   //pMenu->m_pTitle = nSDL_LoadImage(image_TwoDigits);
#endif
}

void FreeMainMenu(struct MainMenu** ppMenu)
{
   struct MainMenu* pMenu = *ppMenu;

   FreeFont(pMenu->m_pFont);
   FreeFlagInformation(&pMenu->m_pFlagInformation);
   SDL_FreeSurface(pMenu->m_pFlagsSurface);
   pMenu->m_pFlagsSurface = NULL;

   pMenu->m_pConfig = NULL;//Does not own
   pMenu->m_pScreen = NULL;//Does not own

#ifdef _TINSPIRE
   //SDL_FreeSurface(pMenu->m_pTitle);
   //pMenu->m_pTitle = NULL;
#endif

   free(*ppMenu);
   *ppMenu = NULL;
}

int PollEvents(struct MainMenu* pMenu)
{
   SDL_Event event;
   while (SDL_PollEvent(&event))
   {
      switch (event.type)
      {
      case SDL_KEYDOWN:
         printf("Key press detected\n");
         switch (event.key.keysym.sym)
         {
         case SDLK_ESCAPE:
            printf("Hit Escape!n");
            pMenu->m_eChoice = Quit;
            return 0;
            break;

         case SDLK_4:
         case SDLK_LEFT:
            if (pMenu->m_eSelectedFlag > (enum Flags)0)
            {
               pMenu->m_eLastSelectedFlag = pMenu->m_eSelectedFlag;
               pMenu->m_eSelectedFlag--;
            }
            break;

         case SDLK_6:
         case SDLK_RIGHT:
            if (pMenu->m_eSelectedFlag < (enum Flags)(FLAGS_MAX-1) )
            {
               pMenu->m_eLastSelectedFlag = pMenu->m_eSelectedFlag;
               pMenu->m_eSelectedFlag++;
            }
            break;

         case SDLK_8:
         case SDLK_UP:
            if (pMenu->m_eSelectedFlag >= (enum Flags)(0+pMenu->m_nItemsPerRow) )
            {
               pMenu->m_eLastSelectedFlag = pMenu->m_eSelectedFlag;
               pMenu->m_eSelectedFlag-= pMenu->m_nItemsPerRow;
            }
            break;

         case SDLK_2:
         case SDLK_DOWN:
            if (pMenu->m_eSelectedFlag <= (enum Flags)(FLAGS_MAX - 1 - pMenu->m_nItemsPerRow))
            {
               pMenu->m_eLastSelectedFlag = pMenu->m_eSelectedFlag;
               pMenu->m_eSelectedFlag += pMenu->m_nItemsPerRow;
            }
            break;

         case SDLK_5:
         case SDLK_SPACE:
         case SDLK_RETURN:
         case SDLK_LCTRL:
            if (pMenu->m_eChoice == ShowDetails) {
               return 0;
            }
            break;

         default:
            break;
         }
      }
   }

   return 1;
}

void DrawFlagsSurface(struct MainMenu* pMenu, SDL_Surface* pFlagsSurface)
{
   if (pMenu->m_eNextFlagImageToLoad != FLAGS_MAX)
   {
      int nFlag = (int)pMenu->m_eNextFlagImageToLoad;
      int nX = 0;
      int nY = 0;
      for (int i = 0; i <= nFlag; i++)
      {
         int selected = (pMenu->m_eSelectedFlag == (enum Flags)i) ? 1 : 0;

         if( i == nFlag )
         {
            DrawFlagThumbnail(pMenu->m_pFlagInformation, pMenu->m_eNextFlagImageToLoad,  pFlagsSurface, nX, nY, MENU_FLAG_MAX_WIDTH, MENU_FLAG_MAX_HEIGHT);
         }

         nX += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
         if (nX >= pFlagsSurface->w)
         {
            nX = 0;
            nY += MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT;
         }
      }

      pMenu->m_eNextFlagImageToLoad++;
   }

   if( pMenu->m_eLastSelectedFlag != FLAGS_MAX )
   {
      int nLastSelectedFlag = (int)pMenu->m_eLastSelectedFlag;
      int nX = 0;
      int nY = 0;
      for( int i=0; i<= nLastSelectedFlag; i++)
      {
         if( i == nLastSelectedFlag)
         {
            SDL_Rect dst;
            dst.x = nX;
            dst.y = nY + MENU_FLAG_MAX_HEIGHT;
            dst.w = min(pMenu->m_pFlagsSurface->w - dst.w, MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ);
            dst.h = min(pMenu->m_pFlagsSurface->h - dst.y, MENU_FLAG_SPACING_VERT);

            SDL_FillRect(pFlagsSurface, &dst, SDL_MapRGB(pMenu->m_pFlagsSurface->format, 255, 215, 139));
         }
         nX += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
         if (nX >= pFlagsSurface->w)
         {
            nX = 0;
            nY += MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT;
         }
      }
      pMenu->m_eLastSelectedFlag = FLAGS_MAX;
   }

   int nSelectedFlag = (int)pMenu->m_eSelectedFlag;
   int x = 0;
   int y = 0;
   for( int i=0; i<= nSelectedFlag; i++)
   {
      if( i == nSelectedFlag)
      {
         SmartDrawText(pFlagsSurface, pMenu->m_pFont, x, y + MENU_FLAG_MAX_HEIGHT, MENU_FLAG_MAX_WIDTH, GetCountryName(pMenu->m_pFlagInformation, pMenu->m_eSelectedFlag), 0, 0, 0);
      }
      x += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
      if (x >= pFlagsSurface->w)
      {
         x = 0;
         y += MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT;
      }
   }

}

void UpdateDisplay(struct MainMenu* pMenu)
{
   int r = 255, g = 215, b = 139;
#ifdef _TINSPIRE
   if (!has_colors)
   {
      r = 255, g = 255, b = 255;
   }
#endif

   SDL_FillRect(pMenu->m_pScreen, NULL, SDL_MapRGB(pMenu->m_pScreen->format, r, g, b));

   DrawText(pMenu->m_pScreen, pMenu->m_pFont, 15, MENU_TITLE_TOP, "nFlags", 0, 0, 0);

   if( pMenu->m_eNextFlagImageToLoad != FLAGS_MAX )
   {
      char text[32];
      strcpy(text, "Loading Flag ");
      char buffer[8];
      IntToA(buffer, sizeof(buffer), (int)pMenu->m_eNextFlagImageToLoad);
      strcat(text, buffer);
      strcat(text, " of ");
      IntToA(buffer, sizeof(buffer), (int)FLAGS_MAX);
      strcat(text, buffer);

      DrawText(pMenu->m_pScreen, pMenu->m_pFont, SCREEN_WIDTH / 3, MENU_TITLE_TOP, text, 0, 0, 0);
   }

   DrawFlagsSurface(pMenu, pMenu->m_pFlagsSurface);

   int nFlagPieceWidth = MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;

   int nCurrentX = 0;
   for(int i=0; i<(int)pMenu->m_eSelectedFlag; i++)
   {
      nCurrentX += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
      if (nCurrentX >= pMenu->m_pFlagsSurface->w)
      {
         nCurrentX = 0;
      }
   }

   //Initial scroll X if too jarring to scroll on opening
   if (pMenu->m_nScrollX == -1) {
      int n = nCurrentX - nFlagPieceWidth;
      if (n < 0)
         n = 0;
      if (n >= (pMenu->m_pFlagsSurface->w - nFlagPieceWidth))
         n = pMenu->m_pFlagsSurface->w - nFlagPieceWidth;
      pMenu->m_nScrollX = pMenu->m_nSrcScrollX = n;
   }

   const int nDestinationLeft = 10;
   const int nDestinationWidth = SCREEN_WIDTH - nDestinationLeft;

   SDL_Rect src;
   src.w = nDestinationWidth;
   src.h = pMenu->m_pFlagsSurface->h;
   src.x = pMenu->m_nSrcScrollX;
   src.y = 0;

   int nDstY = (SCREEN_HEIGHT - MENU_TITLE_TOP - 15/*height*/ - src.h - 3/*Little padding*/) / 2 + MENU_TITLE_TOP + 15/*height*/;

   SDL_Rect dst;
   dst.w = nDestinationWidth;
   dst.h = src.h;
   dst.x = nDestinationLeft;
   dst.y = nDstY;
   SDL_BlitSurface(pMenu->m_pFlagsSurface, &src, pMenu->m_pScreen, &dst);

   if (pMenu->m_nSrcScrollX < pMenu->m_nScrollX)
   {
      int nAmount = 3;
      if ((pMenu->m_nScrollX - pMenu->m_nSrcScrollX) > (4 * nFlagPieceWidth))
         nAmount = 18;
      else if ((pMenu->m_nScrollX - pMenu->m_nSrcScrollX) > (3 * nFlagPieceWidth))
         nAmount = 8;
      else if ((pMenu->m_nScrollX - pMenu->m_nSrcScrollX) > (2 * nFlagPieceWidth))
         nAmount = 6;
      pMenu->m_nSrcScrollX += nAmount;
   }
   if (pMenu->m_nSrcScrollX > pMenu->m_nScrollX)
   {
      int nAmount = 3;
      if ((pMenu->m_nSrcScrollX - pMenu->m_nScrollX) > (4 * nFlagPieceWidth))
         nAmount = 18;
      else if ((pMenu->m_nSrcScrollX - pMenu->m_nScrollX) > (3 * nFlagPieceWidth))
         nAmount = 8;
      else if ((pMenu->m_nSrcScrollX - pMenu->m_nScrollX) > (2 * nFlagPieceWidth))
         nAmount = 6;
      pMenu->m_nSrcScrollX -= nAmount;
   }

   //Check if needs to scroll
   int nCurrentFlagLeftScreen = pMenu->m_nScrollX > nCurrentX ? 1 : 0;
   int nCurrentFlagRightScreen = (pMenu->m_nScrollX + nDestinationWidth - (nFlagPieceWidth + 15/*Little extra*/) - nCurrentX) < 0 ? 1 : 0;
   if (nCurrentFlagLeftScreen == 1 || nCurrentFlagRightScreen == 1)
   {
      if (nCurrentFlagLeftScreen == 1) {
         pMenu->m_nScrollX -= (nFlagPieceWidth*1.5);
         if (pMenu->m_nScrollX < 0)
            pMenu->m_nScrollX = 0;
      }
      else if (nCurrentFlagRightScreen == 1) {
         pMenu->m_nScrollX += (nFlagPieceWidth*1.5);
         if (pMenu->m_nScrollX > (pMenu->m_pFlagsSurface->w - nDestinationWidth))
            pMenu->m_nScrollX = pMenu->m_pFlagsSurface->w - nDestinationWidth;
      }
   }

   SDL_UpdateRect(pMenu->m_pScreen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

int MainMenuLoop(struct MainMenu* pMenu)
{
   if (PollEvents(pMenu) == 0)
      return 0;

   UpdateDisplay(pMenu);

   return 1;
}

int MainMenuShouldQuit(struct MainMenu* pMenu)
{
   return pMenu->m_eChoice == Quit;
}

enum Flags MainMenuGetSelectedFlag(struct MainMenu* pMenu)
{
   return pMenu->m_eSelectedFlag;
}


