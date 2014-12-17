#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include "CommandDispatcherBase.h"

namespace MLP
{
  class StreamParser
  {
    // The stream that we are parsing for commands. 
    Stream &m_rSource;

    // A buffer to collect commands. Buffer, and size, is provided. 
    char * const m_pchBuffer;
    const unsigned m_uMaxBufferSize;

    // Index where next character will be placed in the buffer. 
    unsigned m_uNextCharacter;

    // True iff an overflow has occured. Commands will not
    // be dispatched from buffers that overflow. 
    bool m_bOverflow;

    // Characters that signal start and end of message. 
    // The buffer is reset when a start character is received. Commands
    // are dispatched when the end character is received. 
    const char m_chStartOfMessage, m_chEndOfMessage;

    MLP::CommandDispatcherBase &m_rCommandHandler;

  protected:
    StreamParser(MLP::CommandDispatcherBase &rCommandHandler, char *pchReceiveBuffer, unsigned uBufferSize, 
      Stream &rSourceStream = Serial, char chStartOfMessage = '!', char chEndOfMessage = '\r');

    void Init();  
    void DispatchMessage();

  public:
    void Process();
    void Reset(); 
  };
}
