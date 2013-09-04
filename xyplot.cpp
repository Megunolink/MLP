#include "xyplot.h"

xyplot::xyplot()
{

}
//Timeplot Plotting
void xyplot::TimePlot(String channelName, String seriesName, float value)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void xyplot::TimePlot(String channelName, String seriesName, double value)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

