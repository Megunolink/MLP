#include "DeviceFileTransfer.h"
#include "CRC.h"
#include "../Formatting.h"

DeviceFileTransfer::DeviceFileTransfer(Print& rDestination /*= Serial*/)
  : MegunoLinkProtocol(F("DFT"), rDestination)
{

}

void DeviceFileTransfer::SendFileInfo(const char* pchFilepath, uint32_t uFileLength, time_t ttLastModified)
{
  SendDataHeader(F("FE"));
  m_rDestination.print(pchFilepath);
  m_rDestination.print('|');
  m_rDestination.print(uFileLength);
  m_rDestination.print('|');

  // Arduino's print method doesn't overload printing for 64 bit integers. 
  // 32 bit value of time_t is good to 2038, so just cast for now. 
  m_rDestination.print((long)ttLastModified);
  SendDataTail();
}

void DeviceFileTransfer::SendFileBytes(const char* pchFilePath, uint32_t nFirstByte, uint8_t* pData, uint16_t uLength, bool bMore)
{
  uint16_t uChecksum = CalculateChecksum(pData, uLength);

  SendDataHeader(F("FD"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print(nFirstByte, HEX);
  m_rDestination.print('|');
  EncodeAsBase64(m_rDestination, pData, uLength);
  m_rDestination.print('|');
  m_rDestination.print(uChecksum, HEX);
  m_rDestination.print('|');
  m_rDestination.print(bMore ? '+' : 'x');
  SendDataTail();
}

void DeviceFileTransfer::SendFileBytes(const char* pchFilePath, Stream& rSource, uint32_t uCurrentPosition, uint16_t uMaxLength)
{
  SendDataHeader(F("FD"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print(uCurrentPosition, HEX);
  m_rDestination.print('|');

  const uint16_t uBufferSize = 66; // must be a multiple of 3. 
  uint8_t abyData[uBufferSize];
  bool bMore = true; 
  uint16_t uChecksum = 0xffff;
  while (uMaxLength && bMore)
  {
    uint16_t nMaxRead = uMaxLength;
    if (nMaxRead > uBufferSize)
    {
      nMaxRead = uBufferSize;
    }
    uint16_t nActualRead = rSource.readBytes(abyData, nMaxRead);
    EncodeAsBase64(m_rDestination, abyData, nActualRead);
    uChecksum = CalculateChecksum(abyData, nActualRead, uChecksum);
    uMaxLength -= nActualRead;
    bMore = nActualRead == nMaxRead;
  }
  m_rDestination.print('|');
  m_rDestination.print(uChecksum, HEX);
  m_rDestination.print('|');
  m_rDestination.print(bMore ? '+' : 'x');
  SendDataTail();
}

void DeviceFileTransfer::SendFileBytes(const char* pchFilePath, uint32_t uCurrentPosition, DFTResult Result)
{
  SendDataHeader(F("FDe"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print(uCurrentPosition, HEX);
  m_rDestination.print('|');
  m_rDestination.print((char)Result);
  SendDataTail();
}


void DeviceFileTransfer::FileDeleteResult(const char* pchFilePath, DFTResult Result)
{
  SendDataHeader(F("FX"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print((char)Result);
  SendDataTail();
}

void DeviceFileTransfer::AllFilesDeleted(uint16_t uRequestId, DFTResult Result)
{
  SendDataHeader(F("FXX"));
  m_rDestination.print(uRequestId);
  m_rDestination.print('|');
  m_rDestination.print((char)Result);
  SendDataTail();
}

void DeviceFileTransfer::FileReceiveResult(const char* pchFilePath, uint32_t uStartAddress, int16_t nReceived, DFTResult Result)
{
  uint16_t uChecksum = CalculateChecksum(nReceived >> 8);
  uChecksum = CalculateChecksum(nReceived & 0xff, uChecksum);
  uChecksum = CalculateChecksum((uStartAddress >> 24) & 0xff, uChecksum);
  uChecksum = CalculateChecksum((uStartAddress >> 16) & 0xff, uChecksum);
  uChecksum = CalculateChecksum((uStartAddress >> 8) & 0xff, uChecksum);
  uChecksum = CalculateChecksum((uStartAddress >> 0) & 0xff, uChecksum);

  SendDataHeader(F("FR"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print(uStartAddress, HEX);
  m_rDestination.print('|');
  m_rDestination.print(nReceived, HEX);
  m_rDestination.print('|');
  m_rDestination.print(uChecksum, HEX);
  m_rDestination.print('|');
  m_rDestination.print((char)Result);
  SendDataTail();
}

void DeviceFileTransfer::SendError(DFTResult Result, char chOperation, const char* pchFilePath, uint32_t uContext)
{
  SendDataHeader(F("ERR"));
  m_rDestination.print((char)Result);
  m_rDestination.print('|');
  m_rDestination.print(uContext, HEX);
  if (pchFilePath != nullptr)
  {
    m_rDestination.print('|');
    m_rDestination.print(pchFilePath);
  }
  SendDataTail();
}

void DeviceFileTransfer::ReportSDMountFailed()
{
  SendError(DFTResult::SDMountFailed, 'i');
}

void DeviceFileTransfer::ReportCardMissing()
{
  SendError(DFTResult::SDCardMissing, 'i');
}
