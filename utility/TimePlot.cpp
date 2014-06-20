#include "TimePlot.h"

TimePlot::TimePlot( const char *channelName /*= NULL*/, Print &rDestination )
  : Plot(F("TIMEPLOT"), channelName, rDestination)
{

}

TimePlot::TimePlot( const __FlashStringHelper *channelName, Print &rDestination )
  : Plot(F("TIMEPLOT"), channelName, rDestination)
{

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

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker);
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

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker)
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker);
  m_rDestination.print(F("T|"));
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}