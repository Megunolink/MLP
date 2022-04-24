#pragma once
#include "MegunoLinkProtocol.h"
#include <time.h>

class DeviceFileTransfer : public MegunoLinkProtocol
{
public:
  DeviceFileTransfer(Print& rDestination = Serial);

  void SendFileInfo(const char* pchFilename, size_t szFileLength, time_t ttLastModified);
};

