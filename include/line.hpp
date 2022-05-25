#pragma once

#include "graren.hpp"
#include "element.hpp"

namespace GraRen
{
  class GRAREN Line : public IElement
  {
  public:
    Line(Point startPt, Point endPt, Color color = Color::WHITE);

    void SetColor(const Color& c) { this->color = c; }

    void SetStartPoint(const Point& pt) { start_pt = pt; }
    void SetEndPoint(const Point& pt) { end_pt = pt; }

    std::vector<Point> RetrievePositions() const override;

    Color RetrieveColor() const override;

    std::vector<unsigned int> RetrieveIndices() const override;

  private:
    Point start_pt;
    Point end_pt;
    Color color;
  };
}