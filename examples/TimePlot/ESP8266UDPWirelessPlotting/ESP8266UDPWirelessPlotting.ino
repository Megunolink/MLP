/************************************************************************************************
In this example, data is sent from an ESP8266 wifi module over UDP to MegunoLink where it is 
plotted in real time. The example uses the UDP broadcast address so it doesn't need to know
the IP address of the computer running MegunoLink. Open the ESP8266UDPWirelessPlotting interface
in MegunoLink to view the data. You'll find it inside the same folder as this Arduino code.

More Information
  * Getting started with MegunoLink: https://www.megunolink.com/documentation/getting-started/
  * Creating UDP connections: https://www.megunolink.com/documentation/connecting/udp-connections/
  * Plotting reference: http://www.megunolink.com/documentation/plotting/

This Example Requires:
  * The MegunoLink arduino library https://www.megunolink.com/documentation/arduino-integration/
  * The ESP8266 arduino library and files https://github.com/esp8266/Arduino

You can find out more about MegunoLink and download a free trial from here
  * https://www.megunolink.com/
  * https://www.megunolink.com/download/
************************************************************************************************/

#include "ESP8266WiFi.h"
#include "WiFiUdp.h"

#include "MegunoLink.h"
#include "ArduinoTimer.h"

// Setup WiFi credentials (SSID and password). 
#define USE_WIFI_CONFIG_FILE // Comment out this line to use Option 2 below
#ifdef USE_WIFI_CONFIG_FILE

// Include SSID and password from a library file. See:
// https://www.megunolink.com/articles/wireless/how-do-i-connect-to-a-wireless-network-with-the-esp32/
#include "WiFiConfig.h"

#else

// Option 2
const char *SSID = "Your SSID";
const char *WiFiPassword = "Your Password";

#endif

// Use the broadcast address for the destination computer
// running MegunoLink so we don't have to know its
// IP address/name.
const IPAddress DestinationIp(255, 255, 255, 255);
const int SourcePort = 52790;
const int DestinationPort = 52791;

WiFiUDP UdpConnection;
ArduinoTimer SendTimer;

void setup()
{
  Serial.begin(9600);
  Serial.println("UDP Plotting Test");

  // Setup the WiFi connection, waiting until it is ready. 
  WiFi.begin(SSID, WiFiPassword);
  auto Result = WiFi.waitForConnectResult();
  if (Result == WL_CONNECTED)
  {
    Serial.print(F("Connected. My IP address: "));
    Serial.println(WiFi.localIP());
    UdpConnection.begin(SourcePort);
  }
  else
  {
    Serial.print(F("Couldn't connect to WiFi. Error: "));
    switch(Result)
    {
      case WL_NO_SHIELD: Serial.println(F("No wifi shield")); break;
      case WL_NO_SSID_AVAIL: Serial.print(F("SSID not found-")); Serial.println(SSID); break;
      case WL_CONNECT_FAILED: Serial.print(F("connect failed")); break;
      case WL_CONNECTION_LOST: Serial.print(F("connection lost")); break;
      default: Serial.println(Result); break;
    }
  }
}

void loop()
{
  // Periodically send data when the connection is available. 
  if (WiFi.isConnected() && SendTimer.TimePassed_Milliseconds(400))
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
  }
}
