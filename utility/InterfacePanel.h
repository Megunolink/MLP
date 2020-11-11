#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include "MegunoLinkProtocol.h"

class InterfacePanel : public MegunoLinkProtocol
{
public:
  InterfacePanel(const char *channelName = NULL, Print &rDestination = Serial);
  InterfacePanel(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  void SetGaugeLabel(const char *ControlName, int LabelNumber, const char *Value);
  void SetGaugeLabel(const __FlashStringHelper *ControlName, int LabelNumber, const char *Value);
  void SetGaugeLabel(const __FlashStringHelper *ControlName, int LabelNumber, const __FlashStringHelper *Value);

  void SetProgress(const char * ControlName, int nValue);
  void SetProgress(const __FlashStringHelper * ControlName, int nValue);

  template<class T>
  void SetText(const char *ControlName, T Value)
  {
    SendTextHeader(ControlName);
    m_rDestination.print(Value);
    SendDataTail();
  }

  template<class T>
  void SetText(const __FlashStringHelper *ControlName, T Value)
  {
    SendTextHeader(ControlName);
    m_rDestination.print(Value);
    SendDataTail();
  }

  void SetText(const __FlashStringHelper *ControlName, float Value, uint8_t DecimalPlaces);
  void SetText(const char *ControlName, float Value, uint8_t DecimalPlaces);

  template<class T>
  void SetNumber(const char *ControlName, T Value)
  {
    SendValueHeader(ControlName);
    m_rDestination.print(Value);
    SendDataTail();
  }

  template<class T>
  void SetNumber(const __FlashStringHelper *ControlName, T Value)
  {
    SendValueHeader(ControlName);
    m_rDestination.print(Value);
    SendDataTail();
  }

  void SetNumber(const char * ControlName, float fValue, int decimal = 3);
  void SetNumber(const __FlashStringHelper * ControlName, float fValue, int decimal = 3);

  void SetListIndex(const char * ControlName, int nIndex);
  void SetListIndex(const __FlashStringHelper * ControlName, int nIndex);
  void SetListValue(const char * ControlName, int nIndex);
  void SetListValue(const __FlashStringHelper * ControlName, int nIndex);
  void SetListName(const char * ControlName, const char *ValueName);
  void SetListName(const __FlashStringHelper * ControlName, const __FlashStringHelper *ValueName);

  void SetCheck(const char * ControlName, bool bChecked = true);
  void SetCheck(const __FlashStringHelper * ControlName, bool bChecked = true);

  void ShowControl(const char * ControlName);
  void HideControl(const char * ControlName);

  void ShowControl(const __FlashStringHelper * ControlName);
  void HideControl(const __FlashStringHelper * ControlName);

  void EnableControl(const char * ControlName);
  void DisableControl(const char * ControlName);

  void EnableControl(const __FlashStringHelper * ControlName);
  void DisableControl(const __FlashStringHelper * ControlName);

  void SetForeColor(const char *ControlName, const char *Color);
  void SetForeColor(const __FlashStringHelper *ControlName, const __FlashStringHelper *Color);

  void SetBackColor(const char *ControlName, const char *Color);
  void SetBackColor(const __FlashStringHelper *ControlName, const __FlashStringHelper *Color);

  void ClearCheck(const char * ControlName);
  void ClearCheck(const __FlashStringHelper * ControlName);

  void CallCommand(const char* CommandName);
  void CallCommand(const __FlashStringHelper* CommandName);

  void GetValue(const char* ControlName, const char* PropertyName);
  void GetValue(const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName);

  void SetReadOnly(const char *ControlName, bool ReadOnly);
  void SetReadOnly(const __FlashStringHelper *ControlName, bool ReadOnly);

  void SetMinimum(const char *ControlName, int Value);
  void SetMaximum(const char *ControlName, int Value);

  void SetMinimum(const __FlashStringHelper *ControlName, int Value);
  void SetMaximum(const __FlashStringHelper *ControlName, int Value);

  template<typename TControlName, typename TContent> void Speak(const TControlName ControlName, const TContent Content)
  {
#if 0
    static_assert(std::is_base_of(char*, TControlName)
      || std::is_base_of(__FlashStringHelper*, TControlName)
      || std::is_base_of(String, TControlName), "Control name should be a const char *, const __FlashStringHelper, or String");
#endif

    SendDataHeader(F("CALL"));
    m_rDestination.print(ControlName);
    m_rDestination.print('.');
    m_rDestination.print(F("Speak(\""));
    m_rDestination.print(Content);
    m_rDestination.println(F("\")}"));
  }

  template<typename TControlName> void StopSpeaking(const TControlName ControlName)
  {
#if 0
    static_assert(std::is_base_of(char*, TControlName)
      || std::is_base_of(__FlashStringHelper*, TControlName)
      || std::is_base_of(String, TControlName), "Control name should be a const char *, const __FlashStringHelper, or String");
#endif

    SendDataHeader(F("CALL"));
    m_rDestination.print(ControlName);
    m_rDestination.print('.');
    m_rDestination.println(F("Stop()}"));
  }

protected:
  void SendControlHeader(const char* ControlName, const char* PropertyName);
  void SendControlHeader(const char *ControlName, const __FlashStringHelper *PropertyName);
  void SendControlHeader(const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName);
  void SendControlHeader(const __FlashStringHelper *ControlName, const char*PropertyName);

  void SendGaugeControlHeader(const char *ControlName, int nLabelNumber);
  void SendGaugeControlHeader(const __FlashStringHelper *ControlName, int nLabelNumber);

  void SendValueHeader(const char *ControlName);
  void SendValueHeader(const __FlashStringHelper *ControlName);
  void SendTextHeader(const char *ControlName);
  void SendTextHeader(const __FlashStringHelper *ControlName);

};
