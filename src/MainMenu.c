#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#endif
#include "MainMenu.h"
#include "Replacements.h"
#include "SDL/SDL_gfxPrimitives.h"

#define MENU_SELECTOR_LINE_WIDTH (2)

#define MENU_FLAG_MAX_WIDTH   (80)
#define MENU_FLAG_MAX_HEIGHT  (60)

#define MENU_FLAG_SPACING_HORIZ  (20)
#define MENU_FLAG_SPACING_VERT   (20)

void CreateMainMenu(struct MainMenu** ppMenu, struct Config* pConfig, struct SDL_Surface* pScreen)
{
   *ppMenu = malloc(sizeof(struct MainMenu));
   struct MainMenu* pMenu = (*ppMenu);

   pMenu->m_pConfig = pConfig;
   pMenu->m_pScreen = pScreen;

   pMenu->m_eChoice = ShowDetails;
   pMenu->m_eSelectedFlag = UnitedStates;

   pMenu->m_pFont = LoadFont("arial.ttf", NSDL_FONT_THIN, 255/*R*/, 0/*G*/, 0/*B*/, 16);

   CreateFlagInformation(&pMenu->m_pFlagInformation);

   int nNumFlags = GetNumberOfFlags(pMenu->m_pFlagInformation);

   const int nNumFlagRows       = SCREEN_HEIGHT / (MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT);
   const int nNumFlagColumns    = SCREEN_WIDTH / (MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ);

   const int nNumRowsNeeded     = max(1, (nNumFlags + nNumFlagColumns) / nNumFlagColumns);
   const int nNumColsNeeded     = max(1, (nNumFlags + nNumRowsNeeded )/ nNumRowsNeeded );

   const int nFlagSurfaceHeight = nNumRowsNeeded * (MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT);
   const int nFlagSurfaceWidth  = nNumColsNeeded * (MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ);

   pMenu->m_pFlagsSurface = SDL_CreateRGBSurface(0, nFlagSurfaceWidth, nFlagSurfaceHeight, SCREEN_BIT_DEPTH, 0, 0, 0, 0);

   CreateImageLoader(&pMenu->m_pImageLoader, nNumFlags);

   pMenu->m_ppThumbnails = malloc(sizeof(struct Thumbnail*) * nNumFlags);
   for (int i = 0; i < nNumFlags; i++)
      (pMenu->m_ppThumbnails)[i] = NULL;

   for (int i = 0; i < nNumFlags; i++)
   {
      CreateThumbnail(&(pMenu->m_ppThumbnails)[i], pMenu->m_pFlagInformation, pMenu->m_pImageLoader, (enum Flags)i);
   }

   pMenu->m_eNextFlagImageToLoad = Brazil;

#ifdef _TINSPIRE
   pMenu->m_pTitle = nSDL_LoadImage(image_TwoDigits);
#endif
}

void FreeMainMenu(struct MainMenu** ppMenu)
{
   struct MainMenu* pMenu = *ppMenu;

   FreeFont(pMenu->m_pFont);
   int nNumFlags = GetNumberOfFlags(pMenu->m_pFlagInformation);
   for (int i = 0; i < nNumFlags; i++)
   {
      if ((pMenu->m_ppThumbnails)[i] != NULL)
      {
         FreeThumbnail(&(pMenu->m_ppThumbnails)[i]);
         (pMenu->m_ppThumbnails)[i] = NULL;
      }
   }
   FreeImageLoader(&pMenu->m_pImageLoader);
   FreeFlagInformation(&pMenu->m_pFlagInformation);
   SDL_FreeSurface(pMenu->m_pFlagsSurface);
   pMenu->m_pFlagsSurface = NULL;

   pMenu->m_pConfig = NULL;//Does not own
   pMenu->m_pScreen = NULL;//Does not own

#ifdef _TINSPIRE
   SDL_FreeSurface(pMenu->m_pTitle);
   pMenu->m_pTitle = NULL;
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
               pMenu->m_eSelectedFlag--;
            }
            break;

         case SDLK_6:
         case SDLK_RIGHT:
            if (pMenu->m_eSelectedFlag < (enum Flags)(FLAGS_MAX-1) )
            {
               pMenu->m_eSelectedFlag++;
            }
            break;

         case SDLK_8:
         case SDLK_UP:
            
            break;

         case SDLK_2:
         case SDLK_DOWN:
            
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
   SDL_FillRect(pFlagsSurface, NULL, SDL_MapRGB(pFlagsSurface->format, 255, 215, 139));

   int nNumFlags = GetNumberOfFlags(pMenu->m_pFlagInformation);
   int nX = 0;
   int nY = 0;
   for (int i = 0; i < nNumFlags; i++)
   {
      if ((pMenu->m_ppThumbnails)[i] != NULL)
      {
         int selected = (pMenu->m_eSelectedFlag == (enum Flags)i) ? 1 : 0;

         DrawThumbnail((pMenu->m_ppThumbnails)[i], pFlagsSurface, selected, nX, nY, MENU_FLAG_MAX_WIDTH, MENU_FLAG_MAX_HEIGHT);
      }
      nX += MENU_FLAG_MAX_WIDTH + MENU_FLAG_SPACING_HORIZ;
      if (nX >= pFlagsSurface->w)
      {
         nX = 0;
         nY += MENU_FLAG_MAX_HEIGHT + MENU_FLAG_SPACING_VERT;
      }
   }
}

void UpdateDisplay(struct MainMenu* pMenu)
{
#ifdef _TINSPIRE
   if (!has_colors)
   {
      SDL_FillRect(pMenu->m_pScreen, NULL, SDL_MapRGB(pMenu->m_pScreen->format, 255, 255, 255));
   }
#else
   SDL_FillRect(pMenu->m_pScreen, NULL, SDL_MapRGB(pMenu->m_pScreen->format, 255, 215, 139));
#endif

   DrawText(pMenu->m_pScreen, pMenu->m_pFont, 15, 15, "nFlags", 0, 0, 0);

   DrawFlagsSurface(pMenu, pMenu->m_pFlagsSurface/*, &nCurrentLevelY*/);

   /*if (pMenu->m_nScrollY == -1) {
      int n = nCurrentLevelY - g_LevelPieceHeight;
      if (n < 0)
         n = 0;
      if (n >= (pMenu->m_pLevelSurface->h - g_LevelPieceHeight))
         n = pMenu->m_pLevelSurface->h - g_LevelPieceHeight;
      pMenu->m_nScrollY = pMenu->m_nSrcScrollY = n;
   }*/

   const int nDestinationLeft = 10;
   const int nDestinationWidth = SCREEN_WIDTH - nDestinationLeft;

   SDL_Rect src;
   src.w = nDestinationWidth;
   src.h = pMenu->m_pFlagsSurface->h;
   src.x = 0;
   src.y = 0;

   SDL_Rect dst;
   dst.w = nDestinationWidth;
   dst.h = src.h;
   dst.x = nDestinationLeft;
   dst.y = SCREEN_HEIGHT / 2 - src.h / 2;
   SDL_BlitSurface(pMenu->m_pFlagsSurface, &src, pMenu->m_pScreen, &dst);

   SDL_UpdateRect(pMenu->m_pScreen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

int MainMenuLoop(struct MainMenu* pMenu)
{
   if (PollEvents(pMenu) == 0)
      return 0;

   if (pMenu->m_eNextFlagImageToLoad != FLAGS_MAX)
   {
      LoadFlagImage(pMenu->m_pImageLoader, pMenu->m_pFlagInformation, pMenu->m_eNextFlagImageToLoad++);
   }
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


