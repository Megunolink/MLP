#include "Plot.h"
#include "PlotFormat.h"

Plot::Plot( const __FlashStringHelper *Context, Print &rDestination )
  : MegunoLinkProtocol(Context, rDestination)
{

}

Plot::Plot( const __FlashStringHelper *Context, const char *Channel, Print &rDestination  )
  : MegunoLinkProtocol(Context, Channel, rDestination)
{

}

Plot::Plot( const __FlashStringHelper *Context, const __FlashStringHelper *Channel, Print &rDestination )
  : MegunoLinkProtocol(Context, Channel, rDestination)
{

}

Plot::Plot(const char* Context, Print& rDestination)
  : MegunoLinkProtocol(Context, rDestination)
{

}

Plot::Plot(const char* Context, const char* Channel, Print& rDestination)
  : MegunoLinkProtocol(Context, Channel, rDestination)
{

}

Plot::Plot(const char* Context, const __FlashStringHelper* Channel, Print& rDestination)
  : MegunoLinkProtocol(Context, Channel, rDestination)
{

}


void Plot::SetTitle(const char *title)
{
  SetParameter(F("title"), title);
}

void Plot::SetXLabel(const char *xlabel)
{
  SetParameter(F("x-label"), xlabel);
}

void Plot::SetYLabel(const char *ylabel)
{
  SetParameter(F("y-label"), ylabel);
}

void Plot::SetY2Label(const char *ylabel)
{
  SetParameter(F("y2-label"), ylabel);
}

void Plot::SetXlabel(const char *xlabel)
{
  SetXLabel(xlabel);
}

void Plot::SetYlabel(const char *ylabel)
{
  SetYLabel(ylabel);
}

void Plot::SetY2label(const char *ylabel)
{
  SetY2Label(ylabel);
}

void Plot::SetTitle(const __FlashStringHelper *title)
{
  SetParameter(F("title"), title);
}

void Plot::SetXLabel(const __FlashStringHelper *xlabel)
{
  SetParameter(F("x-label"), xlabel);
}

void Plot::SetYLabel(const __FlashStringHelper *ylabel)
{
  SetParameter(F("y-label"), ylabel);
}

void Plot::SetY2Label(const __FlashStringHelper *ylabel)
{
  SetParameter(F("y2-label"), ylabel);
}

void Plot::SetXlabel(const __FlashStringHelper *xlabel)
{
  SetXLabel(xlabel);
}

void Plot::SetYlabel(const __FlashStringHelper *ylabel)
{
  SetYLabel(ylabel);
}

void Plot::SetY2label(const __FlashStringHelper *ylabel)
{
  SetY2Label(ylabel);
}

void Plot::SetYVisible(bool bVisible)
{
  SetParameter(F("y-visible"), bVisible ? "1" : "0");
}

void Plot::SetY2Visible(bool bVisible)
{
  SetParameter(F("y2-visible"), bVisible ? "1" : "0");
}

void Plot::ShowCursor(const char* SeriesName, bool bVisible)
{
  SendDataHeader(F("C-VIS"));
  m_rDestination.print(SeriesName);
  m_rDestination.print('|');
  m_rDestination.print(bVisible ? '1' : '0');
  SendDataTail();
}

void Plot::HideCursor(const char* SeriesName)
{
  ShowCursor(SeriesName, false);
}

void Plot::ShowCursor(const __FlashStringHelper* SeriesName, bool bVisible)
{
  SendDataHeader(F("C-VIS"));
  m_rDestination.print(SeriesName);
  m_rDestination.print('|');
  m_rDestination.print(bVisible ? '1' : '0');
  SendDataTail();
}

void Plot::HideCursor(const __FlashStringHelper* SeriesName)
{
  ShowCursor(SeriesName, false);
}

void Plot::SetCursorPosition(const char* SeriesName, double dPosition, int nPrecision)
{
  SendDataHeader(F("C-POS"));
  m_rDestination.print(SeriesName);
  m_rDestination.print('|');
  m_rDestination.print(dPosition, nPrecision);
  SendDataTail();
}

void Plot::SetCursorPosition(const __FlashStringHelper* SeriesName, double dPosition, int nPrecision)
{
  SendDataHeader(F("C-POS"));
  m_rDestination.print(SeriesName);
  m_rDestination.print('|');
  m_rDestination.print(dPosition, nPrecision);
  SendDataTail();
}

