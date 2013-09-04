#pragma once
#include <Arduino.h>


class table
{


public:
  table();


  //Table Functions
  void Send(String name, float value, String description);
  void Send(String name, double value, String description);
  void Send(String name, int value, String description);
  void Send(String name, byte value, String description);
  void Clear();
  void ClearEntry(String name);
  void GetEntry(String name);

};

