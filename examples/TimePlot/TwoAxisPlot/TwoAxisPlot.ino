/* **********************************************************************************************
   Example program to plot sine wave data on MegunoLink's Time Plot visualiser
   Visit http://www.megunolink.com/documentation/plotting/
   for more information.
*  ********************************************************************************************** */
#include "MegunoLink.h"
#include "ArduinoTimer.h"

// For more information on installing the MegunoLink Arduino library check out our documentation
// http://www.megunolink.com/documentation/arduino-integration/

// You can download the MegunoLink Interface (.mlx) that goes with this example here
// http://www.megunolink.com/examples/arduino/TimePlot/TwoAxisPlot/TwoAxisPlot.mlpz




// Uncomment if you would like to use plotting channels
// TimePlot MyPlot("Waveforms"); //"Waveforms" = the taget plotting channel (remember to select this in megunolink)

TimePlot MyPlot; //no channel selected

ArduinoTimer PlotPropertiesTimer;
ArduinoTimer PlotSendTimer;

void setup()
{
  Serial.begin(115200);
  SendPlotProperties();
}


void loop()
{
  double dY, dY2;
  float seconds;
  float frequency = 0.5; //Hz
  float phase = 3.141 / 2;

  //Send plotting data every 100mS
  if (PlotSendTimer.TimePassed_Milliseconds(100))
  {
    seconds = (float)millis() / 1000;

    dY = sin(2 * 3.141 * frequency * seconds);
    dY2 = cos(2 * 3.141 * frequency * seconds + phase);

    //Send Data To MegunoLink Pro
    //"Sinewave" = series name, Plot::Blue = line colour, 2 = line width, Plot::Square = marker style
    MyPlot.SendData(F("Sinewave"), dY, Plot::Blue, Plot::Solid, 2, Plot::Square, Plot::LeftAxis); // Sinewave = series name, dY = data to plot
    MyPlot.SendData(F("Cosinewave"), dY2, Plot::Red, Plot::Solid, 2, Plot::Square, Plot::RightAxis); // By wrapping strings in F("") we can save ram by storing strings in program memory

    // Colours include
    // Red, Green, Blue, Yellow, Black, Magenta, Cyan, White

    // Markers include
    // Square, Diamond, Triangle, Circle, Cross, Plus, Star, DownwardTriangle, NoMarker

    // Line style
    // Solid, Dashed, Dotted, DashDot, DashDotDot

    // Axis options
    // LeftAxis, RightAxis, DefaultAxis

  }

  //Send plotting style message every 10000mS
  if (PlotPropertiesTimer.TimePassed_Milliseconds(10000))
  {
    SendPlotProperties();
  }
}


void SendPlotProperties()
{
  MyPlot.SetTitle("Sine and Cosine Function Waveforms");
  MyPlot.SetXLabel("Time");
  MyPlot.SetYLabel("Amplitude");
  MyPlot.SetY2Label("Amplitude 2");
  MyPlot.SetYRange(-1.5, 5);
  MyPlot.SetY2Range(-5, 1.5);
  MyPlot.SetY2Visible();
}