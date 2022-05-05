#pragma once
#include "MegunoLinkProtocol.h"
#include <time.h>
#include <Stream.h>

class DeviceFileTransfer : public MegunoLinkProtocol
{
public:
  DeviceFileTransfer(Print& rDestination = Serial);

  void SendFileInfo(const char* pchFilepath, uint32_t uFileLength, time_t ttLastModified);
  void SendFileBytes(const char* pchFilepath, uint32_t nFirstByte, uint8_t* pData, uint16_t uLength, bool bMore);
  void SendFileBytes(const char* pchFilePath, Stream& rSource, uint32_t uCurrentPosition, uint16_t uMaxLength);

  void FileReceiveResult(const char* pchFilePath, uint32_t uStartAddress, int16_t nReceived);

  void FileDeleteResult(const char* pchFilePath, bool bSuccess);
  void AllFilesDeleted(uint16_t uRequestId, bool bSuccess);
};

