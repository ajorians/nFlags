#ifdef _TINSPIRE
#include <os.h>
#else
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#endif
#include "Config.h"
#include "Replacements.h"
#include "FlagEnum.h"

void CreateConfig(struct Config** ppConfig)
{
   *ppConfig = malloc(sizeof(struct Config));

   struct Config* pConfig = (*ppConfig);
   pConfig->m_nLastCountry = (int)TheUnitedStates;

#ifndef _WIN32
   pConfig->m_Archive = NULL;
   ArchiveCreate(&pConfig->m_Archive);

   OpenArchiveFile(pConfig->m_Archive, "FlagsSettings.tns");
   int nSettings = GetNumberArchives(pConfig->m_Archive, "Settings");
   char strName[MAX_NAME_LENGTH];
   for(int i=0; i<nSettings; i++) {
      StringCopy(strName, MAX_NAME_LENGTH, GetName(pConfig->m_Archive, "Settings", i));

      char buffer[16];

      StringCopy(buffer, sizeof(buffer), "LastCountry");
      if( strcmp(strName, buffer) == 0 ) {
         pConfig->m_nLastCountry = atoi( GetValue(pConfig->m_Archive, "Settings", i) );
      }
   }
#endif
}

void FreeConfig(struct Config** ppConfig)
{
   char buffer[16];
   char bufferName[16];
   struct Config* pConfig = *ppConfig;
/*#ifndef _WIN32
   ArchiveSetBatchMode(pConfig->m_Archive, ARCHIVE_ENABLE_BATCH);

   sprintf(buffer, "%d", pConfig->m_nLastCountry);
   strcpy(bufferName, "LastCountry");
   UpdateArchiveEntry(pConfig->m_Archive, "Settings", bufferName, buffer, NULL);

   ArchiveSetBatchMode(pConfig->m_Archive, ARCHIVE_DISABLE_BATCH);

   ArchiveFree(&pConfig->m_Archive);
#endif*/

   free(*ppConfig);
   *ppConfig = NULL;
}
void SetLastLevel(struct Config* pConfig, int nLastLevelNum)
{
   pConfig->m_nLastCountry = nLastLevelNum;
}

int GetLastLevel(struct Config* pConfig)
{
   return pConfig->m_nLastCountry;
}
