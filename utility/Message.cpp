#include "Message.h"

Message::Message(const char *channelName /*= NULL*/, Print &rDestination)
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
  , m_Destination(Text)
{

}

Message::Message(MessageDestination Destination, const char *channelName /*= NULL*/, Print &rDestination)
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
  , m_Destination(Destination)
{

}

Message::Message(const __FlashStringHelper *channelName, Print &rDestination)
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
  , m_Destination(Text)
{

}

Message::Message(const __FlashStringHelper *channelName, MessageDestination Destination, Print &rDestination)
  : MegunoLinkProtocol(F("MESSAGE"), channelName, rDestination)
  , m_Destination(Destination)
{

}

void Message::Begin()
{
  switch (m_Destination)
  {
  case Text:
    SendDataHeader(F("DATA"));
    break;
  case Speak:
    SendDataHeader(F("SPEAK"));
    break;
  case TextAndSpeak:
    SendDataHeader(F("SPEAK+DATA"));
    break;
  }
}

void Message::End()
{
  SendDataTail();
}

void Message::Send( const char *Message )
{
  Begin();
  m_rDestination.print(Message);
  SendDataTail();
}

void Message::Send( const __FlashStringHelper *Message )
{
  Begin();
  m_rDestination.print(Message);
  SendDataTail();
}

void Message::Clear()
{
  SendDataHeader(F("CLEAR"));
  SendDataTail();
}

void Message::SendSeparator()
{
  m_rDestination.print(F(": "));
}


