#include "circle.hpp"

#include <cmath>

GraRen::Circle::Circle(GraRen::Point center,
                       GraRen::Number radius,
                       GraRen::Color color)
    : center(center), radius(radius), color(color)
{
}

void GraRen::Circle::SetCenter(const Point& pt) { this->center = pt; }

GraRen::Point GraRen::Circle::GetCenter() const { return center; }

std::vector<GraRen::Point> GraRen::Circle::RetrievePositions() const
{
  std::vector<GraRen::Point> pts;
  pts.reserve(DISCRETE_POINTS + 1);

  const double pi = 2.0 * std::asin(1.0);

  const double start_rad = 0.0;
  const double end_rad = 2.0 * pi;
  const double step = (end_rad - start_rad) / DISCRETE_POINTS;
  for (double angle = start_rad; angle <= end_rad; angle += step)
  {
    double si = std::sin(angle);
    double co = std::cos(angle);

    Number x = static_cast<Number>(si * radius);
    Number y = static_cast<Number>(co * radius);

    pts.push_back(GraRen::Point{ x, y } + center);
  }

  pts.push_back(center);

  return pts;

};

GraRen::Color GraRen::Circle::RetrieveColor() const { return color; }

std::vector<unsigned int> GraRen::Circle::RetrieveIndices() const
{
  const unsigned int CENTER_ID = DISCRETE_POINTS;
  std::vector<unsigned int> indices;
  indices.reserve(DISCRETE_POINTS * 3);

  unsigned int i = 0;
  for (int c = 0; c < DISCRETE_POINTS; c++, i++)
  {
    indices.push_back(i);
    if (i != DISCRETE_POINTS - 1)
      indices.push_back(i + 1);
    else
      indices.push_back(0);
    indices.push_back(CENTER_ID);
  }

  return indices;
};