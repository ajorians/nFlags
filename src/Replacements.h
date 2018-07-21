#ifndef REPLACEMENTS_H
#define REPLACEMENTS_H

#ifndef _TINSPIRE
#define SCREEN_WIDTH	(320)
#define SCREEN_HEIGHT	(240)
#endif

#define SCREEN_BIT_DEPTH        (16)

int min(int a, int b);
int max(int a, int b);

void IntToA(char* pstrBuffer, int bufferSize, int n);

void CommaSeparate(char* pstrBuffer);

void StringCopy(char* pstrOutput, int bufferSize, char* pstrInput);

void StringAppend(char* pstrBuffer, int nSize, char* pstrAddition);

void StringFmt(char* pstrBuffer, int nSize, char* pstrFormat, ...);

#endif
