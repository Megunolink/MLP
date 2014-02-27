#include "ArduinoTimer.h"

ArduinoTimer::ArduinoTimer()
{
  m_uStartTime = 0;
}

bool ArduinoTimer::TimePassed_Milliseconds(uint32_t uPeriod, bool bAtuoReset)
{
  uint32_t uNow;

  uNow = millis();
  if (uNow - m_uStartTime >= uPeriod)
  {
    if (bAtuoReset)
      m_uStartTime = uNow;
    return true;
  }

  return false;
}

bool ArduinoTimer::TimePassed_Seconds(uint16_t uPeriod, bool bAtuoReset)
{
  uint32_t uNow;

  uNow = millis();
  if ((uNow - m_uStartTime)/1000 >= uPeriod)
  {
    if (bAtuoReset)
      m_uStartTime = uNow;
    return true;
  }

  return false;
}