#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include "Plot.h"

class XYPlot : public Plot
{

public:
  XYPlot(const char *channelName = NULL, Print &rDestination = Serial);
  XYPlot(const __FlashStringHelper *channelName, Print &rDestination = Serial);

  template<class TXData, class TYData> void SendData(const char * seriesName, TXData xValue, TYData yValue, const char * seriesProperties=NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const char * seriesName, TXData xValue, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TXData> void SendData(const char * seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData> void SendData(const char * seriesName, TXData xValue, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, TYData yValue, const char * seriesProperties=NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TXData, class TYData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TXData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties=NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<class TXData> void SendData(const __FlashStringHelper * seriesName, TXData xValue, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }
};
