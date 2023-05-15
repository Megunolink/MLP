/* **********************************************************************************************
*  Example program to send CSV data through Megunolinks message system and log data to a text file
*  based on a file name supplied from the Arduino. 
*  ********************************************************************************************** */

#include "MegunoLink.h"
#include "CommandHandler.h"
#include "ArduinoTimer.h"

Message Msg;
CommandHandler<> Cmds;
ArduinoTimer ExperimentTimer;


int SamplingPeriod = 10;
uint32_t ExperimentStartTime = -SamplingPeriod * 1000;


void Cmd_StartExperiment(CommandParameter &p)
{
  SamplingPeriod = p.NextParameterAsInteger();
  Msg.LogTo(p.RemainingParameters());
  ExperimentStartTime = millis();
}

void setup()
{
  Serial.begin(9600);
  Cmds.AddCommand(F("Start"), Cmd_StartExperiment);

}

void loop()
{
  Cmds.Process();
  if ((millis() - ExperimentStartTime) < (SamplingPeriod * 1000))
  {
    int Value1 = analogRead(A0);
#if defined(A1)
    int Value2 = analogRead(A1);
#else
    // Some boards only have 1 analog input. For them we'll get another value from the first port. 
    int Value2 = analogRead(A0);
#endif

    Msg.Begin();
    Serial.print(millis() - ExperimentStartTime); //Milliseconds since run started
    Serial.print(",");
    Serial.print(Value1);
    Serial.print(",");
    Serial.print(Value2);
    Msg.End();

    delay(100);
  }

}