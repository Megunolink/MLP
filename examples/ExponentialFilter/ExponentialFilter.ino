/* ****************************************************
 *  Exponential Filter example. 
 *  Uses the exponential filter class in the MegunoLink
 *  library to smooth measurements from an ADC. The
 *  raw and smoothed data are sent to MegunoLink for 
 *  plotting to demonstrate the effect of smoothing. 
 *  See: http://www.MegunoLink.com/documentation/arduino-libraries/exponential-filter/
 *  for more information. 
 */

#include "MegunoLink.h"
#include "Filter.h"

// Create a new exponential filter with a weight of 10 and initial value of 0. 
ExponentialFilter<long> ADCFilter(10, 0);

void setup() 
{
  Serial.begin(9600);
  Serial.println("Exponential Filter demo");
  Serial.println("-----------------------");
}

void loop() 
{
  int RawValue = analogRead(0);
  ADCFilter.Filter(RawValue);

  TimePlot Plot;
  Plot.SendData("Raw", RawValue);
  Plot.SendData("Filtered", ADCFilter.Current());

  delay(100);
}
