#include "timeplot.h"
#include "table.h"

timeplot TimePlot;
table Table;

void setup() 
{
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() 
{
  int DataValue = analogRead(0);
  
  // put your main code here, to run repeatedly: 
  TimePlot.Send("ChannelName","SeriesName",DataValue);
  Table.Send("DataValue",DataValue,"this is a reading from analog channel 0");
  delay(1000);
}
