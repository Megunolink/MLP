#include "TimePlot.h"

TimePlot::TimePlot( const char *channelName /*= NULL*/, Print &rDestination )
  : Plot(F("TIMEPLOT"), channelName, rDestination)
{

}

TimePlot::TimePlot( const __FlashStringHelper *channelName, Print &rDestination )
  : Plot(F("TIMEPLOT"), channelName, rDestination)
{

}

TimePlot::TimePlot(Print& rDestination)
  : Plot(F("TIMEPLOT"), (const char*) NULL, rDestination)
{
}


void TimePlot::Run(bool bEnable)
{
  SendDataHeader(F("RUN"));
  m_rDestination.print(bEnable ? '1' : '0');
  SendDataTail();
}

void TimePlot::SetXRange(float fTimespanHours)
{
	SendDataHeader(F("xrange"));
	m_rDestination.print("T|");
	m_rDestination.print(fTimespanHours,5);
	SendDataTail();
}

void TimePlot::Stop()
{
  Run(false);
}

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties/*=NULL*/)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(seriesProperties);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties/*=NULL*/)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(seriesProperties);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, int32_t nColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(nColor, Line, uLineWidth, Marker, ax);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SetCursorPositionToNow(const char* SeriesName)
{
  SendDataHeader(F("C-POSD"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(F("|T"));
  SendDataTail();
}

void TimePlot::SetCursorPositionToNow(const __FlashStringHelper* SeriesName)
{
  SendDataHeader(F("C-POSD"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(F("|T"));
  SendDataTail();
}

void TimePlot::SetCursorPosition(const char* SeriesName, tm& Time)
{
  SendDataHeader(F("C-POSD"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(F("|"));
  m_rDestination.print(1900 + Time.tm_year);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mon);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mday);
  m_rDestination.print(' ');
  m_rDestination.print(Time.tm_hour);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_min);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_sec);

  SendDataTail();
}

void TimePlot::SetCursorPosition(const __FlashStringHelper* SeriesName, tm& Time)
{
  SendDataHeader(F("C-POSD"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(F("|"));
  m_rDestination.print(1900 + Time.tm_year);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mon);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mday);
  m_rDestination.print(' ');
  m_rDestination.print(Time.tm_hour);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_min);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_sec);

  SendDataTail();
}

