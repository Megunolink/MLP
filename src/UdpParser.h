#pragma once

#include "CommandDispatcherBase.h"
#include "Udp.h"
#include "ArduinoTimer.h"
#include "BlockParser.h"

namespace MLP
{
  class UdpParser : protected BlockParser
  {
  protected:

    // The commands to dispatch messages to.     
    CommandDispatcherBase& m_rDispatcher;

    // Object responsible for sending and receiving UdpPackets. 
    UDP& m_rConnection;

    // A buffer to collect commands. 
    char * const m_pchBuffer;

    // Size of m_pchBuffer [bytes].
    const size_t m_szMaxBufferSize;

    // Timer to perioidcally check for network packets. 
    ::ArduinoTimer m_tmrPacketCheck;
    
    // Interval between checking for new packets. 
    const unsigned PacketCheckInterval = 10; // ms

  public:
    UdpParser(MLP::CommandDispatcherBase& rDispatcher, char* pchReceiveBuffer, size_t szReceiveBuffer, UDP& rConnection);

    void Process();

  private:
  };
} // namespace MLP
