#pragma once
#include <Udp.h>
#include "MLPMsgBuffer.h"

namespace MLP
{
  class UdpResponseStream : public MLPMsgDestination
  {
  private:

    UDP & m_rConnection;
    bool m_bStartedPacket;

    IPAddress m_ipDestinationAddress;
    uint16_t m_uDestinationPort;

    const static int BufferSize = 128;
    char m_achBuffer[BufferSize];

  public:
    UdpResponseStream(UDP& rConnection, IPAddress ipDestinationAddress, uint16_t uDestinationPort);

    virtual void flush() override;

    void EndTransmission();
  };

} // namespace MLP
