#pragma once

#include "graren.hpp"
#include "element.hpp"

namespace GraRen
{
  /**
   * @brief Rectangle shape class that implements IElement interface
   *
   * @par A Rectangle is represented by a bottom-left corner position
   * and width and height values.
   *
   * @par The bottom-left is designed to be vertex 0, bottom-right is
   * vertex 1 and so on:
   *
   * 3          2
   *  ┌────────┐
   *  │        │
   *  │        │
   *  └────────┘
   * 0          1
   *
   * The triangles to render this rectangle are formed by triangles:
   * T1 = 0-1-2
   * T2 = 0-2-3
   *
   */
  class GRAREN Rectangle : public IElement
  {
  public:
    Rectangle(Point bottomLeft, Number w, Number h, Color color = Color::WHITE);

    Rectangle(Point bottomLeft, Point topRight, Color color = Color::WHITE);

    void SetBottomLeft(const Point& pt) { bot_left_point = pt; }
    
    void SetTopRight(const Point& pt);

    void SetCenterPoint(const Point& pt);
    
    Point GetCenterPoint() const;

    void SetColor(const Color& c) { this->color = c; }

    std::vector<Point> RetrievePositions() const override;

    Color RetrieveColor() const override;

    std::vector<unsigned int> RetrieveIndices() const override;

  private:
    Point bot_left_point;
    Number width;
    Number height;
    Color color;
  };
}
