#include "CommandModule.h"

using namespace MLP;

CommandModule::CommandModule(const __FlashStringHelper* pName)
  : Command((PGM_P)pName)
{
  NextModule = nullptr;
}
