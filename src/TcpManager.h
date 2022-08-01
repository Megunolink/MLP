/* ***********************************************************************
 *  TcpManager
 *  Maintains Tcp connections
 *  *********************************************************************** */
#pragma once

#include <Arduino.h>
#include <Client.h>

class ITcpManager
{
public:
  virtual Client& GetConnection() = 0;
};