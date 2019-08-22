#pragma once
#define __PROG_TYPES_COMPAT__
#include "MegunoLinkProtocol.h"

class Map : public MegunoLinkProtocol
{
public:
  Map(Print &rDestination = Serial);

  void SendData(const char *Placename, const char *Latitude, const char *Longitude);
  void SendData(const __FlashStringHelper *Placename, const char *Latitude, const char *Longitude);

  void SendData(const char *Placename, float Latitude, float Longitude);
  void SendData(const __FlashStringHelper *Placename, float Latitude, float Longitude);
};

