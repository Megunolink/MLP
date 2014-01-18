#include "Map.h"


Map::Map()
  : MegunoLinkProtocol(F("MAP"))
{
}


void Map::SendData(const char *Placename, const char *Latitude, const char *Longitude)
{
  SendDataHeader(F("SET"));
  Serial.print(Placename);
  Serial.print('|');
  Serial.print(Latitude);
  Serial.print('|');
  Serial.print(Longitude);
  SendDataTail();
}

void Map::SendData(const __FlashStringHelper *Placename, const char *Latitude, const char *Longitude)
{
  SendDataHeader(F("SET"));
  Serial.print(Placename);
  Serial.print('|');
  Serial.print(Latitude);
  Serial.print('|');
  Serial.print(Longitude);
  SendDataTail();
}

void Map::SendData(const char *Placename, float Latitude, float Longitude)
{
  SendDataHeader(F("SET"));
  Serial.print(Placename);
  Serial.print('|');
  Serial.print(Latitude);
  Serial.print('|');
  Serial.print(Longitude);
  SendDataTail();
}

void Map::SendData(const __FlashStringHelper *Placename, float Latitude, float Longitude)
{
  SendDataHeader(F("SET"));
  Serial.print(Placename);
  Serial.print('|');
  Serial.print(Latitude);
  Serial.print('|');
  Serial.print(Longitude);
  SendDataTail();
}

