#pragma once
#include "MegunoLinkProtocol.h"
#include <time.h>
#include <Stream.h>


enum class DFTResult
{
  Ok = 'k',

  // Command isn't recognized. 
  UnknownCommand = '?',

  // Failed to open root folder either because
  // it doesn't exist or isn't a directory. 
  BadRoot = 'r',

  // Seeking a file position failed. 
  SeekFailed = 's',

  // Failed to open a file. The file might no longer
  // exist, or already be opened. 
  FileOpenFailed = 'o',

  // The address for the datablock is not at the
  // end of the target file. 
  BadDataBlockAddress = 'a',

  // A filename was too long. 
  PathTooLong = 'l',

  // Received and calculated checksum didn't match. 
  BadChecksum = '#',

  // Bad base-64 data received. 
  BadData = '6',

  // File deletion is not permitted.
  FileDeleteDisabled = 'x',

  // Delete all files is disabled. 
  DeleteAllDisabled = 'f',

  // Failed to delete file requested. 
  DeleteFileFailed = 'e',

  // Unable to mount the SD card.
  SDMountFailed = 'm',

  // SD Card missing
  SDCardMissing = 'c',
};

class DeviceFileTransfer : public MegunoLinkProtocol
{
public:
  DeviceFileTransfer(Print& rDestination = Serial);

  void SendFileInfo(const char* pchFilepath, uint32_t uFileLength, time_t ttLastModified);
  void SendFileBytes(const char* pchFilepath, uint32_t nFirstByte, uint8_t* pData, uint16_t uLength, bool bMore);
  void SendFileBytes(const char* pchFilePath, Stream& rSource, uint32_t uCurrentPosition, uint16_t uMaxLength);
  void SendFileBytes(const char* pchFilePath, uint32_t uCurrentPosition, DFTResult Result);

  void FileReceiveResult(const char* pchFilePath, uint32_t uStartAddress, int16_t nReceived, DFTResult Result);

  void FileDeleteResult(const char* pchFilePath, DFTResult Result);
  void AllFilesDeleted(uint16_t uRequestId, DFTResult Result);

  void ReportSDMountFailed();
  void ReportCardMissing();

  void SendError(DFTResult ErrorCode, char chOperation, const char* pchFilePath = nullptr, uint32_t uContext = 0);
};
