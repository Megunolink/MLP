/* 
  mDNSExample - 
    Based on example Transparent UART to Telnet Server for esp8266

  See: https://www.megunolink.com/documentation/connecting/mdns-browser/
  for more information

  Copyright (c) 2018 Number Eight Innovation Limited.
  Copyright (c) 2015 Hristo Gochkov. All rights reserved.
 
  This library is free software; you can redistribute it and/or
  modify it under the terms of the GNU Lesser General Public
  License as published by the Free Software Foundation; either
  version 2.1 of the License, or (at your option) any later version.

  This library is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
  Lesser General Public License for more details.

  You should have received a copy of the GNU Lesser General Public
  License along with this library; if not, write to the Free Software
  Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
*/
#include <ESP8266WiFi.h>
#include <ESP8266mDNS.h>

// Fill in your network information
const char* ssid = "ENTER SSID";
const char* password = "ENTER PASSWORD";

// Maximum number of clients that can connect to this device
#define MAX_SRV_CLIENTS 1
WiFiServer server(23);
WiFiClient serverClients[MAX_SRV_CLIENTS];

String MakeMine(const char *Template)
{
  uint16_t uChipId = ESP.getChipId();
  String Result = String(Template) + String(uChipId, HEX);
  return Result;
}

void ConnectToWiFi()
{
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);

  Serial.print("Connecting to "); Serial.println(ssid);

  uint8_t i = 0;
  while (WiFi.status() != WL_CONNECTED) 
  {
    Serial.print('.');
    delay(500);

    if ((++i % 16) == 0)
    {
      Serial.println(F(" still trying to connect"));
    }
  }

  Serial.print(F("Connected. My IP address is: "));
  Serial.println(WiFi.localIP());
}

void AdvertiseServices()
{
  String MyName = MakeMine("WiFiSensor");
  if (MDNS.begin(MyName.c_str()))
  {
    Serial.println(F("mDNS responder started"));
    Serial.print(F("My name is: "));
    Serial.println(MyName.c_str());

    // Add service to MDNS-SD
    MDNS.addService("n8i-mlp", "tcp", 23);
  }
  else
  {
    while (1) 
    {
      Serial.println(F("Error setting up MDNS responder"));
      delay(1000);
    }
  }
}

void setup()
{
  Serial.begin(115200);
  Serial.println(F("mDNS Test"));
  Serial.println(F("---------"));

  ConnectToWiFi();

  AdvertiseServices();

  // Start the TCP server
  server.begin();
  server.setNoDelay(true);
  
  Serial.println("Ready.");
}

void loop() 
{
  uint8_t i;
  // check if there are any new clients wanting to connect
  if (server.hasClient())
  {
    for(i = 0; i < MAX_SRV_CLIENTS; i++)
    {
      //find free/disconnected spot
      if (!serverClients[i] || !serverClients[i].connected())
      {
        if(serverClients[i]) serverClients[i].stop();
        serverClients[i] = server.available();
        Serial.print("New client: "); Serial.print(i);
        break;
      }
    }
    //no free/disconnected spot so reject
    if ( i == MAX_SRV_CLIENTS) 
    {
       WiFiClient serverClient = server.available();
       serverClient.stop();
       Serial.println("Connection rejected ");
    }
  }

  // check clients for data. Any data that is received is sent
  // out the local serial port. 
  for(i = 0; i < MAX_SRV_CLIENTS; i++)
  {
    if (serverClients[i] && serverClients[i].connected())
    {
      if (serverClients[i].available())
      {
        //get data from the telnet client and push it to the UART
        while (serverClients[i].available())
        {
          Serial.write(serverClients[i].read());
        }
      }
    }
  }

  // Check UART for data. Any serial data received is sent to 
  // connected TCP clients.
  if(Serial.available())
  {
    size_t len = Serial.available();
    uint8_t sbuf[len];
    Serial.readBytes(sbuf, len);
    //push UART data to all connected telnet clients
    for(i = 0; i < MAX_SRV_CLIENTS; i++)
    {
      if (serverClients[i] && serverClients[i].connected()){
        serverClients[i].write(sbuf, len);
        delay(1);
      }
    }
  }
}
