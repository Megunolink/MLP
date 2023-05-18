/************************************************************************************************
Example Description
In this example we demonstrate how to handle strings with our command handler. This is great if
you want to be able to send your device a password or SSID to establish a network connection or
maybe adjust some text on a display.
 
More Information
*  https://www.megunolink.com/documentation/build-arduino-interface/
*  https://www.megunolink.com/documentation/interface-panel/
*  https://www.megunolink.com/documentation/arduino-libraries/serial-command-handler/
 
This Example Requires:
*  The MegunoLink library for Arduino https://www.megunolink.com/documentation/arduino-integration/

MegunoLink Interface
You can download a pre-made interface from here:
https://github.com/Megunolink/MLP/raw/master/examples/InterfacePanel/HandlingStrings/HandlingStrings.mlpz
 
You can find out more about MegunoLink and download a free trial from here
https://www.megunolink.com/
https://www.megunolink.com/download/
************************************************************************************************/

#include "MegunoLink.h"
#include "CommandHandler.h"
#include "FixedStringBuffer.h"

CommandHandler<> SerialCommandHandler;

void Cmd_SetSSID(CommandParameter &Parameters)
{
  // Create local fixed size character buffer on the stack
  FixedStringBuffer<50> mystring;

  // Put the characters from MegunoLink into buffer
  mystring.print(Parameters.RemainingParameters()); 
  
  Serial.print("NewSSID:");
  Serial.println(mystring);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("MegunoLink - Handling Strings");
  Serial.println("-----------------------------");

  SerialCommandHandler.AddCommand(F("SetSSID"), Cmd_SetSSID);
}

void loop()
{
  SerialCommandHandler.Process();
}
