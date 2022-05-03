#include <stdint.h>
#include "CRC.h"

#if defined(__AVR__)

#include <util/crc16.h>

#else

// Backup CRC algorithm where not supported by native library. For compatibility with AVR
// checksum implementation: https://www.nongnu.org/avr-libc/user-manual/group__util__crc.html#ga95371c87f25b0a2497d9cba13190847f 
uint16_t _crc16_update(uint16_t crc, uint8_t data)
{
  int i;
  crc ^= data;
  for (i = 0; i < 8; ++i)
  {
    if (crc & 1)
      crc = (crc >> 1) ^ 0xA001;
    else
      crc = (crc >> 1);
  }
  return crc;
}

#endif

uint16_t CalculateChecksum(uint8_t const* pData, uint16_t uLength, uint16_t uSeed /*= 0xffff*/)
{
  uint16_t uChecksum = uSeed;
  while (uLength--)
  {
    uChecksum = _crc16_update(uChecksum, *pData++);
  }
  return uChecksum;
}

uint16_t CalculateChecksum(uint8_t uData, uint16_t uSeed)
{
  return _crc16_update(uSeed, uData);
}
