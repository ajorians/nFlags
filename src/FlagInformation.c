#ifdef _TINSPIRE
#include <os.h>
#include <libndls.h>
#else
#include "SDL/SDL.h"
#endif
#include "FlagInformation.h"

//#include "Images/af.h"
#include "Images/af.h"
#include "Images/al.h"
#include "Images/dz.h"
#include "Images/ad.h"
#include "Images/ao.h"
#include "Images/ag.h"
#include "Images/ar.h"
#include "Images/am.h"
#include "Images/au.h"
#include "Images/at.h"
#include "Images/az.h"
#include "Images/br.h"
#include "Images/us.h"
#include "Images/tr.h"
#include "Images/gn.h"
#include "Images/il.h"



#ifndef _WIN32
#define C(e, n, km, pop, img, path) { e, n, km, pop, img, sizeof(img)}
#define P(s) "../../src/" s
#else
#define P(s) s
#define C(e, n, km, pop, img, path) { e, n, km, pop, path}
#endif

struct FlagInfo
{
   enum Flags eFlag;
   const char* pstrCountryName;
   int nSqKMs;
   int nPopulation;
#ifdef _WIN32
   const char* pstrImagePath;
#else
   unsigned char* pImg;
   int nImgSize;
#endif
} g_FlagInfo[] = {

   //C( Afghanistan,       "Afghanistan",                652090,  25500100,  af, P("Images/af.bmp") )
   C( Afghanistan,       "Afghanistan",                652090,  25500100,  af, P("Images/af.bmp") ),
   C( Albania,           "Albania",                    28748,   2821977,   al, P("Images/al.bmp") ),
   C( Algeria,           "Algeria",                    2381740, 38700000,  dz, P("Images/dz.bmp") ),
   C( Andorra,           "Andorra",                    468,     76098,     ad, P("Images/ad.bmp") ),
   C( Angola,            "Angola",                     1246700, 20609294,  ao, P("Images/ao.bmp") ),
   C( AntiguaAndBarbuda, "Antigua and Barbuda",        442,     86295,     ag, P("Images/ag.bmp") ),
   C( Argentina,         "Argentina",                  2780400, 44660096,  ar, P("Images/ar.bmp") ),
   C( Armenia,           "Armenia",                    29800,   3017400,   am, P("Images/am.bmp") ),
   C( Australia,         "Australia",                  7741220, 23414552,  au, P("Images/au.bmp") ),
   C( Austria,           "Austria",                    83858,   8504850,   at, P("Images/at.bmp") ),
   C( Azerbaijan,        "Azerbaijan",                 86600,   9477100,   az, P("Images/az.bmp") ),
   C( Brazil,            "Brazil",                     8514880, 201032714, br, P("Images/br.bmp") ),
   C( UnitedStates,      "United States of America",   9629090, 317706000, us, P("Images/us.bmp") ),
   C( Turkey,            "Turkey",                     783562,  76667864,  tr, P("Images/tr.bmp") ),
   C( Germany,           "Germany",                    357022,  80619000,  gn, P("Images/gn.bmp") ),
   C( Israel,            "Israel",                     22145,   8146300,   il, P("Images/il.bmp") )
};

#undef C
#undef P

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

#ifdef _WIN32
const char* GetPathForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pstrImagePath;
   return "";
}
#else
unsigned char* GetImgDataForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].pImg;
   return NULL;
}

int GetImgDataSizeForFlag(struct FlagInformation* pFlagInformation, enum Flags flag)
{
   for (int i = 0; i < sizeof(g_FlagInfo) / sizeof(g_FlagInfo[0]); i++)
      if (g_FlagInfo[i].eFlag == flag)
         return g_FlagInfo[i].nImgSize;
   return -1;
}
#endif
