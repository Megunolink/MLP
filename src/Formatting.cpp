/* ***********************************************************************
*  Format helpers for outputing values.
*  Base 64 translation based on:
*    https://github.com/Densaugeo/base64_arduino/blob/master/src/base64.hpp
*  *********************************************************************** */
#include "Formatting.h"
#include "utility/CRC.h"

char binary_to_base64(uint8_t v)
{
  // Capital letters - 'A' is ascii 65 and base64 0
  if (v < 26) return v + 'A';

  // Lowercase letters - 'a' is ascii 97 and base64 26
  if (v < 52) return v + 71;

  // Digits - '0' is ascii 48 and base64 52
  if (v < 62) return v - 4;

  // '+' is ascii 43 and base64 62
  if (v == 62) return '+';

  // '/' is ascii 47 and base64 63
  if (v == 63) return '/';

  return 64;
}

uint8_t base64_to_binary(unsigned char c) {
  // Capital letters - 'A' is ascii 65 and base64 0
  if ('A' <= c && c <= 'Z') return c - 'A';

  // Lowercase letters - 'a' is ascii 97 and base64 26
  if ('a' <= c && c <= 'z') return c - 71;

  // Digits - '0' is ascii 48 and base64 52
  if ('0' <= c && c <= '9') return c + 4;

  // '+' is ascii 43 and base64 62
  if (c == '+') return 62;

  // '/' is ascii 47 and base64 63
  if (c == '/') return 63;

  return 255;
}

void EncodeAsBase64(Print& rDestination, const uint8_t* pData, uint16_t Length)
{
  unsigned int full_sets = Length / 3;

  // While there are still full sets of 24 bits...
  for (unsigned int i = 0; i < full_sets; ++i)
  {
    rDestination.print(binary_to_base64(pData[0] >> 2));
    rDestination.print(binary_to_base64((pData[0] & 0x03) << 4 | pData[1] >> 4));
    rDestination.print(binary_to_base64((pData[1] & 0x0F) << 2 | pData[2] >> 6));
    rDestination.print(binary_to_base64(pData[2] & 0x3F));

    pData += 3;
  }

  switch (Length % 3)
  {
  case 0:
    break;
  case 1:
    rDestination.print(binary_to_base64(pData[0] >> 2));
    rDestination.print(binary_to_base64((pData[0] & 0x03) << 4));
    rDestination.print('=');
    rDestination.print('=');
    break;
  case 2:
    rDestination.print(binary_to_base64(pData[0] >> 2));
    rDestination.print(binary_to_base64((pData[0] & 0x03) << 4 | pData[1] >> 4));
    rDestination.print(binary_to_base64((pData[1] & 0x0F) << 2));
    rDestination.print('=');
    break;
  }
}

int ToSixBits(uint8_t aBlock[4])
{
  int iBlockByte;
  for (iBlockByte = 0; iBlockByte < 4; ++iBlockByte)
  {
    uint8_t uData = aBlock[iBlockByte];
    if (uData == '=')
      break;

    if (uData >= 'A' && uData <= 'Z')
      uData -= 'A';
    else if (uData >= 'a' && uData <= 'z')
      uData = uData - 'a' + 26;
    else if (uData >= '0' && uData <= '9')
      uData = uData - '0' + 52;
    else if (uData == '+')
      uData = 62;
    else if (uData == '/')
      uData = 63;
    else
    {
      return 0; // illegal character. 
    }
    aBlock[iBlockByte] = uData;
  }

  if (iBlockByte >= 2)
  {
    aBlock[0] = aBlock[0] << 2 | ((aBlock[1] & 0x30) >> 4);
    if (iBlockByte >= 3)
    {
      aBlock[1] = (aBlock[1] & 0x0f) << 4 | ((aBlock[2] & 0x3C) >> 2);
    }
    else
    {
      return 1;
    }

    if (iBlockByte == 4)
    {
      aBlock[2] = (aBlock[2] & 0x03) << 6 | aBlock[3];
      return 3;
    }
    else
    {
      return 2;
    }
  }

  return 0; 
}

int DecodeFromBase64(Print& rDestination, const char* pchData)
{
  // Receive blocks of base-64 data into a temporary buffer. 
  // When a complete block is received, write into the message
  // buffer. 
  uint8_t aBlock[4];
  uint8_t iBlockIndex = 0;
  int nWritten = 0; 
  while (*pchData)
  {
    aBlock[iBlockIndex++] = *pchData++;
    if (iBlockIndex == 4)
    {
      int nConverted = ToSixBits(aBlock);
      if (nConverted == 0)
      {
        return DECODE_BAD_DATA;
      }
      nWritten += rDestination.write(aBlock, nConverted);
      
      iBlockIndex = 0;
    }
  }

  return nWritten;
}

uint16_t CalculateChecksumFromBase64(const char* pchData)
{
  // Receive blocks of base-64 data into a temporary buffer. 
  // When a complete block is received, update the checksum.
  uint8_t aBlock[4];
  uint8_t iBlockIndex = 0;
  uint16_t uChecksum = 0xffff;
  while (*pchData)
  {
    aBlock[iBlockIndex++] = *pchData++;
    if (iBlockIndex == 4)
    {
      int nConverted = ToSixBits(aBlock);
      if (nConverted == 0)
      {
        return 0;
      }
      uChecksum = CalculateChecksum(aBlock, nConverted, uChecksum);
      iBlockIndex = 0;
    }
  }

  return uChecksum;
}






void WriteHex(Print& rDestination, uint8_t uValue)
{
  if (uValue < 0x10)
  {
    rDestination.print('0');
  }
  rDestination.print(uValue, HEX);
}

void WriteHex(Print& rDestination, uint16_t uValue)
{
  WriteHex(rDestination, (uint8_t)(uValue >> 8));
  WriteHex(rDestination, (uint8_t)(uValue & 0xff));
}

void WriteHex(Print& rDestination, uint32_t uValue)
{
  WriteHex(rDestination, (uint8_t)(uValue >> 24));
  WriteHex(rDestination, (uint8_t)(uValue >> 16));
  WriteHex(rDestination, (uint8_t)(uValue >> 8));
  WriteHex(rDestination, (uint8_t)(uValue & 0xff));
}
