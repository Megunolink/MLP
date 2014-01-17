#pragma once
#include <Arduino.h>
#include "PlotHelpers.h"

namespace XYPlot
{

  void SetTitle(const char * channelName, const char * title);
  void SetXlabel(const char * channelName, const char * xlabel);
  void SetYlabel(const char * channelName, const char * ylabel);

  template<class TXData, class TYData> void SendData(const char * channelName, const char * seriesName, TXData xValue, TYData yValue, const char * seriesProperties=NULL)
  {
    MLPPlotHelpers::SendDataHeader(F("XYPLOT"), channelName, seriesName, seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue);
    MLPPlotHelpers::SendDataTail();
  }

  template<class TXData> void SendData(const char * channelName, const char * seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL)
  {
    MLPPlotHelpers::SendDataHeader(F("XYPLOT"), channelName, seriesName, seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue, nDecimalPlaces);
    MLPPlotHelpers::SendDataTail();
  }
};
