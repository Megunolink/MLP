#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include <Stream.h>

#include "utility/CommandDispatcherBase.h"
#include "utility/StreamParser.h"

template <int MAX_COMMANDS = 10, int CP_SERIAL_BUFFER_SIZE = 30> class CommandHandler : public MLP::CommandDispatcherBase, public MLP::StreamParser
{
  // Array of commands we can match & dispatch. 
  MLP::CommandCallback m_Commands[MAX_COMMANDS];

  // Buffer for data received.
  char m_achBuffer[CP_SERIAL_BUFFER_SIZE];

public:

  CommandHandler(Stream &rSourceStream = Serial, char chStartOfMessage = '!', char chEndOfMessage = '\r')
    : CommandDispatcherBase(m_Commands, MAX_COMMANDS)
    , StreamParser(*(static_cast<MLP::CommandDispatcherBase *>(this)), m_achBuffer, sizeof(m_achBuffer), rSourceStream, chStartOfMessage, chEndOfMessage)
  {
  }
};
