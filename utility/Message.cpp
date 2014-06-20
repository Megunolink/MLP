#include "message.h"

Message::Message( const char *channelName /*= NULL*/, Print &rDestination  )
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
{

}

Message::Message( const __FlashStringHelper *channelName, Print &rDestination )
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
{

}

void Message::Begin()
{
  SendDataHeader(F("DATA"));
}

void Message::End()
{
  SendDataTail();
}

void Message::Send( const char *Message )
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(Message);
  SendDataTail();
}

void Message::Send( const __FlashStringHelper *Message )
{
  SendDataHeader(F("DATA"));
  m_rDestination.print(Message);
  SendDataTail();
}

void Message::Clear()
{
  SendDataHeader(F("CLEAR"));
  SendDataTail();
}




