#pragma once
#define __PROG_TYPES_COMPAT__
#include <Arduino.h>
#include "CommandParameter.h"

namespace MLP
{
  struct CommandCallback 
  {
    const char *m_strCommand PROGMEM;
    void (*m_Callback)(CommandParameter &rParameters);
  };

  class CommandDispatcherBase
  {
    // Array of up to m_uMaxCommands we can match & dispatch. 
    CommandCallback *const m_pCommands;
    const uint8_t m_uMaxCommands;
    uint8_t m_uLastCommand;

    // Handler called (if not null) when no command matches. 
    void (*m_fnDefaultHandler)();

  protected:
    CommandDispatcherBase(CommandCallback *pCallbackBuffer, uint8_t uCallbackBufferLength);

  public:
    bool AddCommand(const __FlashStringHelper *pCommand, void(*CallbackFunction)(CommandParameter &rParameters));
    void SetDefaultHandler(void(*CallbackFunction)());
    void ClearCommands();

    void DispatchCommand(char *pchMessage, Print& rSource) const;

  protected:
    enum EConstants { NO_MATCH = 0 };
    uint8_t MatchCommand(PROGMEM const char *pchCommand, const char *pchTest) const;
  };
}