/* ************************************************************************
Prompting the user

On receiving a serial message to "launch a missle", this program sends a 
command to MegunoLink requesting confirmation. In response, MegunoLink 
displays a message box and sends a serial message to either confirm or 
abort the "launch". A simple timeout also aborts the launch if confirmation
isn't received in time. 

The example folder also contains a MegunoLink project, with an Interface
Panel for this example. To download a free MegunoLink trial, visit:
  - http://www.MegunoLink.com to download MegunoLink.

More Information
  - https://www.megunolink.com/documentation/getting-started/build-arduino-interface/
  - https://www.megunolink.com/documentation/interface-panel/prompt/
  - https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
  - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/

This example requires:
* Our MegunoLink Arduino library
  https://www.megunolink.com/documentation/arduino-library/
************************************************************************ */

#include "MegunoLink.h"
#include "CommandHandler.h"
#include "ArduinoTimer.h"

InterfacePanel Panel;
CommandHandler<> SerialCmds;

bool WaitingForPromptResponse = false; 
int CurrentPromptId = 1;
::ArduinoTimer PromptTimeout;

void Cmd_BeginMissileLaunch(CommandParameter& p)
{
  if (WaitingForPromptResponse)
  {
    if (PromptTimeout.TimePassed_Seconds(5))
    {
      WaitingForPromptResponse = false;
    }
    else
    {
      Serial.println(F("Missile launch underway. Waiting for confirmation"));
    }
  }

  if (!WaitingForPromptResponse)
  {
    WaitingForPromptResponse = true; 
    Panel.ShowPrompt("MissilePrompt", ++CurrentPromptId, "Do you really want to launch the missile now?");
    PromptTimeout.Reset();
  }
}

void Cmd_HandlePromptResponse(CommandParameter& p)
{
  int PromptId = p.NextParameterAsInteger();
  const char* Response = p.NextParameter();
  if (PromptId == CurrentPromptId)
  {
    WaitingForPromptResponse = false; 
    bool Launch = *Response != '\0' && *Response == 'Y';
    if (Launch)
    {
      Serial.println(F("Fire missiles!!"));
    }
    else
    {
      Serial.println(F("Launch aborted."));
    }
  }
}

void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Missile launch program"));

  SerialCmds.AddCommand(F("BeginLaunch"), Cmd_BeginMissileLaunch);
  SerialCmds.AddCommand(F("PromptResponse"), Cmd_HandlePromptResponse);
}

void loop() 
{
  SerialCmds.Process();
}
