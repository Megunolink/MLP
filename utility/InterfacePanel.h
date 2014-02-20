#pragma once
#include <Arduino.h>
#include "MegunoLinkProtocol.h"

class InterfacePanel : public MegunoLinkProtocol
{
public:
  InterfacePanel(const char *channelName = NULL);
  InterfacePanel(const __FlashStringHelper *channelName);

  void SetText(const char * ControlName, const char * Value);
  void SetText(const __FlashStringHelper * ControlName, const char * Value);
  void SetText(const __FlashStringHelper * ControlName, const __FlashStringHelper * Value);

  void SetProgress(const char * ControlName, int nValue);
  void SetProgress(const __FlashStringHelper * ControlName, int nValue);

  void SetNumber(const char * ControlName, int nValue);
  void SetNumber(const __FlashStringHelper * ControlName, int nValue);

  void SetListIndex(const char * ControlName, int nIndex);
  void SetListIndex(const __FlashStringHelper * ControlName, int nIndex);
  void SetListValue(const char * ControlName, int nIndex);
  void SetListValue(const __FlashStringHelper * ControlName, int nIndex);

  void SetCheck(const char * ControlName, bool bChecked = true);
  void SetCheck(const __FlashStringHelper * ControlName, bool bChecked = true);

  void ClearCheck(const char * ControlName);
  void ClearCheck(const __FlashStringHelper * ControlName);

  void CallCommand(const char* CommandName);
  void CallCommand(const __FlashStringHelper* CommandName);

  void GetValue(const char* ControlName, const char* PropertyName);
  void GetValue(const __FlashStringHelper* ControlName, const __FlashStringHelper* PropertyName);

protected:
  void SendControlHeader(const char *ControlName, const __FlashStringHelper *PropertyName);
  void SendControlHeader(const __FlashStringHelper *ControlName, const __FlashStringHelper *PropertyName);
};