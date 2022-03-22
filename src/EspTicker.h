/* ******************************************************************
*  A wrapper around the ESP32 timer implementation to support 
*  function bindings. 
*  ****************************************************************** */
#pragma once

#if defined(ARDUINO_ARCH_ESP8266)
#include "Ticker.h"

class EspTicker : public Ticker
{
  // That's it. Nothing special needed for the 8266 ticker. 
};

#elif defined(ARDUINO_ARCH_ESP32)

#include "Ticker.h"
#include <functional>


class EspTicker
{
public:

  typedef std::function<void(void)> callback_function_t;

  void once(float fSeconds, callback_function_t handler);
  void detach();
private:
  Ticker m_SourceTicker;
  callback_function_t m_Handler = nullptr;

  static void OnTick(EspTicker* pTimer);

};



#endif