#include "FixedStringBuffer.h"

FixedStringPrint::FixedStringPrint(char* pchBuffer, size_t szBuffer)
{
  m_pchBuffer = pchBuffer;
  m_szBuffer = szBuffer;
  begin();
}

void FixedStringPrint::begin()
{
  m_pchNext = m_pchBuffer;
  if (m_szBuffer > 0)
  {
    *m_pchNext = '\0';
  }
  m_bBufferFlow = false; 
}

size_t FixedStringPrint::write(uint8_t uValue)
{
  if ((m_pchNext + 1) < (m_pchBuffer + m_szBuffer))
  {
    *m_pchNext++ = uValue;
    *m_pchNext = '\0';
    return 1;
  }

  m_bBufferFlow = true; 
  return 0;
}