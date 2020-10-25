#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>

class MegunoLinkProtocol
{
  const char * const m_pfchContext;

  const void *m_ChannelName;
  const bool m_bFlashString;

protected:
  Print &m_rDestination;

protected:
  MegunoLinkProtocol(const __FlashStringHelper *Context);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const char *Channel);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const __FlashStringHelper *Channel);

  MegunoLinkProtocol(const __FlashStringHelper *Context, Print &rDestination);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const char *Channel, Print &rDestination);
  MegunoLinkProtocol(const __FlashStringHelper *Context, const __FlashStringHelper *Channel, Print &rDestination);

  MegunoLinkProtocol(const char* Context);
  MegunoLinkProtocol(const char* Context, const char* Channel);
  MegunoLinkProtocol(const char* Context, const __FlashStringHelper* Channel);

  MegunoLinkProtocol(const char* Context, Print& rDestination);
  MegunoLinkProtocol(const char* Context, const char* Channel, Print& rDestination);
  MegunoLinkProtocol(const char* Context, const __FlashStringHelper* Channel, Print& rDestination);


  void SendDataHeader(const __FlashStringHelper* pfstrCommand);
  void SendDataHeader(const char *pfstrCommand);
  void SendDataTail();

public:
  void Attach(Print& rDestination);

};

