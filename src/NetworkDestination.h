#pragma once

#include <IPAddress.h>

class INetworkDestination
{
public:
  virtual bool SendBlock(const char* pchData, size_t szLength, IPAddress ipDestination, uint16_t uPort = 0) = 0;
};

class IStreamDestination
{
public:
  virtual bool SendBlock(const char* pchData, size_t szLength) = 0;
};