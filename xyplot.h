#pragma once
#include <Arduino.h>


namespace xyplot
{


  void Title(String channelName, String title)
  {
    Serial.print("{XYPLOT:");
    Serial.print(channelName);
    Serial.print("|set|title=");
    Serial.print(title);
    Serial.println("}");
  }

  void Xlabel(String channelName, String xlabel)
  {
    Serial.print("{XYPLOT:");
    Serial.print(channelName);
    Serial.print("|set|x-label=");
    Serial.print(xlabel);
    Serial.println("}");
  }

  void Ylabel(String channelName, String ylabel)
  {
    Serial.print("{XYPLOT:");
    Serial.print(channelName);
    Serial.print("|set|y-label=");
    Serial.print(ylabel);
    Serial.println("}");
  }




  template<class T, class M> void Send(String channelName, String seriesName, T xValue, M yValue)
  {
    Serial.print("{XYPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print("|");
    Serial.print(xValue);
    Serial.print("|");
    Serial.print(yValue);
    Serial.println("}");
  }

  //template<> void Send<float,float>(String channelName, String seriesName, float xValue, float yValue)
  //{
  //  Serial.print("{XYPLOT:");
  //  Serial.print(channelName);
  //  Serial.print("|data|");
  //  Serial.print(seriesName);
  //  Serial.print("|");
  //  Serial.print(xValue,3);
  //  Serial.print("|");
  //  Serial.print(yValue,3);
  //  Serial.println("}");
  //}

  template<class T, class M> void Send(String channelName, String seriesName, T xValue, M yValue, String plotProperties)
  {
    Serial.print("{XYPLOT:");
    Serial.print(channelName);
    Serial.print("|data|");
    Serial.print(seriesName);
    Serial.print(":");
    Serial.print(plotProperties);
    Serial.print("|");
    Serial.print(xValue);
    Serial.print("|");
    Serial.print(yValue);
    Serial.println("}");
  }

  //template<> void Send<float,float>(String channelName, String seriesName, float xValue, float yValue, String plotProperties)
  //{
  //  Serial.print("{XYPLOT:");
  //  Serial.print(channelName);
  //  Serial.print("|data|");
  //  Serial.print(seriesName);
  //  Serial.print(":");
  //  Serial.print(plotProperties);
  //  Serial.print("|");
  //  Serial.print(xValue,3);
  //  Serial.print("|");
  //  Serial.print(yValue,3);
  //  Serial.println("}");
  //}


};
