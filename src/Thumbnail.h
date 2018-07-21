#ifndef THUMBNAIL_H
#define THUMBNAIL_H

#ifdef _TINSPIRE
#include <os.h>
#endif
#include "SDL/SDL.h"
#include "ImageLoader.h"
#include "FlagInformation.h"
#include "FlagEnum.h"

struct Thumbnail
{
   SDL_Surface* m_pThumbSurface;
   enum Flags m_eFlag;
   struct FlagInformation* m_pFlagInformation;//Does not own
   struct ImageLoader* m_pImageLoader;//Does not own
};

void CreateThumbnail(struct Thumbnail** ppThumbnail, struct FlagInformation* pFlagInformation, struct ImageLoader* pImageLoader, enum Flags eFlag);
void FreeThumbnail(struct Thumbnail** ppThumbnail);
void DrawThumbnail(struct Thumbnail* pThumbnail, SDL_Surface* pScreen, int selected, int x, int y, int maxWidth, int maxHeight);

#endif
