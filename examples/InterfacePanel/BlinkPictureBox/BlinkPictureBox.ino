/* ************************************************************
** This example hides and shows picture boxes on a MLP 
** Interface Panel visualizer. Open the "Blink Picture Box.mlx"
** project in the same folder as this file to load the interface
** panel and see the blinking boxes. 
** ************************************************************ */

#include "MegunoLink.h"

InterfacePanel Panel;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Panel.ShowControl("pbRed");
  delay(400);
  Panel.HideControl("pbRed");
  delay(450);
  Panel.ShowControl("pbGreen");
  delay(400);
  Panel.HideControl("pbGreen");
  delay(450);
}
