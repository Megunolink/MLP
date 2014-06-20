#pragma once
#include "MegunoLinkProtocol.h"

class Message : protected MegunoLinkProtocol
{
public:
  Message(const char *channelName = NULL, Print &rDestination = Serial);
  Message(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  void Begin();
  void End();

  void Send(const char *Message);
  void Send(const __FlashStringHelper *Message);

  template<class TValue> void Send(TValue Value)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(Value);
    SendDataTail();
  }

  template<class TValue> void Send(const char *Label, TValue Value)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(Label);
    m_rDestination.print(F(": "));
    m_rDestination.print(Value);
    SendDataTail();
  }

  template<class TValue> void Send(const __FlashStringHelper *Label, TValue Value)
  {
    SendDataHeader(F("DATA"));
    m_rDestination.print(Label);
    m_rDestination.print(F(": "));
    m_rDestination.print(Value);
    SendDataTail();
  }

  void Clear();
};

