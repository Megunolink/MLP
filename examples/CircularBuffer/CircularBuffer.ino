/* *****************************************************************************
*  Demo for circular buffer. 
*  Records the time-stamp for button pushes in a circular buffer and 
*  periodically writes them to the serial port. 
*  ***************************************************************************** */

#include "CircularBuffer.h"
#include "ArduinoTimer.h"

// The buffer which will hold button presses. We use the time stamp from 
// the micros timer to store the time a button press was registered. So
// the buffer must store unsigned long values. Up to 20 button times 
// will be stored before old ones are overwritten. 
typedef CircularBuffer<unsigned long, 20> ButtonTimeBuffer;
ButtonTimeBuffer ButtonTimes;

// The pin that the button is connected to. The other side of the button
// should be connected to ground. 
const int ButtonPin = 3;

// The amount of time between writing out all the data in the circular buffer
// and a timer to keep track if that amount of time has passed yet. 
const int PrintingPeriod = 10; // seconds
ArduinoTimer PrintingTimer;

void setup() 
{
  Serial.begin(9600);

  pinMode(ButtonPin, INPUT_PULLUP);
}

void loop() 
{
  bool ButtonPressed = digitalRead(ButtonPin) == 0;
  static bool WasPressed = false;
  
  if (ButtonPressed)
  {
    if (!WasPressed)
    {
      WasPressed = true; 
      unsigned long CurrentTime = micros();
      ButtonTimes.Add(CurrentTime);
    }
  }
  else
  {
    WasPressed = false; 
  }

  if (PrintingTimer.TimePassed_Seconds(PrintingPeriod))
  {
    for(ButtonTimeBuffer::ForwardIterator Iterator(ButtonTimes); Iterator.AtEnd() == false; Iterator.Next())
    {
      Serial.print(Iterator.ItemNumber());
      Serial.print('\t');
      Serial.println(Iterator.CurrentValue());
    }
    
    ButtonTimes.Clear();
  }
}
