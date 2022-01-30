#include "Monkey.h"

Monkey::Monkey(Print& rDestination)
  : MegunoLinkProtocol(F("Mky"), rDestination)
{

}

Monkey::Monkey(const char *channelName /*= NULL*/, Print &rDestination)
  : MegunoLinkProtocol(F("Mky"), channelName, rDestination)
{

}

Monkey::Monkey(const __FlashStringHelper* channelName, Print& rDestination)
  : MegunoLinkProtocol(F("Mky"), channelName, rDestination)
{

}

void Monkey::ClearTriggers()
{
  SendDataHeader(F("CLR"));
  SendDataTail();
}




