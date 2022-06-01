#include "UdpManager.h"

UdpManager::UdpManager(UDP &rConnection, uint16_t uListenPort, uint16_t uDestinationPort)
  : m_uListenPort(uListenPort)
  , m_rConnection(rConnection)
{
  m_uDefaultDestinationPort = uDestinationPort == 0 ? uListenPort : uDestinationPort;
  SetDefaultDestinationToBroadcast();
}

bool UdpManager::OnNetworkConnected()
{
  if (!m_rConnection.begin(m_uListenPort))
  {
    Serial.println(F("ERR: UDP listen"));
    return false; 
  }

  return true; 
}

void UdpManager::OnNetworkConnectionLost()
{
  m_rConnection.stop();
}

void UdpManager::SetDefaultDestinationPort(uint16_t uDestinationPort)
{
  m_uDefaultDestinationPort = uDestinationPort;
}

void UdpManager::SetDefaultDestination(IPAddress DestinationAddress, uint16_t uDestinationPort)
{
  m_DefaultDestinationAddress = DestinationAddress;
  if (uDestinationPort != 0)
  {
    m_uDefaultDestinationPort = uDestinationPort;
  }
}

void UdpManager::SetDefaultDestinationToBroadcast()
{
  m_DefaultDestinationAddress = IPAddress(255, 255, 255, 255);
}

bool UdpManager::SendBlock(const char* pchData, size_t szLength)
{
  return SendBlock(pchData, szLength, m_DefaultDestinationAddress, m_uDefaultDestinationPort);
}

bool UdpManager::SendBlock(const char* pchData, size_t szLength, IPAddress DestinationAddress, uint16_t uDestinationPort)
{
  if ((uint32_t)DestinationAddress == 0)
  {
    DestinationAddress = m_DefaultDestinationAddress;
  }

  if (uDestinationPort == 0)
  {
    uDestinationPort = m_uDefaultDestinationPort;
  }

  if (!m_rConnection.beginPacket(DestinationAddress, uDestinationPort))
  {
    return false; 
  }

  if (m_rConnection.write((uint8_t*)pchData, szLength) != szLength)
  {
    return false;
  }

  return m_rConnection.endPacket() != 0; 
}
