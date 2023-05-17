/*************************************************************
This example demonstrates message monkey triggers that could
be used to send commands to move a motor after it has reached
the home position. 

To keep the example simple, serial messages are displayed
in place of a motor driver implementation. 

The MegunoLink project for this example is in the same folder as this
Arduino code. To download a free MegunoLink trial, visit:
  - http://www.MegunoLink.com to download MegunoLink.

More Information
  - https://www.megunolink.com/documentation/message-monkey/
  - https://www.megunolink.com/documentation/interface-panel/requesting-data-from-an-interface-panel/
  - https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
  - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/
************************************************************** */

#include "MegunoLink.h"
#include "CommandHandler.h"
#include "ArduinoTimer.h"


// --- Serial command handlers. 

// Receive and process serial commands. 
CommandHandler<> SerialCmds;

void Cmd_FindHome(CommandParameter &p)
{
  FindHome();
}

void Cmd_MoveTo(CommandParameter &p)
{
  // Move motor to supplied position
  int NewPosition = p.NextParameterAsInteger();
  MoveTo(NewPosition);
}

// --- Mock motor driver
bool FindingHome = false; 
bool MovingMotor = false; 
::ArduinoTimer MotorMovingTimer; // in place of real motor driver.

void FindHome()
{
  if (MovingMotor)
  {
    Serial.println(F("Can't move; finding home."));
  }

  Serial.println(F("Seeking home..."));

  // In lieu of a real motor driver with a sensor when
  // the motor reaches home position, we just set a flag
  // and start a timer to simulate the movement time. 
  FindingHome = true;
  MotorMovingTimer.Reset();
}

void MoveTo(int NewPosition)
{
  if (FindingHome)
  {
    Serial.println(F("Can't move; finding home."));
  }

  Serial.print(F("Move to "));
  Serial.println(NewPosition);

  // In lieu of a real motor driver we just start a 
  // timer we just set a flag and start a timer.
  MovingMotor = true; 
  MotorMovingTimer.Reset();  
}

void TrackMotorState()
{
  Monkey Mky;

  if (FindingHome && MotorMovingTimer.TimePassed_Seconds(5))
  {
    FindingHome = false; 
    Serial.println(F("Reached home"));

    // Trigger the next actions in the message monkey
    Mky.SetTrigger(F("HomeDone"));
  }

  if (MovingMotor && MotorMovingTimer.TimePassed_Seconds(2))
  {
    MovingMotor = false;
    Serial.println(F("Move done"));

    // Trigger the next actions in the message monkey
    Mky.SetTrigger(F("MoveDone"));
  }

  static ::ArduinoTimer ProgressReporter;
  if (ProgressReporter.TimePassed_Milliseconds(300))
  {
    if (FindingHome)
    {
      Serial.println(F("homing..."));
    }

    if (MovingMotor)
    {
      Serial.println(F("moving..."));
    }
  }
}

// --- Setup & loop
void setup() 
{
  Serial.begin(9600);
  Serial.println(F("Message Monkey Trigger Example"));
  Serial.println(F("------------------------------"));

  SerialCmds.AddCommand(F("Home"), Cmd_FindHome);
  SerialCmds.AddCommand(F("Goto"), Cmd_MoveTo);
}

void loop() 
{
  SerialCmds.Process();  
  TrackMotorState();
}
