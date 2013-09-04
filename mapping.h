#pragma once
#include <Arduino.h>


class mapping
{


public:
  mapping();


  //Table Functions
  void Table(String name, float value, String description);
  void Table(String name, double value, String description);
  void Table(String name, int value, String description);
  void Table(String name, byte value, String description);
  void ClearTable();
  void ClearTableEntry(String name);
  void GetTableEntry(String name);

  //Timeplot Plotting
  void TimePlot(String channelName, String seriesName, float value);
  void TimePlot(String channelName, String seriesName, unsigned long value);
  void TimePlot(String channelName, String seriesName, double value);
  void TimePlot(String channelName, String seriesName, byte value);
  void TimePlot(String channelName, String seriesName, int value);
  void TimePlotTitle(String channelName, String title);
  void TimePlotXlabel(String channelName, String xlabel);
  void TimePlotYlabel(String channelName, String ylabel);

};

