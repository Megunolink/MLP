#include "InterfacePanel.h"

InterfacePanel::InterfacePanel(const char *channelName /*= NULL*/, Print &rDestination)
  : MegunoLinkProtocol(F("UI"), channelName, rDestination)
{

}

InterfacePanel::InterfacePanel(const __FlashStringHelper *channelName, Print &rDestination)
  : MegunoLinkProtocol(F("UI"), channelName, rDestination)
{

}

void InterfacePanel::SetText(const char * ControlName, const char * Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetText(const char * ControlName, int Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetText(const char * ControlName, long Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetText(const char * ControlName, unsigned long Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetText(const char * ControlName, float Value)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetText(const char * ControlName, float Value, int DecimalPlaces)
{
  SendControlHeader(ControlName, F("Text"));
  m_rDestination.print(Value, DecimalPlaces);
  SendDataTail();
}

void InterfacePanel::SetProgress(const char * ControlName, int nValue)
{
  SetNumber(ControlName, (int32_t) nValue);
}

void InterfacePanel::SetNumber(const char * ControlName, int16_t nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const char * ControlName, int32_t nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const char * ControlName, uint32_t nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const char * ControlName, float fValue, int nDecimal)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(fValue, nDecimal);
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
  SetNumber(ControlName, (int32_t) nValue);
}

void InterfacePanel::SetListValue(const __FlashStringHelper * ControlName, int nValue)
{
  SetNumber(ControlName, (int32_t) nValue);
}

void InterfacePanel::SetListName(const char * ControlName, const char *ValueName)
{
  SendControlHeader(ControlName, F("SelectedName"));
  m_rDestination.print(ValueName);
  SendDataTail();
}

void InterfacePanel::SetListName(const __FlashStringHelper * ControlName, const __FlashStringHelper *ValueName)
{
  SendControlHeader(ControlName, F("SelectedName"));
  m_rDestination.print(ValueName);
  SendDataTail();
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
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print((int32_t)nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const __FlashStringHelper * ControlName, int16_t nValue)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(nValue);
  SendDataTail();
}

void InterfacePanel::SetNumber(const __FlashStringHelper * ControlName, float fValue, int nDecimal)
{
  SendControlHeader(ControlName, F("Value"));
  m_rDestination.print(fValue, nDecimal);
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

void InterfacePanel::CallCommand(const char* CommandName)
{
  SendDataHeader(F("CMD"));
  m_rDestination.print(CommandName);
  SendDataTail();
}

void InterfacePanel::CallCommand(const __FlashStringHelper* CommandName)
{
  SendDataHeader(F("CMD"));
  m_rDestination.print(CommandName);
  SendDataTail();
}

void InterfacePanel::GetValue(const char* ControlName, const char* PropertyName)
{
  SendDataHeader(F("GET"));
  m_rDestination.print(ControlName);
  m_rDestination.print('.');
  m_rDestination.print(PropertyName);
  SendDataTail();
}

void InterfacePanel::GetValue(const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName)
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

void InterfacePanel::ShowControl(const char * ControlName)
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::ShowControl(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::HideControl(const char * ControlName)
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::HideControl(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Visible"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::EnableControl(const char * ControlName)
{
  SendControlHeader(ControlName, F("Enabled"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::EnableControl(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Enabled"));
  m_rDestination.print(F("True"));
  SendDataTail();
}

void InterfacePanel::DisableControl(const char * ControlName)
{
  SendControlHeader(ControlName, F("Enabled"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::DisableControl(const __FlashStringHelper * ControlName)
{
  SendControlHeader(ControlName, F("Enabled"));
  m_rDestination.print(F("False"));
  SendDataTail();
}

void InterfacePanel::SetForeColor(const char *ControlName, const char *Color)
{
  SendControlHeader(ControlName, F("ForeColor"));
  m_rDestination.print(Color);
  SendDataTail();
}

void InterfacePanel::SetForeColor(const __FlashStringHelper *ControlName, const __FlashStringHelper *Color)
{
  SendControlHeader(ControlName, F("ForeColor"));
  m_rDestination.print(Color);
  SendDataTail();
}

void InterfacePanel::SetBackColor(const char *ControlName, const char *Color)
{
  SendControlHeader(ControlName, F("BackColor"));
  m_rDestination.print(Color);
  SendDataTail();
}

void InterfacePanel::SetBackColor(const __FlashStringHelper *ControlName, const __FlashStringHelper *Color)
{
  SendControlHeader(ControlName, F("BackColor"));
  m_rDestination.print(Color);
  SendDataTail();
}

void InterfacePanel::SetReadOnly(const char *ControlName, bool ReadOnly)
{
  SendControlHeader(ControlName, F("ReadOnly"));
  m_rDestination.print(ReadOnly ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::SetReadOnly(const __FlashStringHelper *ControlName, bool ReadOnly)
{
  SendControlHeader(ControlName, F("ReadOnly"));
  m_rDestination.print(ReadOnly ? F("True") : F("False"));
  SendDataTail();
}

void InterfacePanel::SetMinimum(const char *ControlName, int Value)
{
  SendControlHeader(ControlName, F("Minimum"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetMaximum(const char *ControlName, int Value)
{
  SendControlHeader(ControlName, F("Maximum"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetMinimum(const __FlashStringHelper *ControlName, int Value)
{
  SendControlHeader(ControlName, F("Minimum"));
  m_rDestination.print(Value);
  SendDataTail();
}

void InterfacePanel::SetMaximum(const __FlashStringHelper *ControlName, int Value)
{
  SendControlHeader(ControlName, F("Maximum"));
  m_rDestination.print(Value);
  SendDataTail();
}

