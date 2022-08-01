 /* *****************************************************************
 *  Extension point for command dispatcher to implement modules with
 *  sets of commands that can be linked to command handling. 
 *  ***************************************************************** */
#pragma once

#include <Arduino.h>
#include "utility/CommandParameter.h"

namespace MLP
{
  class CommandModule
  {
  public:
    CommandModule(const __FlashStringHelper* pName);
    PGM_P const Command;
    CommandModule* NextModule;

    virtual void DispatchCommand(CommandParameter& p) = 0;
  };

}