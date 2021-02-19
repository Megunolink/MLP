#include "Audio.h"

Audio::Audio(Print& rDestination)
  : MegunoLinkProtocol(F("AUDIO"), rDestination)
{
}