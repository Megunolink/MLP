#include "xyplot.h"
#include "PlotHelpers.h"

namespace XYPlot
{
 
  void SetTitle(const char * channelName, const char * title)
  {
    MLPPlotHelpers::SetParameter(F("XYPLOT"), channelName, title, F("title"));
  }

  void SetXlabel(const char * channelName, const char * xlabel)
  {
    MLPPlotHelpers::SetParameter(F("XYPLOT"), channelName, xlabel, F("x-label"));
  }

  void SetYlabel(const char * channelName, const char * ylabel)
  {
    MLPPlotHelpers::SetParameter(F("XYPLOT"), channelName, ylabel, F("y-label"));
  }
}