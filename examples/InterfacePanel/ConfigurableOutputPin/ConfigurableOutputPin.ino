/* ************************************************************************
Configurable Output Pin
This program demonstrates how MegunoLink's Interface Panel and our command
handler Arduino library can be used to reconfigure which IO pin your device
is using at runtime.

The example folder also contains a MegunoLink project, with an Interface
Panel to control the IO Pin.
Visit:
* http://www.MegunoLink.com to download MegunoLink.
************************************************************************ */

#include "MegunoLink.h"
#include "CommandHandler.h"


int IOPort = 9; //initial IO pin number

long LastToggleTime = 0; // Time we last toggled the IO
int OnTime = 10; // Amount of time the IO remains on [milliseconds]
int OffTime = 100; // Amount of time the IO remains off [milliseconds]

CommandHandler<> SerialCommandHandler;

void Cmd_SetIOPin(CommandParameter &Parameters)
{
  Serial.print("Setting IO Port to:");
  IOPort = Parameters.NextParameterAsInteger();
  pinMode(IOPort, OUTPUT);
  Serial.println(IOPort);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Configurable IO Pin Demo");
  Serial.println("-----------------------------");

  pinMode(IOPort, OUTPUT);

  SerialCommandHandler.AddCommand(F("SetIOPin"), Cmd_SetIOPin);
}

void loop()
{
  SerialCommandHandler.Process();

  // Toggle the IO Pin
  uint32_t uNow = millis();
  if (uNow - LastToggleTime < OnTime)
    digitalWrite(IOPort, HIGH);
  else
    digitalWrite(IOPort, LOW);

  if (uNow - LastToggleTime > OnTime + OffTime)
    LastToggleTime = uNow;
}
