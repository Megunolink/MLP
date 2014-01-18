#include "TimePlot.h"

TimePlot::TimePlot( const char *channelName /*= NULL*/ )
  : Plot(F("TIMEPLOT"), channelName)
{

}

TimePlot::TimePlot( const __FlashStringHelper *channelName )
  : Plot(F("TIMEPLOT"), channelName)
{

}

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties/*=NULL*/)
{
  SendDataHeader(F("DATA"));
  Serial.print(seriesName);
  SendSeriesProperties(seriesProperties);
  Serial.print(F("T|"));
  Serial.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const char * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker)
{
  SendDataHeader(F("DATA"));
  Serial.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker);
  Serial.print(F("T|"));
  Serial.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, const char * seriesProperties/*=NULL*/)
{
  SendDataHeader(F("DATA"));
  Serial.print(seriesName);
  SendSeriesProperties(seriesProperties);
  Serial.print(F("T|"));
  Serial.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatData(const __FlashStringHelper * seriesName, float yValue, int nDecimalPlaces, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker)
{
  SendDataHeader(F("DATA"));
  Serial.print(seriesName);
  SendSeriesProperties(Color, Line, uLineWidth, Marker);
  Serial.print(F("T|"));
  Serial.print(yValue, nDecimalPlaces);
  SendDataTail();
}