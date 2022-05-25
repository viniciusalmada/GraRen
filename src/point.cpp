#include "point.hpp"

GraRen::Point GraRen::Point::operator+(const GraRen::Point& pt) const
{
  return { this->x + pt.x, this->y + pt.y };
}
GraRen::Point GraRen::Point::operator-(const GraRen::Point& pt) const
{
  return { this->x - pt.x, this->y - pt.y };
}
void GraRen::Point::operator+=(const GraRen::Point& pt)
{
  this->x += pt.x;
  this->y += pt.y;
}