#pragma once
#include <Arduino.h>

namespace InterfacePanel
{
  void SetText(const char * ChannelName, const char * ControlName, const char * Value);
  void SetProgress(const char * ChannelName, const char * ControlName, int nValue);
  void SetNumber(const char * ChannelName, const char * ControlName, int nValue);
  void SetCheck(const char * ChannelName, const char * ControlName, bool bChecked);

}