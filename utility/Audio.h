#pragma once
#define __PROG_TYPES_COMPAT__
#include "MegunoLinkProtocol.h"

class Audio : public MegunoLinkProtocol
{
public:
  Audio(Print& rDestination = Serial);

  template<typename TContent> void Speak(TContent Content)
  {
    SendDataHeader(F("SPK"));
    m_rDestination.print(Content);
    SendDataTail();
  }

  void Stop()
  {
    SendDataHeader(F("STP"));
    SendDataTail();
  }
};