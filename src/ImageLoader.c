#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#endif
#include "ImageLoader.h"

void CreateImageLoader(struct ImageLoader** ppImageLoader, int nNumImages)
{
   *ppImageLoader = malloc(sizeof(struct ImageLoader));
   struct ImageLoader* pImageLoader = (*ppImageLoader);

   pImageLoader->m_nNumImages = nNumImages;

   pImageLoader->m_ppSurfaces = malloc(sizeof(SDL_Surface*) * nNumImages);
   for (int i = 0; i < nNumImages; i++)
      (pImageLoader->m_ppSurfaces)[i] = NULL;
}

void FreeImageLoader(struct ImageLoader** ppImageLoader)
{
   struct ImageLoader* pImageLoader = *ppImageLoader;

   for (int i = 0; i < pImageLoader->m_nNumImages; i++)
   {
      if ((pImageLoader->m_ppSurfaces)[i] != NULL)
      {
         SDL_FreeSurface((pImageLoader->m_ppSurfaces)[i]);
         (pImageLoader->m_ppSurfaces)[i] = NULL;
      }
   }

   free(*ppImageLoader);
   *ppImageLoader = NULL;
}

void LoadFlagImage(struct ImageLoader* pImageLoader, struct FlagInformation* pFlagInformation, enum Flags flag)
{
   int nIndex = (int)flag;
   (pImageLoader->m_ppSurfaces)[nIndex] = 
#ifndef _TINSPIRE
      SDL_LoadBMP( GetPathForFlag(pFlagInformation, flag) );
#endif
}

SDL_Surface* GetLoadedImage(struct ImageLoader* pImageLoader, enum Flags flag)
{
   int nIndex = (int)flag;
   return (pImageLoader->m_ppSurfaces)[nIndex];
}
