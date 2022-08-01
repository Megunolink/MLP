/* ***********************************************************************
*  Buffers output to an object supporting the Print interface. 
*  Writes are stored in a RAM buffer and sent when the internal buffer is 
*  full, a new-line is encountered or when flush is called directly. 
*  *********************************************************************** */

#include "MLPMsgBuffer.h"

namespace MLP
{
  template<int BufferSize = 128>
  class PrintBuffer : public MLPMsgDestination
  {
  protected:
    char m_achBuffer[BufferSize];

    Print& m_rDestination;

  public:
    PrintBuffer(Print& rDestination) 
      : MLPMsgDestination(m_achBuffer, sizeof(m_achBuffer))
      , m_rDestination(rDestination)
    {

    }

    virtual void flush() override
    {
      m_rDestination.write(c_str(), length());
      begin();
    }
    
  };

} // namespace MLP
