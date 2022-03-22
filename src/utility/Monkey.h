#pragma once
#include "MegunoLinkProtocol.h"

class Monkey : public MegunoLinkProtocol
{
public:
  Monkey(Print& rDestination = Serial);
  Monkey(const char *channelName, Print &rDestination = Serial);
  Monkey(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  void ClearTriggers();

  template<class TValue> void ClearTrigger(TValue Name)
  {
    SendDataHeader(F("CLR"));
    m_rDestination.print(Name);
    SendDataTail();
  }

  template<class TValue> void SetTrigger(TValue Name)
  {
    SendDataHeader(F("TRG"));
    m_rDestination.print(Name);
    SendDataTail();
  }
};

