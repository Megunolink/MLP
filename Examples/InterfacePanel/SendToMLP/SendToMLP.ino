/* **********************************************************************************************
*  Example program to set values on a MegunoLink Pro User Interface
*  Panel. Visit http://www.megunolink.com/updating-interface-panel-controls-from-the-arduino/
*  for more information. 
*  
*  This program sends out commands to set the value of a progress bar named 'Progress', a 
*  numeric up/down control named 'Current' and a text box named 'Status' periodically. The 
*  interface panel is included in the MegunoLink Pro project in the example folder. 
*  ********************************************************************************************** */

#include "MegunoLink.h" // Helpful functions for communicating with MegunoLink Pro. 

// Millis value when the data was last sent. 
long LastSent;

// Progress value
int Progress; 

void setup()
{
  Serial.begin(9600);

  LastSent = millis();
  Progress = 0;
}

void loop()
{
  if ((millis() - LastSent) > 1000)
  {
    LastSent = millis();

    InterfacePanel::SetProgress("Test", "Progress", Progress);
    InterfacePanel::SetNumber("Test", "Current", Progress);
    
    if (Progress == 0)
      InterfacePanel::SetText("Test", "Status", "Start");
    else if (Progress == 8)
      InterfacePanel::SetText("Test", "Status", "Nearly there");
    else if (Progress == 9)
      InterfacePanel::SetText("Test", "Status", "End");
    else
      InterfacePanel::SetText("Test", "Status", "Working");

    Progress = (Progress + 1) % 10;

    XYPlot::SendData("Test", "Fish", Progress, Progress);
    TimePlot::SendData("Test", "Fish", Progress);
  }

}