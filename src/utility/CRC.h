#pragma once

uint16_t _crc16_update(uint16_t crc, uint8_t data);
uint16_t CalculateChecksum(uint8_t* pData, uint16_t uLength, uint16_t uSeed = 0xffff);
