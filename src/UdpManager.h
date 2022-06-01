/* ***********************************************************************
 *  UdpManager
 *  Maintains Udp connection
 *  *********************************************************************** */
#pragma once

#include <Arduino.h>
#include <Udp.h>

#include "NetworkDestination.h"

class UdpManager : public INetworkDestination
{
private:
  const uint16_t m_uListenPort;

  UDP &m_rConnection;

  IPAddress m_DefaultDestinationAddress;
  uint16_t m_uDefaultDestinationPort;

protected:
  UdpManager(UDP &rConnection, uint16_t uListenPort, uint16_t uDestinationPort = 0);

public:
  bool OnNetworkConnected();
  void OnNetworkConnectionLost();

  // Placeholder to maintain a consistent interface. 
  void Process() {}

  void SetDefaultDestinationPort(uint16_t uDestinationPort);
  void SetDefaultDestination(IPAddress DestinationAddress, uint16_t uDestinationPort = 0);
  void SetDefaultDestinationToBroadcast();

  bool SendBlock(const char* pchData, size_t szLength);
  virtual bool SendBlock(const char* pchData, size_t szLength, IPAddress DestinationAddress, uint16_t uDestinationPort = 0) override;

  UDP& GetConnection() { return m_rConnection; }
};

