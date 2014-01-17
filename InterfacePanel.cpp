#include "InterfacePanel.h"

namespace InterfacePanel
{
  void SendHeader(const char * ChannelName, const char * ControlName, const __FlashStringHelper *pPropertyName)
  {
    Serial.print(F("{UI"));
    if (ChannelName != NULL && strlen(ChannelName) != 0)
    {
      Serial.print(':');
      Serial.print(ChannelName);
    }
    Serial.print(F("|SET|"));
    Serial.print(ControlName);
    Serial.print('.');
    Serial.print(pPropertyName);
    Serial.print('=');
  }

  void SendTail()
  {
    Serial.println('}');
  }

  void SetText(const char * ChannelName, const char * ControlName, const char * Value)
  {
    SendHeader(ChannelName, ControlName, F("Text"));
    Serial.print(Value);
    SendTail();
  }

  void SetProgress(const char * ChannelName, const char * ControlName, int nValue)
  {
    SetNumber(ChannelName, ControlName, nValue);
  }

  void SetNumber(const char * ChannelName, const char * ControlName, int nValue)
  {
    SendHeader(ChannelName, ControlName, F("Value"));
    Serial.print(nValue);
    SendTail();
  }

  void SetCheck(const char * ChannelName, const char * ControlName, bool bChecked)
  {
    SendHeader(ChannelName, ControlName, F("Checked"));
    Serial.print(bChecked ? F("True") : F("False"));
    SendTail();
  }

}