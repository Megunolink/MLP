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

void InterfacePanel::SetListIndex(const char * ControlName, int nIndex)
{
  SendControlHeader(ControlName, F("SelectedIndex"));
  Serial.print(nIndex);
  SendDataTail();
}

void InterfacePanel::SetListIndex(const __FlashStringHelper * ControlName, int nIndex)
{
  SendControlHeader(ControlName, F("SelectedIndex"));
  Serial.print(nIndex);
  SendDataTail();
}

void InterfacePanel::SetListValue(const char * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
}

void InterfacePanel::SetListValue(const __FlashStringHelper * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
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

void InterfacePanel::CallCommand( const char* CommandName )
{
  SendDataHeader(F("CMD"));
  Serial.print(CommandName);
  SendDataTail();
}

void InterfacePanel::CallCommand( const __FlashStringHelper* CommandName )
{
  SendDataHeader(F("CMD"));
  Serial.print(CommandName);
  SendDataTail();
}

void InterfacePanel::GetValue( const char* ControlName, const char* PropertyName )
{
  SendDataHeader(F("GET"));
  Serial.print(ControlName);
  Serial.print('.');
  Serial.print(PropertyName);
  SendDataTail();
}

void InterfacePanel::GetValue( const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName )
{
  SendDataHeader(F("GET"));
  Serial.print(ControlName);
  Serial.print('.');
  Serial.print(PropertyName);
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

