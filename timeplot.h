#pragma once
#include <Arduino.h>
#include "PlotHelpers.h"

namespace TimePlot
{

  void SetTitle(const char * channelName, const char * title);
  void SetXlabel(const char * channelName, const char * xlabel);
  void SetYlabel(const char * channelName, const char * ylabel);

  template<class T> void SendData(const char * channelName, const char * seriesName, T yValue, const char * seriesProperties = NULL)
  {
    MLPPlotHelpers::SendDataHeader(F("TIMEPLOT"), channelName, seriesName, seriesProperties);
    Serial.print(F("T|"));
    Serial.print(yValue);
    MLPPlotHelpers::SendDataTail();
  }

  
  void SendFloatData(const char * channelName, const char * seriesName, float value, int nDecimalPlaces, const char * seriesProperties = NULL);
};
