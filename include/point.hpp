#ifndef GRAREN_POINT
#define GRAREN_POINT

#include "graren.hpp"

namespace GraRen
{
  using Number = int;
  class GRAREN Point
  {
  public:
    Point(Number x, Number y) : x(x), y(y) {}

    Point operator+(const Point& pt) const;
    Point operator-(const Point& pt) const;
    void operator+=(const Point& pt);

    Number GetX() const { return x; }
    Number GetY() const { return y; }

  private:
    Number x;
    Number y;
  };
}

#endif
