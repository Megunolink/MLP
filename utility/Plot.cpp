#include "Plot.h"

Plot::Plot( const __FlashStringHelper *Context )
  : MegunoLinkProtocol(Context)
{

}

Plot::Plot( const __FlashStringHelper *Context, const char *Channel )
  : MegunoLinkProtocol(Context, Channel)
{

}

Plot::Plot( const __FlashStringHelper *Context, const __FlashStringHelper *Channel )
  : MegunoLinkProtocol(Context, Channel)
{

}

void Plot::SetTitle(const char *title)
{
  SetParameter(F("title"), title);
}

void Plot::SetXlabel(const char *xlabel)
{
  SetParameter(F("x-label"), xlabel);
}

void Plot::SetYlabel(const char *ylabel)
{
  SetParameter(F("y-label"), ylabel);
}

void Plot::SetTitle(const __FlashStringHelper *title)
{
  SetParameter(F("title"), title);
}

void Plot::SetXlabel(const __FlashStringHelper *xlabel)
{
  SetParameter(F("x-label"), xlabel);
}

void Plot::SetYlabel(const __FlashStringHelper *ylabel)
{
  SetParameter(F("y-label"), ylabel);
}

void Plot::SetSeriesProperties(const char *SeriesName, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker )
{
  char Data[5] = {':', Color, Marker, Line, '\0'};

  SendDataHeader(F("STYLE"));
  Serial.print(SeriesName);
  Serial.print(Data);
  Serial.print(uLineWidth);
  SendDataTail();
}

void Plot::SetSeriesProperties(const __FlashStringHelper *SeriesName, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker )
{
  char Data[5] = {':', Color, Marker, Line, '\0'};

  SendDataHeader(F("STYLE"));
  Serial.print(SeriesName);
  Serial.print(Data);
  Serial.print(uLineWidth);
  SendDataTail();
}

void Plot::SetSeriesProperties(const char *SeriesName, const char *SeriesProperties )
{
  SendDataHeader(F("STYLE"));
  Serial.print(SeriesName);
  Serial.print(':');
  Serial.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetSeriesProperties(const __FlashStringHelper *SeriesName, const char *SeriesProperties )
{
  SendDataHeader(F("STYLE"));
  Serial.print(SeriesName);
  Serial.print(':');
  Serial.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetSeriesProperties(const __FlashStringHelper *SeriesName, const __FlashStringHelper *SeriesProperties )
{
  SendDataHeader(F("STYLE"));
  Serial.print(SeriesName);
  Serial.print(':');
  Serial.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetParameter(const __FlashStringHelper *pfstrParameter, const char * Value )
{
  SendDataHeader(F("SET"));
  Serial.print(pfstrParameter);
  Serial.print('=');
  Serial.print(Value);
  SendDataTail();
}

void Plot::SetParameter( const __FlashStringHelper *pfstrParameter, const __FlashStringHelper * Value )
{
  SendDataHeader(F("SET"));
  Serial.print(pfstrParameter);
  Serial.print('=');
  Serial.print(Value);
  SendDataTail();
}

void Plot::SendSeriesProperties( const char *SeriesProperties )
{
  if (SeriesProperties != NULL)
  {
    Serial.print(':');
    Serial.print(SeriesProperties);
  }
  Serial.print('|');
}

void Plot::SendSeriesProperties( const __FlashStringHelper *SeriesProperties )
{
  if (SeriesProperties != NULL)
  {
    Serial.print(':');
    Serial.print(SeriesProperties);
  }
  Serial.print('|');
}

void Plot::SendSeriesProperties( Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker )
{
  char Data[5] = {':', Color, Marker, Line, '\0'};

  Serial.print(Data);
  Serial.print(uLineWidth);
  Serial.print('|');
}

