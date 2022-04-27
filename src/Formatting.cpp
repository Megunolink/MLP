/* ***********************************************************************
*  Format helpers for outputing values.
*  Base 64 translation based on:
*    https://github.com/Densaugeo/base64_arduino/blob/master/src/base64.hpp
*  *********************************************************************** */
#include "Formatting.h"

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

void WriteBase64(Print& rDestination, uint8_t* pData, uint16_t Length)
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
