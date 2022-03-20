#include "MLPMsgBuffer.h"

MLPMsgDestination::MLPMsgDestination()
{
  begin();
}

void MLPMsgDestination::begin()
{
  m_pchNext = m_achBuffer;
  *m_pchNext = '\0';
}

size_t MLPMsgDestination::write(uint8_t uValue)
{
  if ((m_pchNext + 1) < (m_achBuffer + sizeof(m_achBuffer)))
  {
    *m_pchNext++ = uValue;
    *m_pchNext = '\0';

    bool bFull = m_pchNext == m_achBuffer + sizeof(m_achBuffer) - 1;
    if (uValue == '\n' || bFull)
    {
      flush();
    }
    return 1;
  }

  return 0;
}
