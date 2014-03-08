#pragma once
#include <Arduino.h>
#include "Plot.h"

class TimePlot : public Plot
{

public:
  TimePlot(const char *channelName = NULL);
  TimePlot(const __FlashStringHelper *channelName);

  template<class TYData> void SendData(const char * seriesName, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(F("T|"));
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const char * seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(F("T|"));
    Serial.print(yValue);
    SendDataTail();
  }

  void SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL);
  void SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle);

  template<class TYData> void SendData(const __FlashStringHelper * seriesName, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(F("T|"));
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const __FlashStringHelper * seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(F("T|"));
    Serial.print(yValue);
    SendDataTail();
  }

  void SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL);
  void SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle);
};