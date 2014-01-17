#pragma once
#include <Arduino.h>

namespace MLPPlotHelpers
{
  void SetParameter(const __FlashStringHelper *pPlotType, const char * channelName, const char * Value, const __FlashStringHelper *pfstrParameter);
  void SendDataHeader(const __FlashStringHelper *pPlotType, const char * ChannelName, const char * SeriesName, const char * SeriesProperties = NULL);
  void SendDataTail();


}
