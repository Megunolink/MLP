/* ***********************************************************************
*  FixedStringBuffer
*  Modelled off PString but Mikal Hart
*  http://arduiniana.org/libraries/pstring/
*  *********************************************************************** */
#pragma once

#include <Arduino.h>


class FixedStringPrint : public Print
{
private:
  // start of buffer that we are writing to
  char* m_pchBuffer;

  // Maximum buffer size. 
  size_t m_szBuffer;

  // Next location in buffer to write to
  char* m_pchNext;

  // True if we've tried to write more than can fit in the buffer. 
  bool m_bBufferFlow;
public:

  FixedStringPrint(char* pchBuffer, size_t  szBuffer);

  void begin();

  inline size_t length() const
  {
    return m_pchNext - m_pchBuffer;
  }

  inline size_t available() const
  {
    return capacity() - length();
  }

  inline size_t capacity() const
  {
    return m_szBuffer;
  }

  bool operator==(char const* pchTest) const
  {
    return m_szBuffer > 0 && strcmp(m_pchBuffer, pchTest) == 0;
  }

  inline operator char const* () const
  {
    return m_pchBuffer;
  }

  inline char const* c_str() const
  {
    return m_pchBuffer;
  }

  template<class T> inline FixedStringPrint& operator=(T value)
  {
    begin(); 
    print(value);
    return *this;
  }

  template<class T> inline FixedStringPrint& operator+=(T value)
  {
    print(value);
    return *this;
  }

  size_t write(uint8_t uValue) override;

  bool IsOverflow() const { return m_bBufferFlow; }
};


template<int nBufferSize> class FixedStringBuffer : public FixedStringPrint
{
private:
  char m_achBuffer[nBufferSize];

public:
  FixedStringBuffer() : FixedStringPrint(m_achBuffer, sizeof(m_achBuffer))
  {
  }
};