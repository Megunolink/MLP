#include "EspTicker.h"

#if defined(ARDUINO_ARCH_ESP32)

void EspTicker::once(float fSeconds, callback_function_t handler)
{
  m_SourceTicker.once<EspTicker*>(fSeconds, OnTick, this);
}

void EspTicker::OnTick(EspTicker* pTimer)
{
  if (pTimer != nullptr && pTimer->m_Handler != nullptr)
  {
    pTimer->m_Handler();
  }
}

void EspTicker::detach()
{
  m_SourceTicker.detach();
}
#endif
