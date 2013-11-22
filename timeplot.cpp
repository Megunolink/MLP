#include "timeplot.h"

timeplot::timeplot()
{

}

//Timeplot Plotting
void timeplot::Send(String channelName, String seriesName, float value, String plotProperties)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print(plotProperties);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void timeplot::Send(String channelName, String seriesName, double value, String plotProperties)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print(plotProperties);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void timeplot::Send(String channelName, String seriesName, unsigned long value, String plotProperties)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print(plotProperties);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void timeplot::Send(String channelName, String seriesName, int value, String plotProperties)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print(plotProperties);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void timeplot::Send(String channelName, String seriesName, byte value, String plotProperties)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|data|");
  Serial.print(seriesName);
  Serial.print(plotProperties);
  Serial.print("|T|");
  Serial.print(value, 3);
  Serial.println("}");
}

void timeplot::Title(String channelName, String title)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|set|title=");
  Serial.print(title);
  Serial.println("}");
}

void timeplot::Xlabel(String channelName, String xlabel)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|set|x-label=");
  Serial.print(xlabel);
  Serial.println("}");
}

void timeplot::Ylabel(String channelName, String ylabel)
{
  Serial.print("{TIMEPLOT:");
  Serial.print(channelName);
  Serial.print("|set|y-label=");
  Serial.print(ylabel);
  Serial.println("}");
}