#pragma once
#include <Arduino.h>
#include <time.h>
#include "Plot.h"
#include "PlotFormat.h"

class TimePlot : public Plot
{

public:
  TimePlot(Print& rDestination = Serial);
  TimePlot(const char *channelName, Print &rDestination = Serial);
  TimePlot(const __FlashStringHelper* channelName, Print& rDestination = Serial);

  void Run(bool bEnable);
  void Stop();
  void SetXRange(float fTimespanHours);

  template<typename TSeriesName>
  void SetCursorPositionToNow(TSeriesName SeriesName)
  {
    SendSeriesHeader(F("C-POSD"), SeriesName, true);
    m_rDestination.print('T');
    SendDataTail();
  }

  template<typename TSeriesName>
  void SetCursorPosition(TSeriesName SeriesName, const tm& Time)
  {
    SendSeriesHeader(F("C-POSD"), SeriesName, true);
    SendTime(Time);
    SendDataTail();
  }

  void SetCursorPosition(const char* SeriesName, double dPosition, uint8_t nPrecision = 5) 
  {
    Plot::SetCursorPosition(SeriesName, dPosition, nPrecision);
  }

  void SetCursorPosition(const __FlashStringHelper* SeriesName, double dPosition, uint8_t nPrecision = 5)
  {
    Plot::SetCursorPosition(SeriesName, dPosition, nPrecision);
  }

#if defined(USE_FLEXIBLE_ARGUMENTS)
  template<class TSeriesName, class TYData> void SendData(const TSeriesName* seriesName, TYData yValue)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print('|');
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TSeriesName, class TYData, typename... TProperties> void SendData(const TSeriesName* seriesName, TYData yValue, TProperties... Properties)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print(':');
    SendSeriesProperties(Properties...);
    m_rDestination.print('|');
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TSeriesName, class TYData> void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print('|');
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TSeriesName, class TYData, typename... TProperties> void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue, TProperties... Properties)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print(':');
    SendSeriesProperties(Properties...);
    m_rDestination.print('|');
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TSeriesName> void SendFloatData(const TSeriesName* seriesName, double yValue, int Precision)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print('|');
    SendTimeSeparator();
    m_rDestination.print(yValue, Precision);
    SendDataTail();
  }

  template<class TSeriesName, typename... TProperties> void SendFloatData(const TSeriesName* seriesName, double yValue, int Precision, TProperties... Properties)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print(':');
    SendSeriesProperties(Properties...);
    m_rDestination.print('|');
    SendTimeSeparator();
    m_rDestination.print(yValue, Precision);
    SendDataTail();
  }

  template<class TSeriesName> void SendFloatData(const TSeriesName* seriesName, const tm& Time, double yValue, int Precision)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print('|');
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue, Precision);
    SendDataTail();
  }

  template<class TSeriesName, typename... TProperties> void SendFloatData(const TSeriesName* seriesName, const tm& Time, double yValue, int Precision, TProperties... Properties)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    m_rDestination.print(':');
    SendSeriesProperties(Properties...);
    m_rDestination.print('|');
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue, Precision);
    SendDataTail();
  }


#else
  template<typename TSeries, typename TYData>
  void SendData(TSeries seriesName, TYData yValue, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(nullptr, nullptr, yValue, seriesProperties);
  }

  template<typename TSeries, typename TYData>
  void SendData(TSeries seriesName, TYData yValue, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(nullptr, nullptr, yValue, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<typename TSeries, typename TYData>
  void SendData(TSeries seriesName, TYData yValue, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(nullptr, nullptr, yValue, Red, Color, true, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName, class TYData> 
  void SendData(const TSeriesName* seriesName, const tm &Time, TYData yValue, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(&Time, nullptr, yValue, seriesProperties);
  }

  template<class TSeriesName, class TYData> 
  void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(&Time, nullptr, yValue, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName, class TYData> 
  void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(&Time, nullptr, yValue, Red, Color, true, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName, class TYData>
  void SendData(TSeriesName seriesName, const time_t& Time, TYData yValue, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(NULL, &Time, yValue, seriesProperties);
  }

  template<class TSeriesName, class TYData>
  void SendData(TSeriesName seriesName, const time_t& Time, TYData yValue, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(NULL, &Time, yValue, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName, class TYData>
  void SendData(TSeriesName seriesName, const time_t& Time, TYData yValue, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendDataCore(NULL, &Time, yValue, Colors::Black, Color, true, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(nullptr, nullptr, yValue, nDecimalPlaces, seriesProperties);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(NULL, NULL, yValue, nDecimalPlaces, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, float yValue, int nDecimalPlaces, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(NULL, NULL, yValue, nDecimalPlaces, Colors::Black, Color, true, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const tm& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(&Time, nullptr, yValue, nDecimalPlaces, seriesProperties);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const tm& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(&Time, NULL, yValue, nDecimalPlaces, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const tm& Time, float yValue, int nDecimalPlaces, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(&Time, NULL, yValue, nDecimalPlaces, Colors::Black, Color, true, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const time_t& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(nullptr, &Time,  yValue, nDecimalPlaces, seriesProperties);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const time_t& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(NULL, &Time,  yValue, nDecimalPlaces, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TSeriesName>
  void SendFloatData(TSeriesName seriesName, const time_t& Time, float yValue, int nDecimalPlaces, const RGBColor& Color, LineStyle Line = MissingLineStyle, uint8_t uLineWidth = 0, MarkerStyle Marker = MissingMarkerStyle, Axis ax = MissingAxis)
  {
    SendSeriesHeader_Data(seriesName, false);
    SendFloatDataCore(NULL, &Time, yValue, nDecimalPlaces, Red, Color, true, Line, uLineWidth, Marker, ax);
  }

#endif

private:

  enum EFlags
  {
    UseIntegerColor = 0x01,
    UseTypedColor = 0x00,

    UseSeriesProperties = 0x02,
    UseIndividualProperties = 0x00,
  };

  void SendTime(const tm& Time);
  void SendTimeWithSeparator(const tm& Time);
  void SendTimeWithSeparator(const time_t& Time);

  template<class TYData> 
  void SendDataCore(const tm* pTime, const time_t *pEpoch, TYData YValue, const char* seriesProperties)
  {
    SendSeriesProperties(seriesProperties);
    SendTime(pTime, pEpoch);

    m_rDestination.print(YValue);

    SendDataTail();
  }

  template<class TYData> 
  void SendDataCore(const tm* pTime, const time_t* pEpoch, TYData YValue, Colors Color, RGBColor CustomColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
  {
    SendProperties(Color, CustomColor, bUseIntColor, Line, uLineWidth, Marker, ax);
    SendTime(pTime, pEpoch);

    m_rDestination.print(YValue);

    SendDataTail();
  }

  void SendProperties(Colors Color, RGBColor CustomColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax);

  void SendTime(const tm* pTime, const time_t* pEpoch);

  void SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, const char* seriesProperties);
  void SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, Colors Color, RGBColor CustomColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax);
};