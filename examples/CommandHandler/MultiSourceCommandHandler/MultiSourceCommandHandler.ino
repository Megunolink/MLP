/* ************************************************************************
MultiSourceCommandHandler

This example demonstrates decoding serial commands received from two
serial sources and dispatching commands. Each serial source uses a separate
command processor to buffer characters and decode commands. A single 
command dispatcher is used so serial commands can be received from either
serial source. 

The example processes the following commands:
* !SetTurtleCount <Count>\r\n
  Set's the global NumberOfTurtles to <Count>, an integer. 
* !GetTurtleCount\r\n 
  Writes the NumberOfTurtles global value to the serial stream that 
  sent the command. 

More Information
*  https://www.megunolink.com/documentation/build-arduino-interface/
*  https://www.megunolink.com/documentation/interface-panel/
*  https://www.megunolink.com/documentation/arduino-libraries/serial-command-handler/

You can find out more about MegunoLink and download a free trial from:
* https://www.megunolink.com/
* https://www.megunolink.com/download/

This example requires the MegunoLink library for Arduino:
* Setup: https://www.megunolink.com/documentation/install/arduino-integration-setup/
* Reference https://www.megunolink.com/documentation/arduino-library/
************************************************************************ */

#include "MegunoLink.h"
#include "CommandProcessor.h"

int NumberOfTurtles = 0;

CommandDispatcher<> CommonCommands;
CommandProcessor<> SerialCommandHandler(CommonCommands, Serial);
CommandProcessor<> Serial2CommandHandler(CommonCommands, Serial2);

void Cmd_GetTurtleCount(CommandParameter &Parameters)
{
  Parameters.Response.print(F("Number of turtles = "));
  Parameters.Response.println(NumberOfTurtles);
}

void Cmd_SetTurtleCount(CommandParameter &Parameters)
{
  NumberOfTurtles=Parameters.NextParameterAsInteger();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("MegunoLink Pro Turtle Monitor");
  Serial.println("-----------------------------");
  
  Serial2.begin(4800);
  
  CommonCommands.AddCommand(F("SetTurtleCount"), Cmd_SetTurtleCount);
  CommonCommands.AddCommand(F("GetTurtleCount"), Cmd_GetTurtleCount);
  
}

void loop()
{
  SerialCommandHandler.Process();
  Serial2CommandHandler.Process();
}
