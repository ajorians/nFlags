#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#include "SDL/SDL.h"
#endif
#include "FlagInformation.h"

void CreateFlagInformation(struct FlagInformation** ppFlagInformation)
{
   *ppFlagInformation = malloc(sizeof(struct FlagInformation));
   struct FlagInformation* pFlagInformation = (*ppFlagInformation);

   //Initialize stuff here
}

void FreeFlagInformation(struct FlagInformation** ppFlagInformation)
{
   struct FlagInformation* pFlagInformation = (*ppFlagInformation);

   free(*ppFlagInformation);
   *ppFlagInformation = NULL;
}

int GetNumberOfFlags(struct FlagInformation* pFlagInformation)
{
   return (int)FLAGS_MAX;
}

const char* GetCountryName(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   switch (flag)
   {
   default:
   case Brazil:
      return "Brazil";
   case UnitedStates:
      return "United States of America";
   case Turkey:
      return "Turkey";
   case Israel:
      return "Israel";
   case Germany:
      return "Germany";
   }
}

#ifndef _TINSPIRE
const char* GetPathForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   switch (flag)
   {
   default:
   case Brazil:
      return "Images\\ad.bmp";
   case UnitedStates:
      return "Images\\ae.bmp";
   case Turkey:
      return "Images\\af.bmp";
   case Israel:
      return "Images\\ag.bmp";
   case Germany:
      return "Images\\ag.bmp";
   }
}
#endif
