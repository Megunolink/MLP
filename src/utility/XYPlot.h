#pragma once
#include <Arduino.h>
#include "Plot.h"
#include "PlotFormat.h"

class XYPlot : public Plot
{

public:
  XYPlot(Print& rDestination = Serial);
  XYPlot(const char *channelName, Print &rDestination = Serial);
  XYPlot(const __FlashStringHelper *channelName, Print &rDestination = Serial);
  void SetXRange(float fXLimMin, float fXlimMax);

  template<typename TSeriesName, class TXData, class TYData>
  void SendData(TSeriesName* seriesName, TXData xValue, TYData yValue, const char * seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(seriesProperties);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<typename TSeriesName, class TXData, class TYData>
  void SendData(TSeriesName seriesName, unsigned NumberOfValues, TXData *xValues, TYData *yValues, const char * seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(seriesProperties);
    SendData<TXData>(xValues, yValues, NumberOfValues, 2);
  }

  template<typename TSeriesName, class TXData, class TYData>
  void SendData(TSeriesName seriesName, TXData xValue, TYData yValue, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<typename TSeriesName, typename TXData, typename TYData> 
  void SendData(TSeriesName seriesName, TXData xValue, TYData yValue, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, TXData xValue, float yValue, int nDecimalPlaces, const char * seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(seriesProperties);
    SendData<TXData>(&xValue, &yValue, 1, nDecimalPlaces);
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, unsigned NumberOfValues, TXData *xValues, float *yValues, int nDecimalPlaces, const char * seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(seriesProperties);
    SendData<TXData>(xValues, yValues, NumberOfValues, nDecimalPlaces);
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, TXData xValue, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, TXData xValue, float yValue, int nDecimalPlaces, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, TXData xValue, double yValue, int nDecimalPlaces, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(seriesProperties);
    SendData<TXData>(&xValue, &yValue, 1, nDecimalPlaces);
  }

  template<typename TSeriesName, typename TXData> 
  void SendData(TSeriesName seriesName, TXData xValue, double yValue, int nDecimalPlaces, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    m_rDestination.print(xValue);
    m_rDestination.print('|');
    m_rDestination.print(yValue, nDecimalPlaces);
    SendDataTail();
  }

private:
  void SendData(float *xValues, float *yValues, unsigned NumberOfValues, int nDecimalPlaces, const char * seriesProperties = NULL);

  template<class TXData, class TYData> void SendData(TXData *xValues, TYData *yValues, unsigned NumberOfValues, int nDecimalPlaces)
  {
    while (NumberOfValues--)
    {
      m_rDestination.print(*xValues++);
      m_rDestination.print('|');
      m_rDestination.print(*yValues++, nDecimalPlaces);
      if (NumberOfValues != 0)
      {
        m_rDestination.print('|');
      }
    }
    SendDataTail();
  }
};
