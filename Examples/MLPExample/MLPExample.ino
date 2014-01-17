#include "timeplot.h"
#include "table.h"
#include "xyplot.h"


float test = 65.987;
void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  int DataValue = analogRead(0);

  // put your main code here, to run repeatedly: 
  TimePlot::Send("ChannelName","SeriesName",test,"r-2s2");
  TimePlot::Title("ChannelName","hello");
  TimePlot::Xlabel("ChannelName","test");
  Table::Send("DataValue",DataValue,"this is a reading from analog channel 0");
  XYPlot::Send("ChannelName","SeriesName",millis(),56.589,"b-2s2");
  delay(1000);
}

