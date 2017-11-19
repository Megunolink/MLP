#include "MegunoLink.h"
#include "CommandHandler.h"
#include "PString.h" //This example requires the PString library http://arduiniana.org/libraries/pstring/


CommandHandler<> SerialCommandHandler;

void Cmd_SetSSID(CommandParameter &Parameters)
{
  char buffer[50]; //Create character buffer for PString to use
  PString mystring(buffer, sizeof(buffer)); //Initialise PString object
  mystring.print(Parameters.RemainingParameters()); //Print the characters from MegunoLink into PString buffer
  
  Serial.print("NewSSID:");
  Serial.println(buffer);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("MegunoLink Pro - Handling Strings");
  Serial.println("-----------------------------");

  SerialCommandHandler.AddCommand(F("SetSSID"), Cmd_SetSSID);

}

void loop()
{
  SerialCommandHandler.Process();
}
