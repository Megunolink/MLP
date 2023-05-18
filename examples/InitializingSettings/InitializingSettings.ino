/* ******************************************************************
Example illustrating how to initialize graph appearance and interface 
panel controls with current configuration data when a serial 
connection is opened. 

The example folder also contains a MegunoLink project for this example.
To download a free MegunoLink trial, visit:
  http://www.MegunoLink.com to download MegunoLink.

More Information
  - https://www.megunolink.com/articles/how-do-i/sending-initial-settings/
  - https://www.megunolink.com/documentation/getting-started/processing-serial-commands/
  - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/

*/
#include "MegunoLink.h"
#include "ArduinoTimer.h"
#include "CommandHandler.h"

// To process serial commands. 
CommandHandler<> SerialCmds;

// For communicating with plot and interface panel visualizers. 
TimePlot Plot;
InterfacePanel Panel;

// To periodically send measurements.
::ArduinoTimer SendMeasurementsTimer;
unsigned long UpdateInterval = 100;

// Command handler to send settings when the 'SendConfig'
// command is received. 
void Cmd_SendConfiguration(CommandParameter& p)
{
  SendConfiguration();
}

// Send current configuration to MegunoLink.
void SendConfiguration()
{
  Plot.SetTitle(F("My data"));
  Plot.SetXLabel(F("Measurement time"));
  Plot.SetYLabel(F("Voltage"));

  Panel.SetNumber(F("DataRate"), UpdateInterval);
}

// Setup communications and commands. 
void setup() 
{
  Serial.begin(9600);

  SerialCmds.AddCommand(F("SendConfig"), Cmd_SendConfiguration);
  SerialCmds.AddVariable(F("DataRate"), UpdateInterval);

  SendConfiguration();
}

// Main loop. 
void loop() 
{
  // Receive and dispatch serial commands. 
  SerialCmds.Process();

  // Periodically send measurements to MegunoLink. 
  if (SendMeasurementsTimer.TimePassed_Milliseconds(UpdateInterval))
  {
    Plot.SendData(F("Battery"), analogRead(0));
  }
}
