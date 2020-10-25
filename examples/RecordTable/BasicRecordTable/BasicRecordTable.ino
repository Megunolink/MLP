/* ************************************************************************
   Basic Demonstration of MegunoLinks Record Table
   This example demonstrates MegunoLinks Record Table visualiser by outputting
   10 lines of data every 5 seconds. The table is then reset and 10 new records
   are generated.

   Visit:
   * http://www.MegunoLink.com to download MegunoLink.
   ************************************************************************ */

#include "MegunoLink.h"
#include "ArduinoTimer.h"

RecordTable MyTable;
ArduinoTimer TableRefreshTimer;

void setup()
{
  Serial.begin(115200);
  delay(1000);

  Serial.print("MegunoLink Record Table Basic Example\n\n\n");
}

void loop()
{

  if (TableRefreshTimer.TimePassed_Milliseconds(5000))
  {
    MyTable.ClearAllRows();
    for (int i = 0; i < 10; i++)
    {
      MyTable.AddRow(i, rand(), "fish", true, millis(), analogRead(0));
      delay(100);
    }
  }

}
