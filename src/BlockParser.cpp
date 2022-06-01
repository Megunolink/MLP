#include "BlockParser.h"

bool BlockParser::FindCommand(char *&rpchBuffer, int &rnLength)
{
  if (rnLength <= 2 || *rpchBuffer != '!')
  {
    return false;
  }
  ++rpchBuffer;
  --rnLength;

  char *pchEnd = rpchBuffer;
  int nLength = 0;
  while (nLength < rnLength && *pchEnd != '\r' && *pchEnd != '\n')
  {
    ++pchEnd;
    ++nLength;
  }

  rnLength = nLength;
  rpchBuffer[rnLength] = '\0';
  return rnLength > 0;
}