#pragma once
#include "MegunoLinkProtocol.h"

class Message : protected MegunoLinkProtocol
{
public:
  Message(const char *channelName = NULL);
  Message(const __FlashStringHelper *channelName);

  void Begin();
  void End();

  void Send(const char *Message);
  void Send(const __FlashStringHelper *Message);
  
  template<class TValue> void Send(const char *Label, TValue Value)
  {
    SendDataHeader(F("DATA"));
    Serial.print(Label);
    Serial.print(F(": "));
    Serial.print(Value);
    SendDataTail();
}

  template<class TValue> void Send(const __FlashStringHelper *Label, TValue Value)
  {
    SendDataHeader(F("DATA"));
    Serial.print(Label);
    Serial.print(F(": "));
    Serial.print(Value);
    SendDataTail();
  }

};

