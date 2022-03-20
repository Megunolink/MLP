/* ***********************************************************************
*  MegunoLinkBufferWrapper
*  Provides a mechanism to access MegunoLink classes that send commands
*  and data to visualizers from a shared destination. 
*  *********************************************************************** */

#pragma once
#include "Print.h"
#include "MegunoLink.h"


class MegunoLinkBufferWrapper 
{
private:
  Print& m_rDestinationBuffer;

public:
  MegunoLinkBufferWrapper(Print* pDestinationBuffer);

  TimePlot GetTimePlot(__FlashStringHelper const* channelName);
  TimePlot GetTimePlot(char const* channelName);
  TimePlot GetTimePlot();

  XYPlot GetXYPlot(__FlashStringHelper const* channelName);
  XYPlot GetXYPlot(char const* channelName);
  XYPlot GetXYPlot();

  InterfacePanel GetInterfacePanel(__FlashStringHelper const* channelName);
  InterfacePanel GetInterfacePanel(char const* channelName);
  InterfacePanel GetInterfacePanel();

  Map GetMap(__FlashStringHelper const* channelName);
  Map GetMap(char const* channelName);
  Map GetMap();

  Message GetMessage(__FlashStringHelper const* channelName);
  Message GetMessage(char const* channelName);
  Message GetMessage();

  Table GetTable(__FlashStringHelper const* channelName);
  Table GetTable(char const* channelName);
  Table GetTable();

  RecordTable GetRecordTable(__FlashStringHelper const* channelName);
  RecordTable GetRecordTable(char const* channelName);
  RecordTable GetRecordTable();

  Monkey GetMonkey(__FlashStringHelper const* channelName);
  Monkey GetMonkey(char const* channelName);
  Monkey GetMonkey();

  Report GetReport();
  Audio GetAudio();
  Pushover GetPushover();

};