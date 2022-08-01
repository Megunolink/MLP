#include "UdpParser.h"
#include "PrintBuffer.h"
#include "UdpResponseStream.h"

using namespace MLP;

UdpParser::UdpParser(MLP::CommandDispatcherBase &rDispatcher, char *pchReceiveBuffer, size_t szReceiveBuffer, UDP& rConnection)
    : m_rDispatcher(rDispatcher), m_rConnection(rConnection), m_pchBuffer(pchReceiveBuffer), m_szMaxBufferSize(szReceiveBuffer)
{
}

void UdpParser::Process()
{
  if (m_tmrPacketCheck.TimePassed_Milliseconds(PacketCheckInterval))
  {
    int nAvailable = m_rConnection.parsePacket();
    if (nAvailable > 0)
    {
      if (nAvailable <= (int)m_szMaxBufferSize)
      {
        char *pchCommand = m_pchBuffer;
        int nCommandLength = m_rConnection.read(pchCommand, m_szMaxBufferSize - 1);
        if (nCommandLength > 0 && FindCommand(pchCommand, nCommandLength))
        {
          IPAddress ipSource = m_rConnection.remoteIP();
          UdpResponseStream Response(m_rConnection, ipSource, m_rConnection.remotePort());
          m_rDispatcher.DispatchCommand(pchCommand, Response, &ipSource);
          Response.EndTransmission();
        }
      }
      else
      {
        Serial.println(F("Err: Udp Ovflw"));
        // read and discard; buffer is too small to process.
        while (nAvailable-- > 0)
        {
          m_rConnection.read();
        }
      }
    }
  }
}

