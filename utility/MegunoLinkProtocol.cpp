#include "MegunoLinkProtocol.h"



MegunoLinkProtocol::MegunoLinkProtocol( const __FlashStringHelper *Context )
  : m_pfchContext((const prog_char*)Context), m_bFlashString(false)
{
}

MegunoLinkProtocol::MegunoLinkProtocol( const __FlashStringHelper *Context, const char *Channel )
  : m_pfchContext((const prog_char*)Context), m_bFlashString(false), m_ChannelName(Channel)
{

}

MegunoLinkProtocol::MegunoLinkProtocol( const __FlashStringHelper *Context, const __FlashStringHelper *Channel )
  : m_pfchContext((const prog_char*)Context), m_bFlashString(true), m_ChannelName((const prog_char*)Channel)
{
}

void MegunoLinkProtocol::SendDataHeader(const __FlashStringHelper *pfstrCommand)
{
  Serial.print('{');
  Serial.print((const __FlashStringHelper *) m_pfchContext);
  if (m_ChannelName != NULL)
  {
    Serial.print(':');
    if (m_bFlashString)
    {
      Serial.print((const __FlashStringHelper *)m_ChannelName);
    }
    else
    {
      Serial.print((const char *)m_ChannelName);
    }
  }
  Serial.print('|');
  Serial.print(pfstrCommand);
  Serial.print('|');
}

void MegunoLinkProtocol::SendDataTail()
{
  Serial.println('}');
}
