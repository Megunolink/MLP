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

  /// <summary>
  /// Buffer that we are writing to. Buffer should
  /// be large enough to hold the biggest message we'll send. 
  /// </summary>
  char * const m_pchStart;

  /// <summary>
  /// Size of the buffer. 
  /// </summary>
  int const m_nBufferSize;

  /// <summary>
  /// Next location in buffer to write to 
  /// </summary>
  char* m_pchNext;

public:

  MLPMsgDestination(char* pchStart, int nLength);

  void begin();

  inline size_t length() const
  {
    return m_pchNext - m_pchStart;
  }

  inline size_t available() const
  {
    return capacity() - length();
  }

  inline size_t capacity() const
  {
    return m_nBufferSize;
  }

  inline char const* c_str() const
  {
    return m_pchStart;
  }

  virtual size_t write(uint8_t uValue) override;

  virtual void flush() = 0;

  virtual void EndTransmission();
};
