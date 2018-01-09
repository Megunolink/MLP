#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include "MegunoLinkProtocol.h"

class InterfacePanel : public MegunoLinkProtocol
{
public:
  InterfacePanel(const char *channelName = NULL, Print &rDestination = Serial);
  InterfacePanel(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  void SetText(const char * ControlName, const char * Value);
  void SetText(const char * ControlName, int Value);  
  void SetText(const char * ControlName, long Value);  
  void SetText(const char * ControlName, unsigned long Value);
  void SetText(const char * ControlName, float Value);
  void SetText(const char * ControlName, float Value, int DecimalPlaces);
  void SetText(const __FlashStringHelper * ControlName, const char * Value);
  void SetText(const __FlashStringHelper * ControlName, const __FlashStringHelper * Value);

  void SetProgress(const char * ControlName, int nValue);
  void SetProgress(const __FlashStringHelper * ControlName, int nValue);

  void SetNumber(const char * ControlName, int16_t nValue);
  void SetNumber(const __FlashStringHelper * ControlName, int16_t nValue);
  
  void SetNumber(const char * ControlName, int32_t nValue);
  void SetNumber(const __FlashStringHelper * ControlName, int32_t nValue);
  
  void SetNumber(const char * ControlName, uint32_t nValue);
  void SetNumber(const __FlashStringHelper * ControlName, uint32_t nValue);
  
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

protected:
  void SendControlHeader(const char *ControlName, const __FlashStringHelper *PropertyName);
  void SendControlHeader(const __FlashStringHelper *ControlName, const __FlashStringHelper *PropertyName);
};
