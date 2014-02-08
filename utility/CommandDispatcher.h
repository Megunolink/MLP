#pragma once

#include "CommandDispatcherBase.h"

template<int MAX_COMMANDS = 10> class CommandDispatcher : public MLP::CommandDispatcherBase
{
  // Array of commands we can match & dispatch. 
  MLP::CommandCallback m_Commands[MAX_COMMANDS];

public:
  CommandDispatcher() : CommandDispatcherBase(m_Commands, MAX_COMMANDS)
  {
  }
};