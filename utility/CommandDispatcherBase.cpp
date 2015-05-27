#include "CommandDispatcherBase.h"
#include <avr/pgmspace.h>

using namespace MLP;


CommandDispatcherBase::CommandDispatcherBase( CommandCallback *pCallbackBuffer, uint8_t uCallbackBufferLength )
  : m_uMaxCommands(uCallbackBufferLength), m_pCommands(pCallbackBuffer)
{
  m_uLastCommand = 0;
  m_fnDefaultHandler = NULL;
}

bool CommandDispatcherBase::AddCommand( const __FlashStringHelper *pCommand, void(*CallbackFunction)(CommandParameter &rParameters) )
{
  if (m_uLastCommand < m_uMaxCommands)
  {
    m_pCommands[m_uLastCommand].m_Callback = CallbackFunction;
    m_pCommands[m_uLastCommand].m_strCommand = (PROGMEM const char* )pCommand;
    ++m_uLastCommand;
    return true;
  }

#if defined(DEBUG)
  Serial.println(F("CommandDispatcherBase::AddCommand: No space for command"));
#endif

  return false; // too many commands stored already. 
}

void CommandDispatcherBase::SetDefaultHandler( void(*CallbackFunction)() )
{
  m_fnDefaultHandler = CallbackFunction;
}

void CommandDispatcherBase::ClearCommands()
{
  m_uLastCommand = 0;
}

void CommandDispatcherBase::DispatchCommand( char *pchMessage, Print &rSource ) const
{
  uint8_t uCommand, uParameterStart;
  CommandCallback *pCommand;

  uCommand = m_uLastCommand;
  pCommand = m_pCommands;
  while(uCommand--)
  {
    uParameterStart = MatchCommand(pCommand->m_strCommand, pchMessage);

    if (uParameterStart != NO_MATCH)
    {
      CommandParameter Parameters(rSource, pchMessage, uParameterStart);
      pCommand->m_Callback(Parameters);
      return;
    }

    ++pCommand;
  }

  // No command matched. 
  if (m_fnDefaultHandler != NULL)
    (*m_fnDefaultHandler)();
}

uint8_t CommandDispatcherBase::MatchCommand( PROGMEM const char *pchCommand, const char *pchTest ) const
{
  char chCommand, chTest;
  uint8_t uParameterStart = 0;
  do 
  {
    chCommand = pgm_read_byte_near(pchCommand++);
    chTest = *pchTest++;
    ++uParameterStart;
  } while (chCommand == chTest && chCommand != '\0' && (chTest != ' ' || chTest != '\0'));

  if (chCommand == '\0' && (chTest == ' ' || chTest == '\0'))
    return uParameterStart;

  return NO_MATCH; // No match. 
}

