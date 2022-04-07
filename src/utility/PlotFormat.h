#pragma once
#include <Arduino.h>
#include "Plot.h"

class LineFormat 
{
public:
  LineFormat(Plot::LineStyle s, uint8_t uLineWidth)
  {
    Style = s;
    Width = uLineWidth;
  }

  Plot::LineStyle Style;
  uint8_t Width;
};


class MarkerFormat
{
public:
  MarkerFormat(Plot::MarkerStyle s, uint8_t uSize)
  {
    Style = s; 
    Size = uSize;
  }

  Plot::MarkerStyle Style;
  uint8_t Size;
};