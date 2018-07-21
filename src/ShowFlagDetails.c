#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#endif
#include "ShowFlagDetails.h"
#include "Replacements.h"
#include "SDL/SDL_gfxPrimitives.h"

void CreateShowFlagDetails(struct ShowFlagDetails** ppShowFlagDetails, struct SDL_Surface* pScreen, enum Flags eFlag)
{
   *ppShowFlagDetails = malloc(sizeof(struct ShowFlagDetails));
   struct ShowFlagDetails* pDetails = (*ppShowFlagDetails);

   pDetails->m_pScreen = pScreen;

   pDetails->m_eFlag = eFlag;

   pDetails->m_pFont = LoadFont("arial.ttf", NSDL_FONT_THIN, 255/*R*/, 0/*G*/, 0/*B*/, 12);

   CreateFlagInformation(&pDetails->m_pFlagInformation);

   CreateImageLoader(&pDetails->m_pImageLoader, 1);
   LoadFlagImage(pDetails->m_pImageLoader, pDetails->m_pFlagInformation, pDetails->m_eFlag);
}

void FreeShowFlagDetails(struct ShowFlagDetails** ppShowFlagDetails)
{
   struct ShowFlagDetails* pDetails = *ppShowFlagDetails;

   FreeFont(pDetails->m_pFont);
   pDetails->m_pFont = NULL;
   FreeImageLoader(&pDetails->m_pImageLoader);
   FreeFlagInformation(&pDetails->m_pFlagInformation);

   pDetails->m_pScreen = NULL;//Does not own

   free(*ppShowFlagDetails);
   *ppShowFlagDetails = NULL;
}

int PollDetailsEvents(struct ShowFlagDetails* pDetails)
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
            return 0;
            break;

         case SDLK_4:
         case SDLK_LEFT:
            /*if (pMenu->m_eSelectedFlag > (enum Flags)0)
            {
               pMenu->m_eSelectedFlag--;
            }*/
            break;

         case SDLK_6:
         case SDLK_RIGHT:
            /*if (pMenu->m_eSelectedFlag < (enum Flags)(FLAGS_MAX-1) )
            {
               pMenu->m_eSelectedFlag++;
            }*/
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
            /*if (pMenu->m_eChoice == ShowDetails) {
               return 0;
            }*/
            break;

         default:
            break;
         }
      }
   }

   return 1;
}
extern SDL_Surface *ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height);
void UpdateDetailsDisplay(struct ShowFlagDetails* pShowFlagDetails)
{
#ifdef _TINSPIRE
   if (!has_colors)
   {
      SDL_FillRect(pMenu->m_pScreen, NULL, SDL_MapRGB(pShowFlagDetails->m_pScreen->format, 255, 255, 255));
   }
#else
   SDL_FillRect(pShowFlagDetails->m_pScreen, NULL, SDL_MapRGB(pShowFlagDetails->m_pScreen->format, 255, 215, 139));
#endif

   SDL_Rect dst;
   dst.x = 10;
   dst.y = 10;
   dst.w = SCREEN_WIDTH/2;
   dst.h = SCREEN_HEIGHT/2;
   SDL_Surface* pFlagSurface = GetLoadedImage(pShowFlagDetails->m_pImageLoader, pShowFlagDetails->m_eFlag);

   SDL_Surface* pSmallerFlagSurface = ScaleSurface(pFlagSurface, SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

   SDL_BlitSurface(pSmallerFlagSurface, NULL, pShowFlagDetails->m_pScreen, &dst);
   SDL_FreeSurface(pSmallerFlagSurface);

   DrawText(pShowFlagDetails->m_pScreen, pShowFlagDetails->m_pFont, 15, 15, GetCountryName(pShowFlagDetails->m_pFlagInformation, pShowFlagDetails->m_eFlag), 0, 0, 0);

   char buffer[16];
   IntToA(buffer, sizeof(buffer), GetCountryAreaSqKM(pShowFlagDetails->m_pFlagInformation, pShowFlagDetails->m_eFlag));
   CommaSeparate(buffer);
   DrawText(pShowFlagDetails->m_pScreen, pShowFlagDetails->m_pFont, SCREEN_WIDTH / 2, 50, "Square KM:", 0, 0, 0);
   DrawText(pShowFlagDetails->m_pScreen, pShowFlagDetails->m_pFont, SCREEN_WIDTH / 2, 65, buffer, 0, 0, 0);

   IntToA(buffer, sizeof(buffer), GetCountryPopulation(pShowFlagDetails->m_pFlagInformation, pShowFlagDetails->m_eFlag));
   CommaSeparate(buffer);
   DrawText(pShowFlagDetails->m_pScreen, pShowFlagDetails->m_pFont, SCREEN_WIDTH / 2, 90, "Population:", 0, 0, 0);
   DrawText(pShowFlagDetails->m_pScreen, pShowFlagDetails->m_pFont, SCREEN_WIDTH / 2, 105, buffer, 0, 0, 0);

   SDL_UpdateRect(pShowFlagDetails->m_pScreen, 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
}

int ShowFlagDetailsLoop(struct ShowFlagDetails* pShowFlagDetails)
{
   if (PollDetailsEvents(pShowFlagDetails) == 0)
      return 0;

   UpdateDetailsDisplay(pShowFlagDetails);

   return 1;
}



