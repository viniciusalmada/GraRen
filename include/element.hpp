#ifndef GRAREN_ELEMENT
#define GRAREN_ELEMENT

#include "color.hpp"
#include "graren.hpp"
#include "point.hpp"

#include <vector>

namespace GraRen
{
  class GRAREN IElement
  {
  public:
    virtual std::vector<Point> RetrievePositions() const { return {}; }

    virtual Color RetrieveColor() const { return Color::WHITE; }

    virtual std::vector<unsigned int> RetrieveIndices() const {return {}; }
  };
}

#endif
