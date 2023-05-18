
/* *********************************************************************************
*  Example program to trigger a scheduled report in MegunoLink. 
* 
*  More Information
*    - https://www.megunolink.com/documentation/scheduled-reporting/
*    - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/
*  ********************************************************************************* */

#include "MegunoLink.h"
#include "ArduinoTimer.h"

Report ReportGenerator;
::ArduinoTimer ReportTimer;

TimePlot ADCValuePlot;
::ArduinoTimer PlotTimer;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if (PlotTimer.TimePassed_Milliseconds(500))
  {
    ADCValuePlot.SendData("A0", analogRead(0));
  }

  if (ReportTimer.TimePassed_Seconds(10))
  {
    ReportGenerator.GenerateNow();
  }
}
