#include "InterfacePanel.h"

InterfacePanel::InterfacePanel( const char *channelName /*= NULL*/, Print &rDestination  )
  : MegunoLinkProtocol(F("UI"), channelName, rDestination)
{

}

InterfacePanel::InterfacePanel(const __FlashStringHelper *channelName, Print &rDestination )
  : MegunoLinkProtocol(F("UI"), channelName, rDestination)
{

}

void InterfacePanel::SetText(const char * ControlName, const char * Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetProgress(const char * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
}

void InterfacePanel::SetNumber(const char * ControlName, int nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}
void InterfacePanel::SetNumber(const char * ControlName, float fValue, int nDecimal)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(fValue,nDecimal);
  SendDataTail();
}

void InterfacePanel::SetListIndex(const char * ControlName, int nIndex)
{
  SendControlHeader(ControlName, F("SelectedIndex"));
  m_rDestination.print(nIndex);
  SendDataTail();
}

void InterfacePanel::SetListIndex(const __FlashStringHelper * ControlName, int nIndex)
{
  SendControlHeader(ControlName, F("SelectedIndex"));
  m_rDestination.print(nIndex);
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
  m_rDestination.print(bChecked ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::ClearCheck(const char * ControlName)
{
  SendControlHeader(ControlName, F("Checked"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::SetText(const __FlashStringHelper * ControlName, const char * Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetProgress(const __FlashStringHelper * ControlName, int nValue)
{
  SetNumber(ControlName, nValue);
}

void InterfacePanel::SetNumber(const __FlashStringHelper * ControlName, int nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const __FlashStringHelper * ControlName, float fValue, int nDecimal)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(fValue,nDecimal);
  SendDataTail();
}

void InterfacePanel::SetCheck(const __FlashStringHelper * ControlName, bool bChecked)
{
  SendControlHeader(ControlName, F("Checked"));
  m_rDestination.print(bChecked ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::ClearCheck(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Checked"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::SetText(const __FlashStringHelper * ControlName, const __FlashStringHelper * Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::CallCommand( const char* CommandName )
{
  SendDataHeader(F("CMD"));
  m_rDestination.print(CommandName);
  SendDataTail();
}

void InterfacePanel::CallCommand( const __FlashStringHelper* CommandName )
{
  SendDataHeader(F("CMD"));
  m_rDestination.print(CommandName);
  SendDataTail();
}

void InterfacePanel::GetValue( const char* ControlName, const char* PropertyName )
{
  SendDataHeader(F("GET"));
  m_rDestination.print(ControlName);
  m_rDestination.print('.');
  m_rDestination.print(PropertyName);
  SendDataTail();
}

void InterfacePanel::GetValue( const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName )
{
  SendDataHeader(F("GET"));
  m_rDestination.print(ControlName);
  m_rDestination.print('.');
  m_rDestination.print(PropertyName);
  SendDataTail();
}

void InterfacePanel::SendControlHeader(const char *ControlName, const __FlashStringHelper *PropertyName)
{
  SendDataHeader(F("SET"));
  m_rDestination.print(ControlName);
  m_rDestination.print('.');
  m_rDestination.print(PropertyName);
  m_rDestination.print('=');
}

void InterfacePanel::SendControlHeader(const __FlashStringHelper *ControlName, const __FlashStringHelper *PropertyName)
{
  SendDataHeader(F("SET"));
  m_rDestination.print(ControlName);
  m_rDestination.print('.');
  m_rDestination.print(PropertyName);
  m_rDestination.print('=');
}

void InterfacePanel::ShowControl( const char * ControlName )
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::ShowControl( const __FlashStringHelper * ControlName )
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::HideControl( const char * ControlName )
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::HideControl( const __FlashStringHelper * ControlName )
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

