/* **********************************************************************************************
*  Example program to plot data from the analoge to digital converter over a UDP channel.
*  Visit http://www.megunolink.com/documentation/plotting/
*  for more information. 
*  
*  This program requires an Arduino with Wiznet 5100 ethernet
*  ********************************************************************************************** */


#include <SPI.h>         // needed for Arduino versions later than 0018
#include <Ethernet.h>
#include <EthernetUdp.h>         // UDP library from: bjoern@cs.stanford.edu 12/30/2008

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
  
  // start the Ethernet and UDP:
  Ethernet.begin(mac); //IP address will be found automatically
  Udp.begin(localPort);

  Serial.println("Setup Complete");
}

void loop() 
{
  int adcval = analogRead(0); //Read adc value


  //Plot Data Every 1000ms
  if((millis()-LastPlotTime)>1000)
  {
    Serial.println("sending udp data"); //notify user using normal serial port
    LastPlotTime = millis();

    //Send UDP data
    Udp.beginPacket(localIPAddress, localPort);
    Udp.write("{TIMEPLOT|data|adc vale|T|");
    Udp.print(adcval);
    Udp.write("}\n");
    Udp.endPacket();
    
    
  }
}

















