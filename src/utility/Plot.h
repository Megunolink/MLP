#pragma once
#include "MegunoLinkProtocol.h"

class LineFormat;
class MarkerFormat;
class RGBColor;

class Plot : public MegunoLinkProtocol
{
public:
  enum Colors 
  { 
    Red = 'r',
    Green = 'g', 
    Blue = 'b',
    Yellow = 'y',
    Black = 'k',
    Magenta = 'm',
    Cyan = 'c',
    White = 'w',
    MissingColor = ' ',
  };

  enum LineStyle
  {
    Solid = '_',
    Dashed = '-',
    Dotted = ':',
    DashDot = ';',
    DashDotDot = '%',
    NoLine = '#',
    MissingLineStyle = ' ',
  };

  enum MarkerStyle 
  {
    Square = 's',
    Diamond = 'd',
    Triangle = '^',
    Circle = 'o',
    Cross = 'x',
    Plus = '+',
    Star = '*',
    DownwardTriangle = 'v',
    NoMarker = 'n',
    FilledSquare = 'S',
    FilledDiamond = 'D',
    FilledCircle = 'O',
    MissingMarkerStyle = ' ',
  };

  enum Axis
  {
    DefaultAxis = ' ',
    LeftAxis = '<',
    RightAxis = '>',
    MissingAxis = '0',
  };

  void SetTitle(const char *title);
  void SetXLabel(const char *xlabel);
  void SetYLabel(const char *ylabel);
  void SetY2Label(const char *ylabel);
  void SetXlabel(const char *xlabel);
  void SetYlabel(const char *ylabel);
  void SetY2label(const char *ylabel);

  void SetTitle(const __FlashStringHelper *title);
  void SetXLabel(const __FlashStringHelper *xlabel);
  void SetYLabel(const __FlashStringHelper *ylabel);
  void SetY2Label(const __FlashStringHelper *ylabel);
  void SetXlabel(const __FlashStringHelper *xlabel);
  void SetYlabel(const __FlashStringHelper *ylabel);
  void SetY2label(const __FlashStringHelper *ylabel);

  template<typename TSeriesName>
  void SetSeriesProperties(TSeriesName SeriesName, Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax = DefaultAxis)
  {
    SendDataHeader(F("STYLE"));
    m_rDestination.print(SeriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    SendDataTail();
  }

  template<typename TSeriesName>
  void SetSeriesProperties(TSeriesName SeriesName, const RGBColor &Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax = DefaultAxis)
  {
    SendDataHeader(F("STYLE"));
    m_rDestination.print(SeriesName);
    SendSeriesProperties(Color, Line, uLineWidth, Marker, ax);
    SendDataTail();
  }

  void SetSeriesProperties(const char *SeriesName, const char *SeriesProperties);
  void SetSeriesProperties(const __FlashStringHelper *SeriesName, const char *SeriesProperties);
  void SetSeriesProperties(const __FlashStringHelper *SeriesName, const __FlashStringHelper *SeriesProperties);

  void Clear();
  void Clear(const char *SeriesName);
  void Clear(const __FlashStringHelper *SeriesName);

  void SetYRange(float fYLimLower, float fYLimUpper);
  void SetY2Range(float fYLimLower, float fYLimUpper);

  void FitXScale() { FitScale(true, false, false); }
  void FitYScale() { FitScale(false, true, false); }
  void FitY2Scale() { FitScale(false, false, true); }
  void FitScale(bool bXScale, bool bYScale, bool bY2Scale);

  void SetYVisible(bool bVisible = true);
  void SetY2Visible(bool bVisible = true);

  void ShowCursor(const char* SeriesName, bool bVisible = true);
  void HideCursor(const char* SeriesName);

  void ShowCursor(const __FlashStringHelper* SeriesName, bool bVisible = true);
  void HideCursor(const __FlashStringHelper* SeriesName);

  void SetCursorPosition(const char* SeriesName, double dPosition, int nPrecision = 5);
  void SetCursorPosition(const __FlashStringHelper* SeriesName, double dPosition, int nPrecision = 5);

protected:
  Plot(const __FlashStringHelper *Context, Print &rDestination = Serial);
  Plot(const __FlashStringHelper *Context, const char *Channel, Print &rDestination = Serial);
  Plot(const __FlashStringHelper *Context, const __FlashStringHelper *Channel, Print &rDestination = Serial);

  Plot(const char* Context, Print& rDestination = Serial);
  Plot(const char* Context, const char* Channel, Print& rDestination = Serial);
  Plot(const char* Context, const __FlashStringHelper* Channel, Print& rDestination = Serial);

  void SetParameter(const __FlashStringHelper *pfstrParameter, const char * Value);
  void SetParameter(const __FlashStringHelper *pfstrParameter, const __FlashStringHelper * Value);

  void SetParameter(const char* pfstrParameter, const char* Value);
  void SetParameter(const char* pfstrParameter, const __FlashStringHelper* Value);

  void SendSeriesProperties(const char *SeriesProperties);
  void SendSeriesProperties(const __FlashStringHelper *SeriesProperties);
  void SendSeriesProperties(Colors Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax);
  void SendSeriesProperties(const RGBColor& Color, LineStyle Line, uint8_t uLineWidth, MarkerStyle Marker, Axis ax);
  
  void SendSeriesProperties(Colors color);
  void SendSeriesProperties(const RGBColor& Color);
  void SendSeriesProperties(LineStyle style, uint8_t uLineWidth);
  void SendSeriesProperties(MarkerStyle style);
  void SendSeriesProperties(Axis ax);
  void SendSeriesProperties(LineFormat const& fmt);
  void SendSeriesProperties(MarkerFormat const& fmt);

  template<typename T, typename... Args>
  void SendSeriesProperties(T Property, Args... MoreProperties)
  {
    SendSeriesProperties(Property);
    SendSeriesProperties(MoreProperties...);
  }

  void SendHeader_Data();
  void SendTimeSeparator();
  void SendColorValue(const RGBColor& Color);

  template<typename T>
  void SendSeriesHeader(const __FlashStringHelper* pstrCmd, T SeriesName, bool bIncludeSeparator)
  {
    SendDataHeader(pstrCmd);
    m_rDestination.print(SeriesName);
    if (bIncludeSeparator)
    {
      m_rDestination.print('|');
    }
  }

  template<typename T>
  void SendSeriesHeader_Data(T SeriesName, bool bIncludeSeparator)
  {
    SendSeriesHeader(F("DATA"), SeriesName, bIncludeSeparator);
  }

private:
  void SendRangeDetail(float fYLimLower, float fYLimUpper);
};

