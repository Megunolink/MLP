#pragma once

#include <Arduino.h>
#include <Stream.h>
#include <WiFi.h>

#include "StreamParser.h"

namespace MLP
{
  template<int CP_SERIAL_BUFFER_SIZE = 30>
  class TCPConnection
    : public MLP::StreamParser
  {
    // Buffer for data received.
    char m_achBuffer[CP_SERIAL_BUFFER_SIZE];

  public:
    TCPConnection()
      : MLP::StreamParser(m_achBuffer, CP_SERIAL_BUFFER_SIZE)
    {
    }

    void Init(MLP::CommandDispatcherBase &rCommandHandler, char chStartOfMessage = '!', char chEndOfMessage = '\r')
    {
      Reset();
      m_pCommandHandler = &rCommandHandler;
      m_chStartOfMessage = chStartOfMessage;
      m_chEndOfMessage = chEndOfMessage;
      m_pSource = NULL;
    }


    void SetStream(Stream *pStream)
    {
      m_pSource = pStream;
      Reset();
    }

    WiFiClient m_Client;
  };
}

