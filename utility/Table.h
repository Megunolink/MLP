#pragma once
#include "MegunoLinkProtocol.h"

class Table : protected MegunoLinkProtocol
{
public:
  Table();

  template<class TValue> void SendData(const char *RowName, TValue Value, const char *Description = NULL)
  {
    SendDataHeader(F("SET"));
    Serial.print(RowName);
    Serial.print('|');
    Serial.print(Value);
    if (Description != NULL)
    {
      Serial.print('|');
      Serial.print(Description);
    }
    SendDataTail();
  }

  template<class TValue> void SendData(const __FlashStringHelper *RowName, TValue Value, const char *Description = NULL)
  {
    SendDataHeader(F("SET"));
    Serial.print(RowName);
    Serial.print('|');
    Serial.print(Value);
    if (Description != NULL)
    {
      Serial.print('|');
      Serial.print(Description);
    }
    SendDataTail();
  }

  template<class TValue> void SendData(const __FlashStringHelper *RowName, TValue Value, const __FlashStringHelper *Description)
  {
    SendDataHeader(F("SET"));
    Serial.print(RowName);
    Serial.print('|');
    Serial.print(Value);
    if (Description != NULL)
    {
      Serial.print('|');
      Serial.print(Description);
    }
    SendDataTail();
  }

  void SetDescription(const char *RowName, const char *Description);
  void SetDescription(const __FlashStringHelper *RowName, const char *Description);
  void SetDescription(const __FlashStringHelper *RowName, const __FlashStringHelper *Description);

  void ClearAllRows();
  void ClearRow(const char *RowName);
  void ClearRow(const __FlashStringHelper *RowName);

  void GetData(const char *RowName);
  void GetData(const __FlashStringHelper *RowName);
};

