#pragma once
#include <Arduino.h>
#include "Plot.h"

class XYPlot : public Plot
{

public:
  XYPlot(const char *channelName = NULL);
  XYPlot(const __FlashStringHelper *channelName);

  template<class TXData, class TYData> void SendData(const char * seriesName, TXData xValue, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const char * seriesName, TXData xValue, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TXData> void SendData(const char * seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData> void SendData(const char * seriesName, TXData xValue, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, TYData yValue, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue);
    SendDataTail();
  }

  template<class TXData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(seriesProperties);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendDataHeader(F("DATA"));
    Serial.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    Serial.print(xValue);
    Serial.print('|');
    Serial.print(yValue, nDecimalPlaces);
    SendDataTail();
  }
};
