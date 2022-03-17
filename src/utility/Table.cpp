#include "Table.h"

Table::Table(Print& rDestination /*= Serial*/)
  : MegunoLinkProtocol(F("PT"), rDestination)
{

}

Table::Table(const char *Channel, Print &rDestination /*= Serial*/)
  : MegunoLinkProtocol(F("PT"), Channel, rDestination)
{

}

Table::Table(const __FlashStringHelper *Channel, Print &rDestination /*= Serial*/)
  : MegunoLinkProtocol(F("PT"), Channel, rDestination)
{

}

void Table::ClearAllRows()
{
  SendDataHeader(F("CLR"));
  SendDataTail();
}

