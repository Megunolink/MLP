#include "PlotHelpers.h"

namespace MLPPlotHelpers
{
  void SetParameter(const char * channelName, const char * Value, const __FlashStringHelper *pfstrParameter, const __FlashStringHelper *pPlotType)
  {
    Serial.print('{');
    Serial.print(pPlotType);
    Serial.print(':');
    Serial.print(channelName);
    Serial.print(F("|set|"));
    Serial.print(pfstrParameter);
    Serial.print('=');
    Serial.print(Value);
    Serial.println("}");
  }

  void SendDataHeader( const __FlashStringHelper *pPlotType, const char * channelName, const char * seriesName, const char * SeriesProperties /*= NULL*/ )
  {

    Serial.print('{');
    Serial.print(pPlotType);
    Serial.print(':');
    Serial.print(channelName);
    Serial.print(F("|data|"));
    Serial.print(seriesName);

    if (SeriesProperties != NULL)
    {
      Serial.print(':');
      Serial.print(SeriesProperties);
    }

    Serial.print('|');
  }

  void SendDataTail()
  {
    Serial.println('}');
  }


}