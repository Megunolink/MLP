#include "InterfacePanel.h"

InterfacePanel::InterfacePanel( const char *channelName /*= NULL*/ )
  : MegunoLinkProtocol(F("UI"), channelName)
{

}

InterfacePanel::InterfacePanel(const __FlashStringHelper *channelName)
  : MegunoLinkProtocol(F("UI"), channelName)
{

}

void InterfacePanel::SetText(const char * ControlName, const char * Value)
{
  SendControlHeader(ControlName, F("Text"));
  Serial.print(Value);
  SendDataTail();
}

void InterfacePanel::SetProgress(const char * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
}

void InterfacePanel::SetNumber(const char * ControlName, int nValue)
{
  SendControlHeader(ControlName, F("Value"));
  Serial.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetCheck(const char * ControlName, bool bChecked)
{
  SendControlHeader(ControlName, F("Checked"));
  Serial.print(bChecked ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::ClearCheck(const char * ControlName)
{
  SendControlHeader(ControlName, F("Checked"));
  Serial.print(F("False"));
  SendDataTail();
}

void InterfacePanel::SetText(const __FlashStringHelper * ControlName, const char * Value)
{
  SendControlHeader(ControlName, F("Text"));
  Serial.print(Value);
  SendDataTail();
}

void InterfacePanel::SetProgress(const __FlashStringHelper * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
}

void InterfacePanel::SetNumber(const __FlashStringHelper * ControlName, int nValue)
{
  SendControlHeader(ControlName, F("Value"));
  Serial.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetCheck(const __FlashStringHelper * ControlName, bool bChecked)
{
  SendControlHeader(ControlName, F("Checked"));
  Serial.print(bChecked ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::ClearCheck(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Checked"));
  Serial.print(F("False"));
  SendDataTail();
}

void InterfacePanel::SetText(const __FlashStringHelper * ControlName, const __FlashStringHelper * Value)
{
  SendControlHeader(ControlName, F("Text"));
  Serial.print(Value);
  SendDataTail();
}

void InterfacePanel::SendControlHeader(const char *ControlName, const __FlashStringHelper *PropertyName)
{
  SendDataHeader(F("SET"));
  Serial.print(ControlName);
  Serial.print('.');
  Serial.print(PropertyName);
  Serial.print('=');
}

void InterfacePanel::SendControlHeader(const __FlashStringHelper *ControlName, const __FlashStringHelper *PropertyName)
{
  SendDataHeader(F("SET"));
  Serial.print(ControlName);
  Serial.print('.');
  Serial.print(PropertyName);
  Serial.print('=');
}
