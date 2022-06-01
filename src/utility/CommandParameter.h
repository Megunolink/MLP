#pragma once
#include <Arduino.h>
#include <IPAddress.h>

class CommandParameter
{
  // Buffer of parameters. As we work through each one, it gets null terminated. 
  char *m_pchBuffer;

  // Offset to next parameter in buffer. 
  uint8_t m_uNextParameter; 

  // Sender address, if this command was sent from an IP address
  // and we know the remote address. Null otherwise. 
  IPAddress* m_pSender;

public:
  CommandParameter(Print &rSourceStream, char *pchBuffer, uint8_t nFirstParameter, IPAddress* pSender = nullptr);

  // The stream that the parameter came from (for replies, for example)
  Print& Response;
  Print& GetSource() { return Response; }

  const char *NextParameter();
  const char *RemainingParameters();

  int NextParameterAsInteger(int nDefault = -1);
  long NextParameterAsLong(long nDefault = -1);
  unsigned long NextParameterAsUnsignedLong(unsigned long nDefault = -1);
  double NextParameterAsDouble(double fDefault = 0.0);

  uint8_t NextParameterAsU8FromHex(uint8_t uDefault = 0);
  uint16_t NextParameterAsU16FromHex(uint16_t uDefault = 0);
  uint32_t NextParameterAsU32FromHex(uint32_t uDefault = 0);

  bool GetSenderAddress(IPAddress& rAddress);

private:
  uint8_t HexValueOf(char ch);
};

