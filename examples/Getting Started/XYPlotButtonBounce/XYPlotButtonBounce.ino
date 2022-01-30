/* **********************************************************************************************
*  Example program to record button bounce and plot the waveform on MegunoLink's XY visualiser. 
*  Find the MegunoLink project (XY plot button bounce.mlpz), that goes with this example, in the same folder
*  as this Arduino code file.
* 
*  For more information:
*     Getting started with plotting (uses time-plot, which is similar to xy-plot):
*       https://www.megunolink.com/documentation/getting-started/plotting-data/
*     XY plot visualizer reference:
*       https://www.megunolink.com/documentation/plotting/xy-plot/
*     Installing the MegunoLink Arduino library:
*       https://www.megunolink.com/documentation/getting-started/arduino-integration/
*     Sending data to multiple plots:
*       https://www.megunolink.com/documentation/plotting/sending-data-to-multiple-plots/
*  ********************************************************************************************** */

#include "MegunoLink.h"

const int InputPin = 7; // Pin that switch is connected to

void setup() 
{
  Serial.begin(57600);
  Serial.println(F("Button Bounce Tester"));

  pinMode(InputPin, INPUT_PULLUP);
}

void loop() 
{
  // Trigger data capture when the switch is closed
  int ButtonState = digitalRead(InputPin);
  if (ButtonState == 0)
  {
    // To accurately capture the bounce, measurements are stored in this RAM
    // buffer then sent to the plot. This approach avoids delays caused by
    // sending serial data. 
    const int NumberOfMeasurements = 200;
    long MeasurementTime[NumberOfMeasurements]; // microseconds
    int Measurement[NumberOfMeasurements];
    
    // Capture bounce
    MeasurementTime[0] = micros();
    Measurement[0] = ButtonState;
    for(int i = 1; i<NumberOfMeasurements; ++i)
    {
      MeasurementTime[i] = micros();
      Measurement[i] = digitalRead(InputPin);
    }

    // Send data to plot.
    XYPlot Plot; // see: https://www.megunolink.com/documentation/plotting/xy-plot-library-reference/
    Plot.Clear();
    for(int i=0; i< NumberOfMeasurements; ++i)
    {
      long TimeSinceStart = MeasurementTime[i] - MeasurementTime[0];
      Plot.SendData("Button", TimeSinceStart, Measurement[i]);
    }

    // Wait until the button is released
    while (digitalRead(InputPin) == 0)
    {
      // still pressed
    }
    delay(100); // debounce release. 
  }
}
