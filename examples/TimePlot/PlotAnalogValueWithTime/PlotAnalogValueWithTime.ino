/* **********************************************************************************************
*  Example program to plot data from the analoge to digital converter on a chart using
*  time supplied from the Aurdio. Normally the Time Plot will use the computer's local time
*  for the x-axis. In this example, we generate our own local time. You could use a real-time
*  clock module too, if one is available. 
*  
*  More Information
*    - http://www.megunolink.com/documentation/plotting/
*    - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/
*  ********************************************************************************************** */

#include "MegunoLink.h" 
#include "ArduinoTimer.h"

// The plot we are sending data to. 
TimePlot MyPlot;

// A timer to trigger sending data. 
::ArduinoTimer SendDataTimer;

// Timer to maintain the system time. 
::ArduinoTimer ClockTick;

/* ----------------------------------------------------------------------------------------------
*  Time Functions
*  Normally keep track of the current time with a real-time clock. Here we fake time.
 */

void SetupClock()
{
  tm Now;
  memset(&Now, 0, sizeof(Now));
  Now.tm_year = 120; // year relative to 1900. 
  Now.tm_mon = 0;    // Jan = 0, Feb = 1,...
  Now.tm_mday = 4;   // Day of month. 1, 2, ...
  Now.tm_hour = 15;  // Hour of day
  Now.tm_min = 0;    // Minute of hour. 
  Now.tm_sec = 0;    // Second of minute. 

  time_t EpocTime = mktime(&Now);

  set_system_time(EpocTime);
}

void MaintainClock()
{
  if (ClockTick.TimePassed_Milliseconds(1000))
  {
    system_tick();
  }
}

tm GetCurrentTime()
{
  time_t CurrentEpoc = time(NULL);

  tm CurrentTime;
  gmtime_r(&CurrentEpoc, &CurrentTime);
  return CurrentTime;
}

#if !defined(__AVR__)
// AVR boards (e.g., Uno, Mega2560) implement some clock functions
// that aren't available for other devices. So we'll roll our own
// for the sake of the example. 

time_t CurrentTime;

#define UNIX_OFFSET 946684800 // Offset between AVR time and Windows time epochs.
void set_system_time(time_t t)
{
  CurrentTime = t;
}

void system_tick()
{
  ++CurrentTime;
}
#endif


/* ----------------------------------------------------------------------------------------------
*  Program setup and loop. 
 */
void setup()
{
  Serial.begin(9600);
  SetupClock();
}

void loop()
{
  MaintainClock();

  if (SendDataTimer.TimePassed_Seconds(1))
  {
    // Using a time structure:
    tm CurrentTime = GetCurrentTime();
    int DataValue0 = analogRead(0);
    MyPlot.SendData("ADCValue0", CurrentTime, DataValue0);

    // Using time epoch. This will be interpreted
    // as local time by MegunoLink. 
    time_t EpochTime = time(NULL) + UNIX_OFFSET;
    float DataValue1 = analogRead(0);
    MyPlot.SendFloatData(F("ADCValue1"), EpochTime, DataValue1, 3);
  }
}
