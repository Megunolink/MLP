#pragma once
#include <Arduino.h>


class timeplot
{


public:
  timeplot();

  //Timeplot Plotting
  void Send(String channelName, String seriesName, float value);
  void Send(String channelName, String seriesName, unsigned long value);
  void Send(String channelName, String seriesName, double value);
  void Send(String channelName, String seriesName, byte value);
  void Send(String channelName, String seriesName, int value);
  void Title(String channelName, String title);
  void Xlabel(String channelName, String xlabel);
  void Ylabel(String channelName, String ylabel);

};

