/* ************************************************************************
Send to Record Table cells. 
   
This example demonstrates sending data to individual cells in a MegunoLink 
record table. Every second it sends a random symbol to a random cell in 
the record table. 

The MegunoLink project for this example is in the same folder as this
Arduino code. To download a free MegunoLink trial, visit:
  - http://www.MegunoLink.com to download MegunoLink.

More Information
  - https://www.megunolink.com/documentation/table/record-table/
  - https://www.megunolink.com/documentation/arduino-libraries/arduino-timer/

************************************************************************ */

#include "MegunoLink.h"
#include "ArduinoTimer.h"

RecordTable MyTable;
::ArduinoTimer SendDataTimer;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.print("MegunoLink Record Table Cell Example\n\n\n");
}

void loop()
{
  if (SendDataTimer.TimePassed_Milliseconds(1000))
  {
    const int MaxRows = 10;
    const int MaxColumns = 10; 

    char Symbols[] = {'x', 'o', '+', '*'};
    
    int Row = random(MaxRows);
    int Column = random(MaxColumns);
    int SymbolIndex = random(sizeof(Symbols));

    MyTable.SetValue(Row, Column, Symbols[SymbolIndex]);
  }
}
