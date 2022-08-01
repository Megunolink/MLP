#include "TimePlot.h"

TimePlot::TimePlot( const char *channelName, Print &rDestination )
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

void TimePlot::SendTime(const tm& Time)
{
  m_rDestination.print(1900 + Time.tm_year);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mon + 1);
  m_rDestination.print('-');
  m_rDestination.print(Time.tm_mday);
  m_rDestination.print(' ');
  m_rDestination.print(Time.tm_hour);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_min);
  m_rDestination.print(':');
  m_rDestination.print(Time.tm_sec);
}

void TimePlot::SendTimeWithSeparator(const tm& Time)
{
  SendTime(Time);
  m_rDestination.print('|');
}

void TimePlot::SendTimeWithSeparator(const time_t& Time)
{
  // Arduino's print method doesn't overload printing for 64 bit integers. 
  // 32 bit value of time_t is good to 2038, so just cast for now. 
  m_rDestination.print((long)Time);
  m_rDestination.print('|');
}

void TimePlot::SendProperties(Colors Color, RGBColor CustomColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  if (bUseIntColor)
  {
    SendSeriesProperties(CustomColor, Line, uLineWidth, Marker, ax);
  }
  else
  {
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
  }
}

void TimePlot::SendTime(const tm* pTime, const time_t* pEpoch)
{
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
}

void TimePlot::SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, const char* seriesProperties)
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
  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();
}

void TimePlot::SendFloatDataCore(const tm* pTime, const time_t* pEpoch, float yValue, int nDecimalPlaces, Colors Color, RGBColor CustomColor, bool bUseIntColor, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  if (bUseIntColor)
  {
    SendSeriesProperties(CustomColor, Line, uLineWidth, Marker, ax);
  }
  else
  {
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
  }

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

  m_rDestination.print(yValue, nDecimalPlaces);
  SendDataTail();

}
