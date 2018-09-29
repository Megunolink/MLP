/* ************************************************************************
IsMegunoLinkConnected

This program demonstrates how MegunoLink's Interface Panel and our command
handler Arduino library can be used to identify when its connected to 
MegunoLink and when its not. This allows you to change the behaviour dynamically.

For example when its plugged in you might want to enter a config mode. When its 
unplugged you might want it to run the program as usual.

The example folder also contains a MegunoLink project, with an Interface
Panel to update the variables.
Visit:
* http://www.MegunoLink.com to download MegunoLink.
************************************************************************ */

#include "MegunoLink.h"
#include "ArduinoTimer.h"
#include "CommandHandler.h"

InterfacePanel MyPanel;
ArduinoTimer MLPCheckTimer;
ArduinoTimer StatusPrintTimer;
CommandHandler<> MyCommandHanlder;

uint32_t LastAnnounceTime = 0;
uint32_t MLPNotThereTimeout = 10*1000; //mS
bool IsMLPThere = false;

// This function is called whenever MegunoLink successfully responds
void Cmd_MegunoLinkIsHere(CommandParameter &Parameters)
{
  LastAnnounceTime = millis();
}


void setup()
{
  Serial.begin(9600);
  MyCommandHanlder.AddCommand(F("MLIsHere"), Cmd_MegunoLinkIsHere);
}


void loop()
{
  MyCommandHanlder.Process();

  // Sends a message to MegunoLink every 5 seconds to check connection
  if (MLPCheckTimer.TimePassed_Seconds(5))
  {
    MyPanel.CallCommand(F("Announce"));
  }

  // If the arduino has herd from MegunoLink in the last timeout period then it returns true, else false.
  IsMLPThere = ((millis() - LastAnnounceTime) > MLPNotThereTimeout) ? false : true;

  // This prints the result every 1 second to confirm its working
  if (StatusPrintTimer.TimePassed_Milliseconds(1000))
  {
    Serial.print("Is MLP there? ");
    Serial.println(IsMLPThere);
  }
}
