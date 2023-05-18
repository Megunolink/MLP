/* ***********************************************************************
*  Format helpers for outputing values. 
*  *********************************************************************** */
#pragma once

#include <Arduino.h>

#if !defined(typeof)
#define typeof(x) __typeof__(x)
#endif

#define AsHex(x) AsHexWrapper<typeof(x)>(x)
#define WithPrecision(x, p) WithPrecisionWrapper<typeof(x)>(x, p)

template<typename TValue>
class AsHexWrapper : public Printable
{
private:
  TValue m_Value;

public:

  AsHexWrapper(TValue Value)
    : m_Value(Value)
  {
  }

  virtual size_t printTo(Print& p) const override
  {
    return p.print(m_Value, HEX);
  }
};

template<typename TValue>
class WithPrecisionWrapper : public Printable
{
private:
  TValue m_Value;
  uint8_t m_uPrecision;

public:
  WithPrecisionWrapper(TValue Value, uint8_t uPrecision)
  {
    m_Value = Value;
    m_uPrecision = uPrecision;
  }

  virtual size_t printTo(Print& p) const override
  {
    return p.print(m_Value, m_uPrecision);
  }
};


#define DECODE_BAD_DATA -1
int DecodeFromBase64(Print& rDestination, const char* pchData);
uint16_t CalculateChecksumFromBase64(const char* pchData);

void EncodeAsBase64(Print& rDestination, const uint8_t* pData, uint16_t Length);

void WriteHex(Print& rDestination, uint8_t uValue);
void WriteHex(Print& rDestination, uint16_t uValue);
void WriteHex(Print& rDestination, uint32_t uValue);

