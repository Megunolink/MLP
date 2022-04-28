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
  m_rDestination.print(ttLastModified);
  SendDataTail();
}

void DeviceFileTransfer::SendFileBytes(const char* pchFilePath, uint32_t nFirstByte, uint8_t* pData, uint16_t uLength, bool bMore)
{
  uint16_t uChecksum = CalculateChecksum(pData, uLength);

  SendDataHeader(F("FD"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  WriteHex(m_rDestination, nFirstByte);
  m_rDestination.print('|');
  WriteBase64(m_rDestination, pData, uLength);
  m_rDestination.print('|');
  WriteHex(m_rDestination, uChecksum);
  m_rDestination.print('|');
  m_rDestination.print(bMore ? '+' : 'x');
  SendDataTail();
}

void DeviceFileTransfer::SendFileBytes(const char* pchFilePath, Stream& rSource, uint32_t uCurrentPosition, uint16_t uMaxLength)
{
  SendDataHeader(F("FD"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  WriteHex(m_rDestination, uCurrentPosition);
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
    WriteBase64(m_rDestination, abyData, nActualRead);
    uChecksum = CalculateChecksum(abyData, nActualRead, uChecksum);
    uMaxLength -= nActualRead;
    bMore = nActualRead == nMaxRead;
  }
  m_rDestination.print('|');
  WriteHex(m_rDestination, uChecksum);
  m_rDestination.print('|');
  m_rDestination.print(bMore ? '+' : 'x');
  SendDataTail();
}

void DeviceFileTransfer::FileDeleteResult(const char* pchFilePath, bool bSuccess)
{
  SendDataHeader(F("FX"));
  m_rDestination.print(pchFilePath);
  m_rDestination.print('|');
  m_rDestination.print(bSuccess ? 'k' : 'e');
  SendDataTail();
}

void DeviceFileTransfer::AllFilesDeleted(int nRequestId)
{
  SendDataHeader(F("FXX"));
  m_rDestination.print(nRequestId);
  SendDataTail();
}
