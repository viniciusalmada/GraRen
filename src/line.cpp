#include "line.hpp"

GraRen::Line::Line(Point startPt, Point endPt, Color color)
    : start_pt(startPt), end_pt(endPt), color(color)
{
}

std::vector<GraRen::Point> GraRen::Line::RetrievePositions() const
{
  GraRen::Point start_pt1 = start_pt + GraRen::Point{ 0, -1 };
  GraRen::Point end_pt1 = end_pt + GraRen::Point{ 0, -1 };

  return { start_pt1, end_pt1, end_pt, start_pt };
}

GraRen::Color GraRen::Line::RetrieveColor() const { return this->color; }

std::vector<unsigned int> GraRen::Line::RetrieveIndices() const
{
  return { 0, 1, 2, 0, 2, 3 };
}