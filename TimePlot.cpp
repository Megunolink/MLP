#include "TimePlot.h"
#include "PlotHelpers.h"

namespace TimePlot
{

  void SetTitle(const char * channelName, const char * title)
  {
    MLPPlotHelpers::SetParameter(F("TIMEPLOT"), channelName, title, F("title"));
  }

  void SetXlabel(const char * channelName, const char * xlabel)
  {
    MLPPlotHelpers::SetParameter(F("TIMEPLOT"), channelName, xlabel, F("x-label"));
  }

  void SetYlabel(const char * channelName, const char * ylabel)
  {
    MLPPlotHelpers::SetParameter(F("TIMEPLOT"), channelName, ylabel, F("y-label"));
  }

  void SendFloatData(const char * channelName, const char * seriesName, float value, int nDecimalPlaces, const char * seriesProperties)
  {
    MLPPlotHelpers::SendDataHeader(F("TIMEPLOT"), channelName, seriesName, seriesProperties);
    Serial.print(F("T|"));
    Serial.print(value, nDecimalPlaces);
    MLPPlotHelpers::SendDataTail();
  }

}