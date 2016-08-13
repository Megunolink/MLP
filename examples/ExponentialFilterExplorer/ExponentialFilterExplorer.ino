/* ****************************************************
 *  Exponential Filter example. 
 *  Uses the exponential filter class in the MegunoLink
 *  library to smooth measurements from an ADC. The amount
 *  of filtering applied can be controlled by MegunoLink
 *  by sending a serial command !SetFilter value\r\n.
 *  The raw and smoothed data are sent to MegunoLink for 
 *  plotting to demonstrate the effect of smoothing. 
 *  See: http://www.MegunoLink.com/documentation/arduino-libraries/exponential-filter/
 *  for more information. 
 */

#include "MegunoLink.h"
#include "Filter.h"
#include "CommandHandler.h"

// Create a new exponential filter with a weight of 10 and initial value of 0. 
ExponentialFilter<long> ADCFilter(10, 0);

CommandHandler<> SerialCommands;

void Cmd_SetFilter(CommandParameter &p)
{
  int NewFilterWeight = p.NextParameterAsInteger(ADCFilter.GetWeight());
  if (NewFilterWeight < 0)
  {
    NewFilterWeight = 0;
  }
  if (NewFilterWeight > 100)
  {
    NewFilterWeight = 100;
  }

  ADCFilter.SetWeight(NewFilterWeight);
  Serial.print(F("Filter weight set to: "));
  Serial.println(NewFilterWeight);
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("Exponential Filter Explorer");
  Serial.println("---------------------------");
  Serial.println();
  Serial.println("Commands: ");
  Serial.println("  !SetFilter value\\r\\n");
  Serial.println("Commands: ");
  Serial.println("  !SetFilter 20\\r\\n set filter parameter to 20%. Range is 0..100");

  SerialCommands.AddCommand(F("SetFilter"), Cmd_SetFilter);
}

void loop() 
{
  SerialCommands.Process();
  
  int RawValue = analogRead(0);
  ADCFilter.Filter(RawValue);

  TimePlot Plot;
  Plot.SendData("Raw", RawValue);
  Plot.SendData("Filtered", ADCFilter.Current());

  delay(100);
}
