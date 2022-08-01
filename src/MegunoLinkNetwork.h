#pragma once

#include "MegunoLink.h"
#include "MLPMsgBuffer.h"
#include "MegunoLinkBufferWrapper.h"

#include "NetworkDestination.h"

class MegunoLinkNetwork : public MLPMsgDestination, public MegunoLinkBufferWrapper
{
protected:
  INetworkDestination* m_pAddressedDestination;
  IStreamDestination* m_pStreamDestination;

  const static int BufferSize = 128;
  char m_achTransmitBuffer[BufferSize];

  IPAddress m_ipDestination;
  uint16_t m_uDestinationPort;

public:
  MegunoLinkNetwork(INetworkDestination& rDestination);
  MegunoLinkNetwork(IStreamDestination& rDestination);

  void SetDestination(IPAddress DestinationAddress, uint16_t uDestinationPort = 0);

  virtual void flush() override;
};