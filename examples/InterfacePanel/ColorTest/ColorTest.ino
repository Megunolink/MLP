/* **************************************************
 *  Colour Test Example
 *  Control the colours of buttons on an interface
 *  panel from your Arduino. Load the companion project
 *  Color Test.mlx into MegunoLink.
 */

#include "MegunoLink.h"

void setup() 
{
  Serial.begin(9600);
  Serial.println("Color Test");
}

void loop() 
{
  InterfacePanel UI;

  // Colours can be by name or hex string. 
  // Named colours are here: https://msdn.microsoft.com/en-us/library/system.drawing.color(v=vs.110).aspx
  // Hex values are RRGGBB
  UI.SetBackColor("bttA", "Red");
  UI.SetBackColor("bttB", "00FF00"); // Green

  delay(1000);
  
  UI.SetBackColor("bttA", "AliceBlue");
  UI.SetBackColor("bttB", "FFFF00"); // Yellow

  delay(1000);
}
