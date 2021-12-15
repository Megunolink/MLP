#include "MegunoLink.h"
#include "ArduinoTimer.h"

const int InputPin = 7;

const int NumberOfMeasurements = 200;
int MeasurementInterval = 10; // microseconds

long MeasurementTime[NumberOfMeasurements]; // microseconds
int Measurement[NumberOfMeasurements];

void setup() 
{
  Serial.begin(57600);
  Serial.println(F("Button Bounce Tester"));

  pinMode(InputPin, INPUT_PULLUP);
}

void loop() 
{
  int ButtonState = digitalRead(InputPin);
  if (ButtonState == 0)
  {
    MeasurementTime[0] = micros();
    Measurement[0] = ButtonState;
    for(int i = 1; i<NumberOfMeasurements; ++i)
    {
      MeasurementTime[i] = micros();
      Measurement[i] = digitalRead(InputPin);
    }

    XYPlot Plot;
    Plot.Clear();
    for(int i=0; i< NumberOfMeasurements; ++i)
    {
      Plot.SendData("Button", MeasurementTime[i] - MeasurementTime[0], Measurement[i]);
    }

    delay(100); // wait for any additional bounces to clear
    while (digitalRead(InputPin) == 0)
    {
      // Wait until button is released
    }
    delay(100); // debounce release. 
  }
}
