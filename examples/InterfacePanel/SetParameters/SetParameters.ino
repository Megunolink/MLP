/* ***********************************************************************
*  Example program to update an Arduino variable using serial commands
*  sent from an interface panel in MegunoLink. Find the MegunoLink project
*  (SetParameters.mlpz), that goes with this example, in the same folder
*  as this Arduino code file. 
* 
*  For more information:
*     Getting started building Arduino interfaces
*       https://www.megunolink.com/documentation/getting-started/build-arduino-interface/
*     Getting started processing serial commands
*       https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
*     Installing the MegunoLink Arduino library:
*       https://www.megunolink.com/documentation/getting-started/arduino-integration/
*     Interface panel reference
*       https://www.megunolink.com/documentation/interface-panel/
*  *********************************************************************** */

// Library to handle serial commands
#include "CommandHandler.h"

// Library to send commands/data to MegunoLink
#include "MegunoLink.h"

/// <summary>
/// The Arduino variable to change using a serial command. 
/// </summary>
int NumberOfTurtles = 0;

/// <summary>
/// Looks after parsing and dispatching serial commands to Arduino functions
/// </summary>
CommandHandler<> SerialCommandHandler;

/// <summary>
/// Called when a 'GetTurtleCount' command is received to query the
/// current count.
/// </summary>
/// <param name="Parameters">No parameters</param>
void Cmd_GetTurtleCount(CommandParameter &Parameters)
{
  // Report count to serial stream. 
  Serial.print(F("Number of turtles = "));
  Serial.println(NumberOfTurtles);

  // Send count to interface panel.
  InterfacePanel TurtleInterface;
  TurtleInterface.SetNumber(F("numTurtles"), NumberOfTurtles);
}

/// <summary>
/// Called when a 'SetTurtleCount' command is received to update the variable.
/// </summary>
/// <param name="Parameters">Contains new count</param>
void Cmd_SetTurtleCount(CommandParameter &Parameters)
{
  // Update Arduino variable with parameter value sent with command. 
  NumberOfTurtles=Parameters.NextParameterAsInteger();
}

void setup()
{
  Serial.begin(9600);
  Serial.println("MegunoLink Pro Turtle Monitor");
  Serial.println("-----------------------------");
  
  // Register commands we can handle.
  SerialCommandHandler.AddCommand(F("SetTurtleCount"), Cmd_SetTurtleCount);
  SerialCommandHandler.AddCommand(F("GetTurtleCount"), Cmd_GetTurtleCount);
  
}

void loop()
{
  // Dispatch and process commands as they are received from the serial port. 
  SerialCommandHandler.Process();
}
