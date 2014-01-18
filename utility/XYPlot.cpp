#include "xyplot.h"


XYPlot::XYPlot( const char *channelName /*= NULL*/ )
  : Plot(F("XYPLOT"), channelName)
{

}

XYPlot::XYPlot( const __FlashStringHelper *channelName )
  : Plot(F("XYPLOT"), channelName)
{

}
