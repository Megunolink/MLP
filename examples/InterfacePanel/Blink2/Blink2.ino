/* ************************************************************************
   Blink 2.0
   This program is a demonstration of the MegunoLink library for Arduino
   serial communication. All commands start with a ! character and end
   with \r (carrige return). It responds to the following serial commands:
      !OnTime n\r\n
        Sets the amount of time the LED remains on to n [milliseconds]

      !OnTime ?\r\n
        Returns the amount of time the LED remains on [milliseconds]

      !OffTime n\r\n
        Sets the amount of time the LED remains off to n [milliseconds]

      !OffTime ?\r\n
        Returns the amount of time the LED remains off [milliseconds]

   The program folder also contains a MegunoLink project, with an Interface
   Panel to control the parameters. Visit www.MegunoLink.com to
   download MegunoLink.
   ************************************************************************ */

#include "CommandHandler.h" // The serial command handler is defined in here. 

CommandHandler<> SerialCommandHandler;

long LastBlink = 0; // Time we last blinked the LED
int OnTime = 10; // Amount of time the LED remains on [milliseconds]
int OffTime = 100; // Amount of time the LED remains off [milliseconds]

const int LEDPin = 13; // Pin the LED is attached to 

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Blink 2.0"));
  Serial.println(F("=========="));

  SerialCommandHandler.AddVariable(F("OnTime"), OnTime);
  SerialCommandHandler.AddVariable(F("OffTime"), OffTime);

  pinMode(LEDPin, OUTPUT);
}

void loop() 
{
  SerialCommandHandler.Process();

  uint32_t uNow = millis();
  if (uNow - LastBlink < OnTime)
    digitalWrite(LEDPin, HIGH);
  else
    digitalWrite(LEDPin, LOW);

  if (uNow - LastBlink > OnTime + OffTime)
    LastBlink = uNow;
}