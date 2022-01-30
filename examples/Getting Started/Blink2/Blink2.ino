/* ***********************************************************************************************
*  Example demonstrating MegunoLink's interface panel visualizer and Arduino command handler. 
*  It extends the classic Arduino Blink example with serial commands to control the flash rate. 
*  Find the MegunoLink project (Blink2.mlpz), that goes with this example, in the same folder as
*  this Arduino code file. 
* 
*  You'll need to install MegunoLink's Arduino library to use this example:
*       https://www.megunolink.com/documentation/getting-started/arduino-integration/
*
*  For more information:
*     Getting started building Arduino interfaces
*       https://www.megunolink.com/documentation/getting-started/build-arduino-interface/
*     Getting started processing serial commands
*       https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
*     Interface panel reference
*       https://www.megunolink.com/documentation/interface-panel/
* 
*  The following serial commands are supported:
*       !OnTime n\r\n
*         Sets the amount of time the LED remains on to n [milliseconds]
* 
*       !OffTime n\r\n
*         Sets the amount of time the LED remains off to n [milliseconds]
* 
*       !ListAll\r\n
*         Lists current blink parameters & sends them to the interface panel. 
*
* *********************************************************************************************** */

#include "CommandHandler.h" // Library to handle serial commands
#include "MegunoLink.h"     // Library to send commands/data to MegunoLink

/// <summary>
/// Variables that control the blink interval and keep track of when we blinked. 
/// </summary>
long LastBlink = 0; // Time we last blinked the LED
int OnTime = 10;    // Amount of time the LED remains on [milliseconds]
int OffTime = 100;  // Amount of time the LED remains off [milliseconds]

/// <summary>
/// The command handler looks after parsing and dispatching serial commands to Arduino functions
/// </summary>
CommandHandler<> SerialCommandHandler;

/// <summary>
/// Called when the 'OnTime' command is received to set the time the LED remains on. 
/// </summary>
/// <param name="Parameters">Contains new on-time (in milliseconds)</param>
void Cmd_SetOnTime(CommandParameter& Parameters)
{
  // Update Arduino variable with parameter value from serial command. 
  OnTime = Parameters.NextParameterAsInteger(OnTime);
}

/// <summary>
/// Called when the 'OffTime' command is received to set the time the LED remains off. 
/// </summary>
/// <param name="Parameters">Contains new off-time (in milliseconds)</param>
void Cmd_SetOffTime(CommandParameter& Parameters)
{
  // Update Arduino variable with parameter value from serial command. 
  OffTime = Parameters.NextParameterAsInteger(OffTime);
}

/// <summary>
/// Called when the 'ListAll' command is received
/// </summary>
/// <param name="Parameters">No parameters</param>
void Cmd_ListAll(CommandParameter& Parameters)
{
  // Write current timing to serial stream
  Serial.print(F("OnTime [ms]="));
  Serial.println(OnTime);
  Serial.print(F("OffTime [ms]="));
  Serial.println(OffTime);

  // Send timing to interface panel. 
  InterfacePanel BlinkController;
  BlinkController.SetNumber(F("numOnTime"), OnTime);
  BlinkController.SetNumber(F("numOffTime"), OffTime);
}

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Blink 2.0"));
  Serial.println(F("=========="));

  // Register commands we can handle with the function called when each command is received. 
  SerialCommandHandler.AddCommand(F("OnTime"), Cmd_SetOnTime);
  SerialCommandHandler.AddCommand(F("OffTime"), Cmd_SetOffTime);
  SerialCommandHandler.AddCommand(F("ListAll"), Cmd_ListAll);

  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() 
{
  // Check for serial commands and dispatch them to registered functions.
  SerialCommandHandler.Process();

  // Update the LED
  uint32_t uNow = millis();
  if ( (uNow - LastBlink) < OnTime)
  {
    digitalWrite(LED_BUILTIN, HIGH);
  }
  else
  {
    digitalWrite(LED_BUILTIN, LOW);
  }

  if ( (uNow - LastBlink) > (OnTime + OffTime) )
  {
    LastBlink = uNow;
  }
}

