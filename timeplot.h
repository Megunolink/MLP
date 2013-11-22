#pragma once
#include <Arduino.h>


namespace timeplot
{


  //Timeplot Plotting
  //void Send(String channelName, String seriesName, float value, String plotProperties);
  //void Send(String channelName, String seriesName, unsigned long value, String plotProperties);
  //void Send(String channelName, String seriesName, double value, String plotProperties);
  //void Send(String channelName, String seriesName, byte value, String plotProperties);
  //void Send(String channelName, String seriesName, int value, String plotProperties);
  //void Title(String channelName, String title);
  //void Xlabel(String channelName, String xlabel);
  //void Ylabel(String channelName, String ylabel);
  void Title(String channelName, String title)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|set|title=");
    Serial.print(title);
    Serial.println("}");
  }

  void Xlabel(String channelName, String xlabel)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|set|x-label=");
    Serial.print(xlabel);
    Serial.println("}");
  }

  void Ylabel(String channelName, String ylabel)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|set|y-label=");
    Serial.print(ylabel);
    Serial.println("}");
  }

  template<class T> void Send(String channelName, String seriesName, T value, String plotProperties)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print(":");
    Serial.print(plotProperties);
    Serial.print("|T|");
    Serial.print(value);
    Serial.println("}");
  }


  template<> void Send<float>(String channelName, String seriesName, float value, String plotProperties)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print(":");
    Serial.print(plotProperties);
    Serial.print("|T|");
    Serial.print(value,3);
    Serial.println("}");
  }


  template<class T> void Send(String channelName, String seriesName, T value)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print("|T|");
    Serial.print(value);
    Serial.println("}");
  }


  template<> void Send<float>(String channelName, String seriesName, float value)
  {
    Serial.print("{TIMEPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print("|T|");
    Serial.print(value,3);
    Serial.println("}");
  }


};
