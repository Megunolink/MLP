/* **********************************************************************************************
*  Example program to send CSV data through Megunolinks message system. These are separated from the
*  main serial stream and can either be displayed (Message Monitor) or logged (Message Logger).
*  Visit http://www.megunolink.com/documentation/monitoring-data/ to see how to use our message monitor and
*  http://www.megunolink.com/documentation/logging-data/ to use our message logger.
*  ********************************************************************************************** */
#include "MegunoLink.h"

Message MyCSVMessage("Data"); //"Data" = the taget message channel (remember to select this in megunolink)

// When logging make sure you specifiy a path for the logfile and enable logging.

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // The values that we want to send...
  int Value1 = analogRead(A0);
#if defined(A1)
  int Value2 = analogRead(A1);
#else
  // Some boards only have 1 analog input. For them we'll get another value from the first port. 
  int Value2 = analogRead(A0);
#endif

  // Sends the microcontroller time, and the analog value using a comma separated format 
  // perfect for use with tools like excel and matlab
  MyCSVMessage.Begin();
  Serial.print(millis());
  Serial.print(",");
  Serial.print(Value1);
  Serial.print(",");
  Serial.print(Value2);
  MyCSVMessage.End();

  delay(100);
}

