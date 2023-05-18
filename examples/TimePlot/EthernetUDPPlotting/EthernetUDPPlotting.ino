/************************************************************************************************
Example Description
Data is sent from a Wiznet 5100 ethernet adapter over UDP to MegunoLink's Time Plot visualiser 
where it is plotted in realtime.

This example uses the raw plotting protocol. Detail about this procotol can be found here:
https://www.megunolink.com/documentation/plotting/plotting-message-reference/
 
More Information
*  http://www.megunolink.com/documentation/plotting/
 
This Example Requires:
* The MegunoLink library for Arduino 
  https://www.megunolink.com/documentation/arduino-integration/
* The Ethernet library
  https://www.arduino.cc/reference/en/libraries/ethernet/
  https://github.com/arduino-libraries/Ethernet
 
MegunoLink Interface
You can download a pre-made interface from:
* https://github.com/Megunolink/MLP/raw/master/examples/TimePlot/EthernetUDPlotting/EthernetUDPPlotting.mlpz
 
You can find out more about MegunoLink and download a free trial from:
* https://www.megunolink.com/
* https://www.megunolink.com/download/
************************************************************************************************/

#include <SPI.h>
#include <Ethernet.h>
#include <EthernetUdp.h>

// Enter a MAC address
byte mac[] = {
  0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED };
  
//Local port to listen to (set this in megunolink)  
unsigned int localPort = 1269;

//Local IP address of the computer you want to send data to (255.255.255.255 = broadcast address)
const char localIPAddress[] = "255.255.255.255";

// An EthernetUDP instance to let us send and receive packets over UDP
EthernetUDP Udp;

// Timer Variables
unsigned long LastPlotTime = 0;

void setup() 
{
  Serial.begin(9600);
  Serial.println("Setup Started");
  
  // start the Ethernet and UDP. An IP address will be found automatically.
  Ethernet.begin(mac); 
  Udp.begin(localPort);

  Serial.println("Setup Complete");
}

void loop() 
{
  int adcval = analogRead(0); //Read adc value


  //Plot Data Every 1000ms
  if((millis()-LastPlotTime)>1000)
  {
    LastPlotTime = millis();

    //notify user using normal serial port
    Serial.println("sending udp data"); 

    //Send UDP data
    Udp.beginPacket(localIPAddress, localPort);
    Udp.write("{TIMEPLOT|data|adc vale|T|");
    Udp.print(adcval);
    Udp.write("}\n");
    Udp.endPacket();
  }
}

















