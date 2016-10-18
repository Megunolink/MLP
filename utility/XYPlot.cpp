#include "XYPlot.h"


XYPlot::XYPlot( const char *channelName /*= NULL*/, Print &rDestination )
  : Plot(F("XYPLOT"), channelName, rDestination)
{

}

XYPlot::XYPlot( const __FlashStringHelper *channelName, Print &rDestination )
  : Plot(F("XYPLOT"), channelName, rDestination)
{

}
