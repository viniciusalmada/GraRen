#include "rectangle.hpp"

GraRen::Rectangle::Rectangle(GraRen::Point bottomLeft,
                          Number w,
                          Number h,
                          Color color)
    : bot_left_point(bottomLeft), width(w), height(h), color(color)
{
}

GraRen::Rectangle::Rectangle(Point bottomLeft, Point topRight, Color color)
    : bot_left_point(bottomLeft), width(topRight.GetX() - bottomLeft.GetX()),
      height(topRight.GetY() - bottomLeft.GetY()), color(color)
{
}

void GraRen::Rectangle::SetTopRight(const GraRen::Point& pt)
{
  Number new_width = pt.GetX() - bot_left_point.GetX();
  Number new_height = pt.GetY() - bot_left_point.GetY();
  width = new_width;
  height = new_height;
}

void GraRen::Rectangle::SetCenterPoint(const GraRen::Point& pt)
{
  GraRen::Point center = GetCenterPoint();

  GraRen::Point diff = pt - center;
  bot_left_point += diff;
}

GraRen::Point GraRen::Rectangle::GetCenterPoint() const
{
  return bot_left_point + GraRen::Point{ width / 2, height / 2 };
}

std::vector<GraRen::Point> GraRen::Rectangle::RetrievePositions() const
{
  GraRen::Point bot_right = bot_left_point + GraRen::Point{ width, 0 };
  GraRen::Point top_right = bot_left_point + GraRen::Point{ width, height };
  GraRen::Point top_left = bot_left_point + GraRen::Point{ 0, height };

  return { bot_left_point, bot_right, top_right, top_left };
}

GraRen::Color GraRen::Rectangle::RetrieveColor() const { return this->color; }

std::vector<unsigned int> GraRen::Rectangle::RetrieveIndices() const
{
  return { 0, 1, 2, 0, 2, 3 };
}