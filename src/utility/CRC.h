#pragma once

uint16_t CalculateChecksum(uint8_t const* pData, uint16_t uLength, uint16_t uSeed = 0xffff);
uint16_t CalculateChecksum(uint8_t uData, uint16_t uSeed = 0xffff);
