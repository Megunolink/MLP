/* ***********************************************************************
*  Format helpers for outputing values. 
*  *********************************************************************** */
#pragma once

#include "Print.h"

#if !defined(typeof)
#define typeof(x) __typeof__(x)
#endif

#define AsHex(x) AsHexWrapper<typeof(x)>(x)


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
