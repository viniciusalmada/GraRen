#pragma once

#include "element.hpp"
#include "graren.hpp"

namespace GraRen
{
  class GRAREN Circle : public IElement
  {
  public:
    Circle(Point center, Number radius, Color color = Color::WHITE);

    void SetCenter(const Point& pt);

    Point GetCenter() const;

    void SetColor(const Color& c) { this->color = c; }

    std::vector<Point> RetrievePositions() const override;

    Color RetrieveColor() const override;

    std::vector<unsigned int> RetrieveIndices() const override;

  private:
    static constexpr int DISCRETE_POINTS = 24;

    Point center;
    Number radius;
    Color color;
  };
};