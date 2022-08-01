#include "MegunoLinkNetwork.h"

MegunoLinkNetwork::MegunoLinkNetwork(INetworkDestination& rDestination)
  : MLPMsgDestination(m_achTransmitBuffer, BufferSize)
  , MegunoLinkBufferWrapper(this)
  , m_pAddressedDestination(&rDestination)
  , m_pStreamDestination(nullptr)
{
  m_uDestinationPort = 0; 
}

MegunoLinkNetwork::MegunoLinkNetwork(IStreamDestination& rDestination)
  : MLPMsgDestination(m_achTransmitBuffer, BufferSize)
  , MegunoLinkBufferWrapper(this)
  , m_pAddressedDestination(nullptr)
  , m_pStreamDestination(&rDestination)
{
  m_uDestinationPort = 0; 
}

void MegunoLinkNetwork::SetDestination(IPAddress DestinationAddress, uint16_t uDestinationPort)
{
  m_ipDestination = DestinationAddress;
  m_uDestinationPort = uDestinationPort;
}

void MegunoLinkNetwork::flush()
{
  if (m_pAddressedDestination != nullptr)
  {
    m_pAddressedDestination->SendBlock(c_str(), length(), m_ipDestination, m_uDestinationPort);
  }
  if (m_pStreamDestination != nullptr)
  {
    m_pStreamDestination->SendBlock(c_str(), length());
  }
}
