#include "DNSServer.h"
#include "ESP8266WebServer.h"
#include "WiFiManager.h"
#include "ESP8266WiFi.h"
#include "WiFiUdp.h"

#include "MegunoLink.h"

const int SourcePort = 52790;
const int DestinationPort = 52791;
const IPAddress DestinationIp(255, 255, 255, 255);

WiFiManager ConnectionManager;
WiFiUDP UdpConnection;

void setup() 
{
  Serial.begin(9600);
  Serial.println("WiFi Test");

  Serial.println("Connecting");
  ConnectionManager.autoConnect();
  Serial.println("Connected");
  
  UdpConnection.begin(SourcePort);
}

void loop() 
{
  // Send a message
  UdpConnection.beginPacket(DestinationIp, DestinationPort);
  UdpConnection.println("A wireless hello");
  UdpConnection.endPacket();

  // Send data for plotting
  UdpConnection.beginPacket(DestinationIp, DestinationPort);
  TimePlot Plot("ADC", UdpConnection);
  Plot.SendData("A0", analogRead(A0));
  UdpConnection.endPacket();

  delay(500); // ms
}
