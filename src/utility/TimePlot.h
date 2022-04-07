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

  void SetCursorPositionToNow(const char* SeriesName);
  void SetCursorPositionToNow(const __FlashStringHelper* SeriesName);

  void SetCursorPosition(const char* SeriesName, const tm &Time);
  void SetCursorPosition(const __FlashStringHelper* SeriesName, const tm& Time);

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
  template<class TYData> void SendData(const char* seriesName, TYData yValue, const char* seriesProperties = NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const char* seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const char* seriesName, TYData yValue, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const __FlashStringHelper* seriesName, TYData yValue, const char* seriesProperties = NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const __FlashStringHelper* seriesName, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const __FlashStringHelper* seriesName, TYData yValue, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
    SendTimeSeparator();
    m_rDestination.print(yValue);
    SendDataTail();
  }


  template<class TSeriesName, class TYData> void SendData(const TSeriesName* seriesName, const tm &Time, TYData yValue, const char* seriesProperties = NULL)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(seriesProperties);
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue);
    SendDataTail();
  }


  template<class TSeriesName, class TYData> void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TSeriesName, class TYData> void SendData(const TSeriesName* seriesName, const tm& Time, TYData yValue, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeader_Data();
    m_rDestination.print(seriesName);
    SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
    SendTimeWithSeparator(Time);
    m_rDestination.print(yValue);
    SendDataTail();
  }

  template<class TYData> void SendData(const char* seriesName, const time_t& Time, TYData yValue, const char* seriesProperties = NULL)
  {
    SendHeaderCore(seriesName);
    SendDataCore(NULL, &Time, yValue, seriesProperties);
  }

  template<class TYData> void SendData(const __FlashStringHelper* seriesName, const time_t& Time, TYData yValue, const char* seriesProperties = NULL)
  {
    SendHeaderCore(seriesName);
    SendDataCore(NULL, &Time, yValue, seriesProperties);
  }

  template<class TYData> void SendData(const char* seriesName, const time_t& Time, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeaderCore(seriesName);
    SendDataCore(NULL, &Time, yValue, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TYData> void SendData(const __FlashStringHelper* seriesName, const time_t& Time, TYData yValue, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeaderCore(seriesName);
    SendDataCore(NULL, &Time, yValue, Color, 0, false, Line, uLineWidth, Marker, ax);
  }

  template<class TYData> void SendData(const char* seriesName, const time_t& Time, TYData yValue, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis)
  {
    SendHeaderCore(seriesName);
    SendDataCore(NULL, &Time, yValue, Colors::Black, nColor, true, Line, uLineWidth, Marker, ax);
  }

  void SendFloatData(const char* seriesName, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const char* seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const char* seriesName, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);

  void SendFloatData(const __FlashStringHelper* seriesName, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const __FlashStringHelper* seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const __FlashStringHelper* seriesName, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);


  void SendFloatData(const char* seriesName, const tm& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const char* seriesName, const tm& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const char* seriesName, const tm& Time, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);

  void SendFloatData(const __FlashStringHelper* seriesName, const tm& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const __FlashStringHelper* seriesName, const tm& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const __FlashStringHelper* seriesName, const tm& Time, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  
  void SendFloatData(const char* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const char* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const char* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);

  void SendFloatData(const __FlashStringHelper* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, const char* seriesProperties = NULL);
  void SendFloatData(const __FlashStringHelper* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
  void SendFloatData(const __FlashStringHelper* seriesName, const time_t& Time, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line = Solid, uint8_t uLineWidth = 1, MarkerStyle Marker = Circle, Axis ax = DefaultAxis);
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

  template<class TSeriesName> void SendHeaderCore(TSeriesName SeriesName)
  {
    SendHeader_Data();
    m_rDestination.print(SeriesName);
  }


  template<class TYData> void SendDataCore(const tm* pTime, const time_t *pEpoch, TYData YValue, const char* seriesProperties)
  {
    SendSeriesProperties(seriesProperties);
    if (pTime != NULL)
    {
      SendTimeWithSeparator(*pTime);
    }
    else if (pEpoch != NULL)
    {
      SendTimeWithSeparator(*pEpoch);
    }
    else
    {
      SendTimeSeparator();
    }
    m_rDestination.print(YValue);
    SendDataTail();

  }

  template<class TYData> void SendDataCore(const tm* pTime, const time_t* pEpoch, TYData YValue, Colors Color, int32_t nColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
  {
    if (bUseIntColor)
    {
      SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
    }
    else
    {
      SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    }

    if (pTime != NULL)
    {
      SendTimeWithSeparator(*pTime);
    }
    else
    {
      SendTimeSeparator();
    }

    m_rDestination.print(YValue);
    SendDataTail();
  }


  void SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, const char* seriesProperties);
  void SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, Colors Color, int32_t nColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax);
};