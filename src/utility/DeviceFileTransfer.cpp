#include "DeviceFileTransfer.h"

DeviceFileTransfer::DeviceFileTransfer(Print& rDestination /*= Serial*/)
  : MegunoLinkProtocol(F("DFT"), rDestination)
{

}

void DeviceFileTransfer::SendFileInfo(const char* pchFilename, size_t szFileLength, time_t ttLastModified)
{
  SendDataHeader(F("FE"));
  m_rDestination.print(pchFilename);
  m_rDestination.print('|');
  m_rDestination.print(szFileLength);
  m_rDestination.print('|');
  m_rDestination.print(ttLastModified);
  SendDataTail();
}
