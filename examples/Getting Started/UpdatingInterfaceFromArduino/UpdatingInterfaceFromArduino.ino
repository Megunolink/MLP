/* ***********************************************************************
 * Updating interface from Arduino
 * Example to illustrate changing control values in a MegunoLink interface
 * panel using commands sent from an Arduino sketch. 
 * 
 * Companion MegunoLink project: UpdatingInterfaceFromArduino.mlpz
 * 
 * For more information:
 *   Download MegunoLink trial: 
 *      https://www.MegunoLink.com/download/
 *   Getting started with interface panels:
 *      https://www.megunolink.com/documentation/getting-started/build-arduino-interface/
 *   Updating controls from your Arduino:
 *      https://www.megunolink.com/documentation/interface-panel/arduino-update-interface-panel/
 *   Control reference:
 *      https://www.megunolink.com/documentation/interface-panel/control-reference/
 * *********************************************************************** */

#include <MegunoLink.h>

/// <summary>
/// Use InterfacePanel variables to send commands to controls on interface panels. 
/// Method reference: https://www.megunolink.com/documentation/interface-panel/interface-panel-arduino-reference/
/// </summary>
InterfacePanel MyPanel;

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  // Set text displayed on controls
  MyPanel.SetText(F("Item"), F(""));
  MyPanel.SetText(F("DescriptionTextbox"), F(""));
  MyPanel.SetText(F("DescriptionTextbox"), F("Demo Starting"));
  delay(5000);
  MyPanel.SetText(F("DescriptionTextbox"), F(""));
  delay(500);
  MyPanel.SetText(F("DescriptionTextbox"), F("You can edit various controls from your arduino."));
  MyPanel.SetText(F("Item"), F("including buttons,"));

  // Hide/show controls
  MyPanel.HideControl(F("MyButton"));
  delay(500);
  MyPanel.ShowControl(F("MyButton"));
  delay(500);
  MyPanel.HideControl(F("MyButton"));
  delay(500);
  MyPanel.ShowControl(F("MyButton"));
  delay(500);
  MyPanel.HideControl(F("MyButton"));
  delay(500);
  MyPanel.ShowControl(F("MyButton"));
  delay(500);

  // Enable/disable controls
  MyPanel.DisableControl(F("MyButton"));
  delay(500);
  MyPanel.EnableControl(F("MyButton"));
  delay(500);
  MyPanel.DisableControl(F("MyButton"));
  delay(500);
  MyPanel.EnableControl(F("MyButton"));
  delay(500);
  MyPanel.DisableControl(F("MyButton"));
  delay(500);
  MyPanel.EnableControl(F("MyButton"));
  delay(500);

  // Change control colors
  MyPanel.SetForeColor(F("MyButton"), F("blue"));
  delay(500);
  MyPanel.SetForeColor(F("MyButton"), F("red"));
  delay(500);
  MyPanel.SetForeColor(F("MyButton"), F("green"));
  delay(500);
  MyPanel.SetForeColor(F("MyButton"), F("black"));
  delay(500);
  MyPanel.SetBackColor(F("MyButton"), F("blue"));
  delay(500);
  MyPanel.SetBackColor(F("MyButton"), F("red"));
  delay(500);
  MyPanel.SetBackColor(F("MyButton"), F("green"));
  delay(500);
  MyPanel.SetBackColor(F("MyButton"), F("white"));
  delay(500);


  // Update content of text boxes
  MyPanel.SetText(F("Item"), F("including buttons, textboxes"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("you"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("can"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("edit"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("textboxes"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("from"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("your"));
  delay(500);
  MyPanel.SetText(F("MyTextbox"), F("arduino"));
  delay(500);


  // Update gauge values and labels
  MyPanel.SetText(F("Item"), F("including buttons, textboxes, gauges"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("you"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("can"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("edit"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("gauge"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("labels"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("from"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("your"));
  delay(500);
  MyPanel.SetGaugeLabel(F("MyGauge"), 0, F("arduino"));
  delay(500);
  MyPanel.SetNumber(F("MyGauge"), 100);
  delay(500);
  MyPanel.SetNumber(F("MyGauge"), 200);
  delay(500);
  MyPanel.SetNumber(F("MyGauge"), 300);
  delay(500);
  MyPanel.SetNumber(F("MyGauge"), 400);
  delay(500);
  MyPanel.SetNumber(F("MyGauge"), 500);
  delay(500);


  // Change checkboxes
  MyPanel.SetText(F("Item"), F("including buttons, textboxes, gauges, checkboxes"));
  delay(500);
  MyPanel.SetCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.ClearCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.SetCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.ClearCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.SetCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.ClearCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.SetCheck(F("MyCheckbox"));
  delay(500);
  MyPanel.ClearCheck(F("MyCheckbox"));
  delay(500);


  // Set value for trackbars
  MyPanel.SetText(F("Item"), F("trackbars"));
  delay(500);
  MyPanel.SetNumber(F("MyTrackbar"), 10);
  delay(500);
  MyPanel.SetNumber(F("MyTrackbar"), 20);
  delay(500);
  MyPanel.SetNumber(F("MyTrackbar"), 30);
  delay(500);
  MyPanel.SetNumber(F("MyTrackbar"), 40);
  delay(500);
  MyPanel.SetNumber(F("MyTrackbar"), 50);
  delay(500);


  // Set value for progress bars
  MyPanel.SetText(F("Item"), F("trackbars, progress bars"));
  delay(500);
  MyPanel.SetProgress(F("MyProgressBar"), 10);
  delay(500);
  MyPanel.SetProgress(F("MyProgressBar"), 20);
  delay(500);
  MyPanel.SetProgress(F("MyProgressBar"), 30);
  delay(500);
  MyPanel.SetProgress(F("MyProgressBar"), 40);
  delay(500);
  MyPanel.SetProgress(F("MyProgressBar"), 50);
  delay(500);


  // Control picture visibility
  MyPanel.SetText(F("Item"), F("trackbars, progress bars, pictures"));
  delay(500);
  MyPanel.HideControl(F("PausePicture"));
  MyPanel.ShowControl(F("PlayPicture"));
  delay(500);
  MyPanel.ShowControl(F("PausePicture"));
  MyPanel.HideControl(F("PlayPicture"));
  delay(500);
  MyPanel.HideControl(F("PausePicture"));
  MyPanel.ShowControl(F("PlayPicture"));
  delay(500);
  MyPanel.ShowControl(F("PausePicture"));
  MyPanel.HideControl(F("PlayPicture"));
  delay(500);
  MyPanel.HideControl(F("PausePicture"));
  MyPanel.ShowControl(F("PlayPicture"));
  delay(500);
  MyPanel.ShowControl(F("PausePicture"));
  MyPanel.HideControl(F("PlayPicture"));
  delay(500);


  MyPanel.SetText(F("DescriptionTextbox"), F("You can also have tab pages, value lists, radio buttons,"));
  MyPanel.SetText(F("Item"), F("group boxes, and buttons to launch files."));
  delay(10000);
}
