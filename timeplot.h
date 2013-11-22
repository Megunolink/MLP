#pragma once
#include <Arduino.h>


class timeplot
{


public:
  timeplot();

  //Timeplot Plotting
  void Send(String channelName, String seriesName, float value, String plotProperties);
  void Send(String channelName, String seriesName, unsigned long value, String plotProperties);
  void Send(String channelName, String seriesName, double value, String plotProperties);
  void Send(String channelName, String seriesName, byte value, String plotProperties);
  void Send(String channelName, String seriesName, int value, String plotProperties);
  void Title(String channelName, String title);
  void Xlabel(String channelName, String xlabel);
  void Ylabel(String channelName, String ylabel);

};

