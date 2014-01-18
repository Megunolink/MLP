#pragma once
#include <Arduino.h>

class MegunoLinkProtocol
{
  const void *m_ChannelName;
  const bool m_bFlashString;

  const prog_char * const m_pfchContext;

protected:
  MegunoLinkProtocol(const __FlashStringHelper *Context);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const char *Channel);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const __FlashStringHelper *Channel);

  void SendDataHeader(const __FlashStringHelper *pfstrCommand);
  void SendDataTail();

};

