#include "table.h"


Table::Table(Print &rDestination)
  : MegunoLinkProtocol(F("TABLE"), rDestination)
{

}

void Table::SetDescription(const char *RowName, const char *Description)
{
  SendDataHeader(F("DESCRIPTION"));
  m_rDestination.print(RowName);
  m_rDestination.print('|');
  m_rDestination.print(Description);
  SendDataTail();
}

void Table::SetDescription(const __FlashStringHelper *RowName, const char *Description)
{
  SendDataHeader(F("DESCRIPTION"));
  m_rDestination.print(RowName);
  m_rDestination.print('|');
  m_rDestination.print(Description);
  SendDataTail();
}

void Table::SetDescription(const __FlashStringHelper *RowName, const __FlashStringHelper *Description)
{
  SendDataHeader(F("DESCRIPTION"));
  m_rDestination.print(RowName);
  m_rDestination.print('|');
  m_rDestination.print(Description);
  SendDataTail();
}

void Table::ClearAllRows()
{
  SendDataHeader(F("CLEAR"));
  SendDataTail();
}

void Table::ClearRow(const char *Name)
{
  SendDataHeader(F("CLEAR"));
  m_rDestination.print(Name);
  SendDataTail();
}

void Table::ClearRow(const __FlashStringHelper *Name)
{
  SendDataHeader(F("CLEAR"));
  m_rDestination.print(Name);
  SendDataTail();
}

void Table::GetData(const char *Name)
{
  SendDataHeader(F("GET"));
  m_rDestination.print(Name);
  SendDataTail();
}

void Table::GetData(const __FlashStringHelper *Name)
{
  SendDataHeader(F("GET"));
  m_rDestination.print(Name);
  SendDataTail();
}
