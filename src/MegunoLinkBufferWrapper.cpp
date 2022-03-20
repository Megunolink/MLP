#include "MegunoLinkBufferWrapper.h"

MegunoLinkBufferWrapper::MegunoLinkBufferWrapper(Print* pDestinationBuffer)
  : m_rDestinationBuffer(*pDestinationBuffer)
{
}

TimePlot MegunoLinkBufferWrapper::GetTimePlot(__FlashStringHelper const* channelName)
{
  return TimePlot(channelName, m_rDestinationBuffer);
}

TimePlot MegunoLinkBufferWrapper::GetTimePlot(char const* channelName)
{
  return TimePlot(channelName, m_rDestinationBuffer);
}

TimePlot MegunoLinkBufferWrapper::GetTimePlot()
{
  return TimePlot(m_rDestinationBuffer);
}

XYPlot MegunoLinkBufferWrapper::GetXYPlot(__FlashStringHelper const* channelName)
{
  return XYPlot(channelName, m_rDestinationBuffer);
}

XYPlot MegunoLinkBufferWrapper::GetXYPlot(char const* channelName)
{
  return XYPlot(channelName, m_rDestinationBuffer);
}

XYPlot MegunoLinkBufferWrapper::GetXYPlot()
{
  return XYPlot(m_rDestinationBuffer);
}

InterfacePanel MegunoLinkBufferWrapper::GetInterfacePanel(__FlashStringHelper const* channelName)
{
  return InterfacePanel(channelName, m_rDestinationBuffer);
}

InterfacePanel MegunoLinkBufferWrapper::GetInterfacePanel(char const* channelName)
{
  return InterfacePanel(channelName, m_rDestinationBuffer);
}

InterfacePanel MegunoLinkBufferWrapper::GetInterfacePanel()
{
  return InterfacePanel(m_rDestinationBuffer);
}

Map MegunoLinkBufferWrapper::GetMap(__FlashStringHelper const* channelName)
{
  return Map(channelName, m_rDestinationBuffer);
}

Map MegunoLinkBufferWrapper::GetMap(char const* channelName)
{
  return Map(channelName, m_rDestinationBuffer);
}

Map MegunoLinkBufferWrapper::GetMap()
{
  return Map(m_rDestinationBuffer);
}

Message MegunoLinkBufferWrapper::GetMessage(__FlashStringHelper const* channelName)
{
  return Message(channelName, m_rDestinationBuffer);
}

Message MegunoLinkBufferWrapper::GetMessage(char const* channelName)
{
  return Message(channelName, m_rDestinationBuffer);
}

Message MegunoLinkBufferWrapper::GetMessage()
{
  return Message(m_rDestinationBuffer);
}

Table MegunoLinkBufferWrapper::GetTable(__FlashStringHelper const* channelName)
{
  return Table(channelName, m_rDestinationBuffer);
}

Table MegunoLinkBufferWrapper::GetTable(char const* channelName)
{
  return Table(channelName, m_rDestinationBuffer);
}

Table MegunoLinkBufferWrapper::GetTable()
{
  return Table(m_rDestinationBuffer);
}

RecordTable MegunoLinkBufferWrapper::GetRecordTable(__FlashStringHelper const* channelName)
{
  return RecordTable(channelName, m_rDestinationBuffer);
}

RecordTable MegunoLinkBufferWrapper::GetRecordTable(char const* channelName)
{
  return RecordTable(channelName, m_rDestinationBuffer);
}

RecordTable MegunoLinkBufferWrapper::GetRecordTable()
{
  return RecordTable(m_rDestinationBuffer);
}

Monkey MegunoLinkBufferWrapper::GetMonkey(__FlashStringHelper const* channelName)
{
  return Monkey(channelName, m_rDestinationBuffer);
}

Monkey MegunoLinkBufferWrapper::GetMonkey(char const* channelName)
{
  return Monkey(channelName, m_rDestinationBuffer);
}

Monkey MegunoLinkBufferWrapper::GetMonkey()
{
  return Monkey(m_rDestinationBuffer);
}

Report MegunoLinkBufferWrapper::GetReport()
{
  return Report(m_rDestinationBuffer);
}

Audio MegunoLinkBufferWrapper::GetAudio()
{
  return Audio(m_rDestinationBuffer);
}

Pushover MegunoLinkBufferWrapper::GetPushover()
{
  return Pushover(m_rDestinationBuffer);
}
