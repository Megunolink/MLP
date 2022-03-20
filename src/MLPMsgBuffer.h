/* ***********************************************************************
*  MLPMsgDestination
*  Implements a buffer for MegunoLink messages for block transports such
*  as Mqtt and Tcp. The message is assembled in a, fixed-size, internal
*  buffer and sent on new-line (or when the buffer is full).  
*  *********************************************************************** */

#pragma once
#include "Print.h"

class MLPMsgDestination : public Print
{
protected:

  // Buffer that we are writing to. Buffer should
  // be large enough to hold the biggest message we'll send. 
  static const int nBufferSize = 128;
  char m_achBuffer[nBufferSize];

  // Next location in buffer to write to
  char* m_pchNext;

public:

  MLPMsgDestination();

  void begin();

  inline size_t length() const
  {
    return m_pchNext - m_achBuffer;
  }

  inline size_t available() const
  {
    return capacity() - length();
  }

  inline size_t capacity() const
  {
    return sizeof(m_achBuffer);
  }

  inline char const* c_str() const
  {
    return m_achBuffer;
  }

  size_t write(uint8_t uValue) override;

  virtual void flush() {}
};
