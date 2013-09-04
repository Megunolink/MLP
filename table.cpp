#include "table.h"

table::table()
{

}

//Table Functions
void table::Send(String name, float value, String description)
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

void table::Send(String name, double value, String description)
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

void table::Send(String name, int value, String description)
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

void table::Send(String name, byte value, String description)
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

void table::Clear()
{
  Serial.print("{TABLE");
  Serial.println("|CLEAR}");
}

void table::ClearEntry(String name)
{
  Serial.print("{TABLE");
  Serial.print("|CLEAR|");
  Serial.print(name);
  Serial.println("}");
}

void table::GetEntry(String name)
{
  Serial.print("{TABLE");
  Serial.print("|GET|");
  Serial.print(name);
  Serial.println("}");
}