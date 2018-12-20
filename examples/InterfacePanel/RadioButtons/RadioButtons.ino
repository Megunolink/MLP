/* **********************************************************************************************
Example program to process the radio buttons as they change state.
Visit http://www.megunolink.com/documentation/interface-panel
for more information.
*  ********************************************************************************************** */
#include "MegunoLink.h"
#include "CommandHandler.h"

// For more information on installing the MegunoLink Arduino library check out our documentation
// http://www.megunolink.com/documentation/arduino-integration/

// You can download the MegunoLink Interface (.mlx) that goes with this example here
// http://www.megunolink.com/examples/arduino/InterfacePanel/RadioButtons/RadioButtons.mlpz


bool RBLow = true;
bool RBMed = false;
bool RBHigh = false;

CommandHandler<> SerialCommandHandler;


void Cmd_RadioButtonLow(CommandParameter &Parameters)
{
  RBLow = Parameters.NextParameterAsInteger();
}

void Cmd_RadioButtonMedium(CommandParameter &Parameters)
{
  RBMed = Parameters.NextParameterAsInteger();
}

void Cmd_RadioButtonHigh(CommandParameter &Parameters)
{
  RBHigh = Parameters.NextParameterAsInteger();
}

void Cmd_Print(CommandParameter &Parameters)
{
  Serial.println("\n\n");
  Serial.print("RB Low  = "); Serial.println(RBLow);
  Serial.print("RB Med  = "); Serial.println(RBMed);
  Serial.print("RB High = "); Serial.println(RBHigh);
}

void setup()
{
  Serial.begin(9600);
  Serial.println("MegunoLink Pro Radio Button Demo");
  Serial.println("-----------------------------");

  SerialCommandHandler.AddCommand(F("RBLow"), Cmd_RadioButtonLow);
  SerialCommandHandler.AddCommand(F("RBMed"), Cmd_RadioButtonMedium);
  SerialCommandHandler.AddCommand(F("RBHigh"), Cmd_RadioButtonHigh);
  SerialCommandHandler.AddCommand(F("Print"), Cmd_Print);

}

void loop()
{
  SerialCommandHandler.Process();
}