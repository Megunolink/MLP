#pragma once
#include <Arduino.h>


namespace table
{

  template<class T> void Send(String name, T value, String description)
  {
    Serial.print("{TABLE");
    Serial.print("|SET|");
    Serial.print(name);
    Serial.print("|");
    Serial.print(value);
    Serial.print("|");
    Serial.print(description);
    Serial.println("}");
  }

  void Clear()
  {
    Serial.print("{TABLE");
    Serial.println("|CLEAR}");
  }

  void ClearEntry(String name)
  {
    Serial.print("{TABLE");
    Serial.print("|CLEAR|");
    Serial.print(name);
    Serial.println("}");
  }

  void GetEntry(String name)
  {
    Serial.print("{TABLE");
    Serial.print("|GET|");
    Serial.print(name);
    Serial.println("}");
  }

};

