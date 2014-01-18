#include "message.h"

Message::Message( const char *channelName /*= NULL*/ )
  : MegunoLinkProtocol(F("MESSAGE"), channelName)
{

}

Message::Message( const __FlashStringHelper *channelName )
  : MegunoLinkProtocol(F("XYPLOT"), channelName)
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
  Serial.print(Message);
  SendDataTail();
}

void Message::Send( const __FlashStringHelper *Message )
{
  SendDataHeader(F("DATA"));
  Serial.print(Message);
  SendDataTail();
}



