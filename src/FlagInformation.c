#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#include "SDL/SDL.h"
#endif
#include "FlagInformation.h"

#ifdef _TINSPIRE
#define C(e, n, km, pop, img) { e, n, km, pop}
#else
#define C(e, n, km, pop, img) { e, n, km, pop, img}
#endif

struct FlagInfo
{
   enum Flags eFlag;
   const char* pstrCountryName;
   int nSqKMs;
   int nPopulation;
#ifndef _TINSPIRE
   const char* pstrImagePath;
#endif
} g_FlagInfo[] = {
   C( Brazil,         "Brazil",                     8514880, 201032714, "Images\\br.bmp" ),
   C( UnitedStates,   "United States of America",   9629090, 317706000, "Images\\us.bmp" ),
   C( Turkey,         "Turkey",                     783562,  76667864,  "Images\\tr.bmp" ),
   C( Germany,        "Germany",                    357022,  80619000,  "Images\\gn.bmp" ),
   C( Israel,         "Israel",                     22145,   8146300,   "Images\\il.bmp" )
};

#undef C

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
   return sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]);
}

const char* GetCountryName(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrCountryName;
   return "";
}

int GetCountryAreaSqKM(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nSqKMs;
   return -1;
}

int GetCountryPopulation(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nPopulation;
   return -1;
}

#ifndef _TINSPIRE
const char* GetPathForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrImagePath;
   return "";
}
#endif
