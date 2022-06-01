#include "MLPMsgBuffer.h"

MLPMsgDestination::MLPMsgDestination(char* pchStart, int nLength)
  : m_pchStart(pchStart)
  , m_nBufferSize(nLength)
{
  begin();
}

void MLPMsgDestination::begin()
{
  m_pchNext = m_pchStart;
  *m_pchNext = '\0';
}

size_t MLPMsgDestination::write(uint8_t uValue)
{
  char* pchEnd = m_pchStart + m_nBufferSize;
  if ((m_pchNext + 1) < pchEnd)
  {
    *m_pchNext++ = uValue;
    *m_pchNext = '\0';

    bool bFull = m_pchNext == pchEnd - 1;
    if (uValue == '\n' || bFull)
    {
      flush();
      begin();
    }
    return 1;
  }

  return 0;
}

void MLPMsgDestination::EndTransmission()
{
  if (length() > 0)
  {
    flush();
    begin();
  }
}