void Plot::SetSeriesProperties(const char* SeriesName, const char* SeriesProperties)
{
  SendDataHeader(F("STYLE"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(':');
  m_rDestination.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetSeriesProperties(const __FlashStringHelper* SeriesName, const char* SeriesProperties)
{
  SendDataHeader(F("STYLE"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(':');
  m_rDestination.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetSeriesProperties(const __FlashStringHelper* SeriesName, const __FlashStringHelper* SeriesProperties)
{
  SendDataHeader(F("STYLE"));
  m_rDestination.print(SeriesName);
  m_rDestination.print(':');
  m_rDestination.print(SeriesProperties);
  SendDataTail();
}

void Plot::SetParameter(const __FlashStringHelper *pfstrParameter, const char * Value )
{
  SendDataHeader(F("SET"));
  m_rDestination.print(pfstrParameter);
  m_rDestination.print('=');
  m_rDestination.print(Value);
  SendDataTail();
}

void Plot::SetParameter( const __FlashStringHelper *pfstrParameter, const __FlashStringHelper * Value )
{
  SendDataHeader(F("SET"));
  m_rDestination.print(pfstrParameter);
  m_rDestination.print('=');
  m_rDestination.print(Value);
  SendDataTail();
}

void Plot::SetParameter(const char* pfstrParameter, const char* Value)
{
  SendDataHeader(F("SET"));
  m_rDestination.print(pfstrParameter);
  m_rDestination.print('=');
  m_rDestination.print(Value);
  SendDataTail();
}

void Plot::SetParameter(const char* pfstrParameter, const __FlashStringHelper* Value)
{
  SendDataHeader(F("SET"));
  m_rDestination.print(pfstrParameter);
  m_rDestination.print('=');
  m_rDestination.print(Value);
  SendDataTail();
}

void Plot::SendSeriesProperties( const char *SeriesProperties )
{
  if (SeriesProperties != NULL)
  {
    m_rDestination.print(':');
    m_rDestination.print(SeriesProperties);
  }
  m_rDestination.print('|');
}

void Plot::SendSeriesProperties( const __FlashStringHelper *SeriesProperties )
{
  if (SeriesProperties != NULL)
  {
    m_rDestination.print(':');
    m_rDestination.print(SeriesProperties);
  }
  m_rDestination.print('|');
}

void Plot::SendSeriesProperties(Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  m_rDestination.print(':');
  SendSeriesProperties(Color);
  SendSeriesProperties(Line, uLineWidth);
  SendSeriesProperties(Marker);
  SendSeriesProperties(ax);
  m_rDestination.print('|');
}

void Plot::SendSeriesProperties(const RGBColor& Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax)
{
  m_rDestination.print(':');
  SendSeriesProperties(Color);
  SendSeriesProperties(Line, uLineWidth);
  SendSeriesProperties(Marker);
  SendSeriesProperties(ax);
  m_rDestination.print('|');
}

void Plot::SendSeriesProperties(Colors color)
{
  if (color != MissingColor)
  {
    m_rDestination.print((char)color);
  }
}

void Plot::SendSeriesProperties(const RGBColor& Color)
{
  SendColorValue(Color);
}

void Plot::SendSeriesProperties(LineStyle style, uint8_t uLineWidth)
{
  if (style != MissingLineStyle)
  {
    m_rDestination.print((char)style);
    if (style != NoLine && uLineWidth > 0)
    {
      m_rDestination.print(uLineWidth);
    }
  }
}

void Plot::SendSeriesProperties(MarkerStyle style)
{
  if (style != MissingMarkerStyle)
  {
    m_rDestination.print((char)style);
  }
}

void Plot::SendSeriesProperties(Axis ax)
{
  if (ax != MissingAxis)
  {
    m_rDestination.print((char)ax);
  }
}

void Plot::SendSeriesProperties(LineFormat const& fmt)
{
  m_rDestination.print((char)fmt.Style);
  if (fmt.Style != NoLine)
  {
    m_rDestination.print(fmt.Width);
  }
}

void Plot::SendSeriesProperties(MarkerFormat const& fmt)
{
  m_rDestination.print((char)fmt.Style);
  if (fmt.Style != NoMarker)
  {
    m_rDestination.print(fmt.Size);
  }
}

void Plot::Clear()
{
  SendDataHeader(F("CLEAR"));
  SendDataTail();
}

void Plot::Clear(const char *SeriesName)
{
  SendDataHeader(F("CLEAR"));
  m_rDestination.print(SeriesName);
  SendDataTail();
}

void Plot::Clear(const __FlashStringHelper *SeriesName)
{
  SendDataHeader(F("CLEAR"));
  m_rDestination.print(SeriesName);
  SendDataTail();
}

void Plot::SendHeader_Data()
{
  SendDataHeader(F("DATA"));
}

void Plot::SendTimeSeparator()
{
  m_rDestination.print(F("T|"));
}

void Plot::SetYRange(float fYLimLower, float fYLimUpper)
{
	SendDataHeader(F("yrange"));
  SendRangeDetail(fYLimLower, fYLimUpper);
}

void Plot::SetY2Range(float fYLimLower, float fYLimUpper)
{
  SendDataHeader(F("y2range"));
  SendRangeDetail(fYLimLower, fYLimUpper);
}

void Plot::FitScale(bool bXScale, bool bYScale, bool bY2Scale)
{
  SendDataHeader(F("fit-scale"));
  if (bXScale)
  {
    m_rDestination.print('X');
  }
  if (bYScale)
  {
    m_rDestination.print('Y');
  }
  if (bY2Scale)
  {
    m_rDestination.print('W');
  }
  SendDataTail();
}


void Plot::SendRangeDetail(float fYLimLower, float fYLimUpper)
{
  m_rDestination.print(fYLimLower, 5);
  m_rDestination.print("|");
  m_rDestination.print(fYLimUpper, 5);
  SendDataTail();
}

void Plot::SendColorValue(const RGBColor& Color)
{
  char achBuffer[8];
  achBuffer[0] = '&';
  achBuffer[7] = 0;
  char* pchBuffer = achBuffer + 6;
  int32_t nColor = Color.PackedValue;
  for (int i = 0; i < 6; ++i)
  {
    char chTemp = nColor & 0x0f;
    if (chTemp < 10)
    {
      chTemp += '0';
    }
    else
    {
      chTemp += 'A' - 10;
    }
    *pchBuffer = chTemp;
    --pchBuffer;
    nColor = nColor >> 4;
  }

  m_rDestination.print(achBuffer);

}
