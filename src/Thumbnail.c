#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#endif
#include "Thumbnail.h"
#include "Font.h"
#include "SDL/SDL_gfxPrimitives.h"

Uint16 get_pixel16(SDL_Surface *surface, int x, int y)
{
   int bpp = surface->format->BytesPerPixel;
   Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp; //Get the requested pixel 
   return *(Uint16 *)p;
}

void put_pixel16(SDL_Surface *surface, int x, int y, Uint16 pixel)
{
   int bpp = surface->format->BytesPerPixel;
   Uint8 *p = (Uint8 *)surface->pixels + y * surface->pitch + x * bpp;
   *(Uint16 *)p = pixel;
}

SDL_Surface *ScaleSurface(SDL_Surface *Surface, Uint16 Width, Uint16 Height)
{
   if (!Surface || !Width || !Height)
      return 0;

   SDL_Surface *_ret = SDL_CreateRGBSurface(Surface->flags, Width, Height, Surface->format->BitsPerPixel,
      Surface->format->Rmask, Surface->format->Gmask, Surface->format->Bmask, Surface->format->Amask);

   double    _stretch_factor_x = ((double)(Width) / (double)(Surface->w)),
      _stretch_factor_y = ((double)(Height) / (double)(Surface->h));

   for (Sint32 y = 0; y < Surface->h; y++)
      for (Sint32 x = 0; x < Surface->w; x++)
         for (Sint32 o_y = 0; o_y < _stretch_factor_y; ++o_y)
            for (Sint32 o_x = 0; o_x < _stretch_factor_x; ++o_x)
               put_pixel16(_ret, (Sint32)(_stretch_factor_x * x) + o_x,
               (Sint32)(_stretch_factor_y * y) + o_y, get_pixel16(Surface, x, y));

   return _ret;
}

static Font *g_pFontThumbnail = NULL;
static int g_nThumbnailCount = 0;

void CreateThumbnail(struct Thumbnail** ppThumbnail, struct FlagInformation* pFlagInformation, struct ImageLoader* pImageLoader, enum Flags eFlag)
{
   *ppThumbnail = malloc(sizeof(struct Thumbnail));
   struct Thumbnail* pThumbnail = (*ppThumbnail);

   pThumbnail->m_pFlagInformation = pFlagInformation;
   pThumbnail->m_pImageLoader = pImageLoader;
   pThumbnail->m_eFlag = eFlag;
   pThumbnail->m_pThumbSurface = NULL;

   if (g_nThumbnailCount == 0)
   {
      g_pFontThumbnail = LoadFont("arial.ttf", NSDL_FONT_THIN, 255/*R*/, 0/*G*/, 0/*B*/, 10);
   }
   g_nThumbnailCount++;
}

void FreeThumbnail(struct Thumbnail** ppThumbnail)
{
   struct Thumbnail* pThumbnail = *ppThumbnail;

   if (pThumbnail->m_pThumbSurface)
   {
      SDL_FreeSurface(pThumbnail->m_pThumbSurface);
      pThumbnail->m_pThumbSurface = NULL;
   }

   pThumbnail->m_pFlagInformation = NULL;//Does not own
   pThumbnail->m_pImageLoader = NULL;//Does not own

   g_nThumbnailCount--;
   if (g_nThumbnailCount == 0)
   {
      FreeFont(g_pFontThumbnail);
      g_pFontThumbnail = NULL;
   }

   free(*ppThumbnail);
   *ppThumbnail = NULL;
}

void DrawThumbnail(struct Thumbnail* pThumbnail, SDL_Surface* pScreen, int selected, int x, int y, int maxWidth, int maxHeight)
{
   if (pThumbnail->m_pThumbSurface == NULL)
   {
      SDL_Surface* pSurface = GetLoadedImage(pThumbnail->m_pImageLoader, pThumbnail->m_eFlag);
      if (pSurface != NULL)
      {
         int nImgWidth = pSurface->w;
         int nImgHeight = pSurface->h;

         if (nImgWidth > maxWidth)
         {
            double d = (double)maxWidth / nImgWidth;
            nImgWidth *= d;
            nImgHeight *= d;
         }
         if (nImgHeight > maxHeight)
         {
            double d = (double)maxHeight / nImgHeight;
            nImgWidth *= d;
            nImgHeight *= d;
         }

         SDL_Surface* pScaledSurface = ScaleSurface(pSurface, (Uint16)maxWidth, (Uint16)maxHeight);
         pSurface = NULL;//Does not own

         pThumbnail->m_pThumbSurface = pScaledSurface;
      }
   }

   if (pThumbnail->m_pThumbSurface != NULL)
   {
      SDL_Rect dst;
      dst.w = pThumbnail->m_pThumbSurface->w;
      dst.h = pThumbnail->m_pThumbSurface->h;
      dst.x = (Sint16)x + ((maxWidth - dst.w) / 2);
      dst.y = (Sint16)y + ((maxHeight - dst.h) / 2);

      SDL_BlitSurface(pThumbnail->m_pThumbSurface, NULL, pScreen, &dst);
   }

   if (selected == 1)
   {
      DrawText(pScreen, g_pFontThumbnail, x, y + maxHeight, GetCountryName(pThumbnail->m_pFlagInformation, pThumbnail->m_eFlag), 0, 0, 0);
   }
}
