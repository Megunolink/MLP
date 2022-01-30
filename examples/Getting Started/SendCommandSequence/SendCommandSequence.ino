/************************************************************************************************
== Example Description ==
This code helps demonstrate MegunoLink's message monkey visualizer, which lets MegunoLink send
a series of commands to your Arduino sketch. In this example MegunoLink sends commands to 
turn on and off a digital output. 

== This Example Requires ==
* MegunoLink's Arduino library. Install it from MegunoLink by selecting 'Setup Arduino integration' 
  from the gear menu.

== More Information ==
* Download a free trial of MegunoLink: https://www.megunolink.com/download/
* Setup Arduino integration: https://www.megunolink.com/documentation/getting-started/arduino-integration/
* Serial command handler: https://www.megunolink.com/documentation/arduino-libraries/serial-command-handler/

== MegunoLink Interface ==
* Open the MegunoLink interface by selecting 'Send Command Sequence' from MegunoLink's 
  Examples->Getting Started menu. 
 
== Serial Commands ==
This sketch implements the following serial commands:
* !Out <State> <Port>\r\n : Turns a digital output state. Port is the pin number to change. The
  output is turned on when State is 1 and off when state is 0. Port defaults to the built-in
  LED if it is missing. 

************************************************************************************************/

#include "CommandHandler.h" // The serial command handler is defined in here. 

// The serial command handler. Receives serial data and dispatches 
// recognised commands to functions registered during setup. 
CommandHandler<> SerialCommandHandler;

// -----------------------------------------------------------------------
// Command handlers. 
// These functions are called when a serial command is received. 
void Cmd_Out(CommandParameter &Parameters)
{
  int State = Parameters.NextParameterAsInteger(0);
  int Port = Parameters.NextParameterAsInteger(LED_BUILTIN);

  pinMode(Port, OUTPUT);
  digitalWrite(Port, State);
}

// -----------------------------------------------------------------------
void setup()
{
  Serial.begin(9600);
  Serial.println(F("MegunoLink Output Controller"));
  Serial.println(F("----------------------------"));

  // Setup the commands the handler will respond to. The first parameter
  // is the command name, the second is the function that will be called
  // when the command is received. Note that each command name is 
  // inside F(""). This places the command text in program memory to
  // save RAM. Commands are case-sensitive.
  SerialCommandHandler.AddCommand(F("Out"), Cmd_Out);

}

void loop()
{
  // Call the serial command handler's process function. It will receive
  // the serial data and call the registered function when a 
  // recognized command is received. 
  SerialCommandHandler.Process();
}
