#ifndef IMAGELOADER_H
#define IMAGELOADER_H

#ifdef _TINSPIRE
#include <os.h>
#endif
#include "SDL/SDL.h"
#include "FlagEnum.h"
#include "FlagInformation.h"

struct ImageLoader
{
   int m_nNumImages;
   SDL_Surface** m_ppSurfaces;
};

void CreateImageLoader(struct ImageLoader** ppImageLoader, int nNumImages);
void FreeImageLoader(struct ImageLoader** ppImageLoader);
void LoadFlagImage(struct ImageLoader* pImageLoader, struct FlagInformation* pFlagInformation, enum Flags flag);
SDL_Surface* GetLoadedImage(struct ImageLoader* pImageLoader, enum Flags flag);

#endif
