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
   Panel to control the parameters. 
   Visit:
   * http://www.MegunoLink.com to download MegunoLink.
   * http://www.megunolink.com/documentation/build-arduino-interface/ 
     for more information on this example.
   ************************************************************************ */

// For more information on installing the MegunoLink Arduino library check out our documentation
// http://www.megunolink.com/documentation/arduino-integration/

// You can download the MegunoLink Interface (.mlx) that goes with this example here
// http://www.megunolink.com/examples/arduino/InterfacePanel/Blink2/Blink2.mlx

   

// Import the serial command handler. If this fails, install the MegunoLink library. 
// See: http://www.megunolink.com/documentation/arduino-library/
#include "CommandHandler.h" 

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

  // Setup the serial commands we can repond to
  SerialCommandHandler.AddCommand(F("OnTime"), Cmd_SetOnTime);
  SerialCommandHandler.AddCommand(F("OffTime"), Cmd_SetOffTime);
  SerialCommandHandler.AddCommand(F("ListAll"), Cmd_ListAll);
  SerialCommandHandler.SetDefaultHandler(Cmd_Unknown);

  pinMode(LEDPin, OUTPUT);
}

void loop() 
{
  // Check for serial commands and dispatch them.
  SerialCommandHandler.Process();

  // Update the LED
  uint32_t uNow = millis();
  if (uNow - LastBlink < OnTime)
    digitalWrite(LEDPin, HIGH);
  else
    digitalWrite(LEDPin, LOW);

  if (uNow - LastBlink > OnTime + OffTime)
    LastBlink = uNow;
}

void Cmd_ListAll(CommandParameter &Parameters)
{
  Serial.print(F("OnTime [ms]="));
  Serial.println(OnTime);
  Serial.print(F("OffTime [ms]="));
  Serial.println(OffTime);
}

void Cmd_SetOnTime(CommandParameter &Parameters)
{
	OnTime = Parameters.NextParameterAsInteger(OnTime);
}

void Cmd_SetOffTime(CommandParameter &Parameters)
{
	OffTime = Parameters.NextParameterAsInteger(OffTime);
}

void Cmd_Unknown()
{
  Serial.println(F("I don't understand"));
}
