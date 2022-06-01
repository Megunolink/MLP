#include "CommandParameter.h"

CommandParameter::CommandParameter(Print &rSourceStream, char *pchBuffer, uint8_t uFirstParameter, IPAddress* pSender)
  : Response(rSourceStream)
{
  m_pchBuffer = pchBuffer;
  m_uNextParameter = uFirstParameter;
  m_pSender = pSender;
}

const char *CommandParameter::NextParameter()
{
  if (m_pchBuffer[m_uNextParameter] == '\0')
    return NULL;

  // Null terminate the next parameter
  char *pchParameter = m_pchBuffer + m_uNextParameter;
  char *pchEnd = pchParameter;
  while (*pchEnd != ' ' && *pchEnd != '\0')
  {
    ++pchEnd;
    ++m_uNextParameter;
  }

  if (*pchEnd != '\0')
  {
    ++m_uNextParameter;
    *pchEnd = '\0';
  }

  return pchParameter;
}

const char * CommandParameter::RemainingParameters()
{
  return m_pchBuffer + m_uNextParameter;
}

int CommandParameter::NextParameterAsInteger( int nDefault /*= -1*/ )
{
  const char *pchParameter = NextParameter();
  if (pchParameter == NULL)
    return nDefault;

  return atoi(pchParameter);
}

long CommandParameter::NextParameterAsLong( long nDefault /*= -1*/ )
{
  const char *pchParameter = NextParameter();
  if (pchParameter == NULL)
    return nDefault;

  return atol(pchParameter);
}

unsigned long CommandParameter::NextParameterAsUnsignedLong( unsigned long nDefault /*= -1*/ )
{
  const char *pchParameter = NextParameter();
  if (pchParameter == NULL)
    return nDefault;

  return strtoul(pchParameter, NULL, 10);
}

double CommandParameter::NextParameterAsDouble( double fDefault /*= 0.0*/ )
{
  const char *pchParameter = NextParameter();
  if (pchParameter == NULL)
    return fDefault;

  return atof(pchParameter);
}

uint8_t CommandParameter::NextParameterAsU8FromHex(uint8_t uDefault)
{
  return NextParameterAsU32FromHex(uDefault) & 0xff;
}

uint16_t CommandParameter::NextParameterAsU16FromHex(uint16_t uDefault)
{
  return NextParameterAsU32FromHex(uDefault) & 0xffff;
}

uint32_t CommandParameter::NextParameterAsU32FromHex(uint32_t uDefault)
{
  const char* pchParameter = NextParameter();
  if (pchParameter == NULL)
    return uDefault;
  uint32_t uValue = 0; 
  while (*pchParameter != '\0')
  {
    uValue = (uValue << 4) | HexValueOf(*pchParameter++);
  }

  return uValue;
}

bool CommandParameter::GetSenderAddress(IPAddress& rAddress)
{
  if (m_pSender != nullptr)
  {
    rAddress = *m_pSender;
  }
  return m_pSender != nullptr;
}

uint8_t CommandParameter::HexValueOf(char ch)
{
  if (ch >= '0' && ch <= '9')
  {
    return ch - '0';
  }

  if (ch >= 'a' && ch <= 'f')
  {
    return ch - 'a' + 10;
  }

  if (ch >= 'A' && ch <= 'F')
  {
    return ch - 'A' + 10;
  }

  return 0;
}