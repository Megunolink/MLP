#include "UdpResponseStream.h"
#include <Arduino.h>

using namespace MLP;

UdpResponseStream::UdpResponseStream(UDP &rConnection, IPAddress ipDestinationAddress, uint16_t uDestinationPort)
  : MLPMsgDestination(m_achBuffer, sizeof(m_achBuffer)) 
  , m_rConnection(rConnection)
  
{
  m_bStartedPacket = false; 
  m_ipDestinationAddress = ipDestinationAddress;
  m_uDestinationPort = uDestinationPort;
}

void UdpResponseStream::flush()
{
  if (length() > 0)
  {
    if (!m_bStartedPacket)
    {
      m_rConnection.beginPacket(m_ipDestinationAddress, m_uDestinationPort);
      m_bStartedPacket = true; 
    }

    m_rConnection.write((uint8_t*)c_str(), length());
  }
}

void UdpResponseStream::EndTransmission()
{
  flush();
  
  if (m_bStartedPacket)
  {
    m_rConnection.endPacket();
  }
}
