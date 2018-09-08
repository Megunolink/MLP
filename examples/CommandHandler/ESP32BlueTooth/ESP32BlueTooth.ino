/* --------------------------------------------------------------
 *  This example demonstrates the command handler processing 
 *  commands sent over the ESP32 Bluetooth connection. For
 *  more information on the command handler see:
 *    https://www.megunolink.com/documentation/getting-started-process-serial-commands/
 *    https://www.megunolink.com/documentation/arduino-libraries/serial-command-handler/
 *  To connect with the ESP32 in windows, open the Settings application;
 *  choose Devices and Add Bluetooth or other device. 
 *  
 *  Once connected, the program will respond to the command:
 *    !GetConnectionColor\r\n
 */
#include "BluetoothSerial.h"
#include "CommandHandler.h"
#include "ArduinoTimer.h"

BluetoothSerial SerialBT;
CommandHandler<> Cmds(SerialBT);

void Cmd_ConnectionColor(CommandParameter &p)
{
  SerialBT.println("Blue");
}

void setup() 
{
  Serial.begin(9600);
  Serial.println("Serial Bluetooth test");
  SerialBT.begin("ESP32");
  Cmds.AddCommand(F("GetConnectionColor"), Cmd_ConnectionColor);
}

void loop() 
{
  Cmds.Process();
}
