#ifndef GRAREN_COLOR
#define GRAREN_COLOR

#include "graren.hpp"

namespace GraRen
{
  class GRAREN Color
  {
  public:
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    float Red() const { return red / 255.0f; }
    float Green() const { return green / 255.0f; }
    float Blue() const { return blue / 255.0f; }

    static const Color BLACK;
    static const Color WHITE;
    static const Color RED;
    static const Color GREEN;
    static const Color BLUE;
    static const Color MAGENTA;
    static const Color YELLOW;
    static const Color CYAN;

  private:
    int red;
    int green;
    int blue;
  };
}

#endif
