#ifndef GRAREN_ELEMENT
#define GRAREN_ELEMENT

#include "color.hpp"
#include "graren.hpp"
#include "point.hpp"

#include <array>
#include <vector>

namespace GraRen
{
  class GRAREN IElement
  {
  public:
    virtual std::vector<Point> RetrievePositions() const = 0;

    virtual Color RetrieveColor() const = 0;

    virtual std::vector<unsigned int> RetrieveIndices() const = 0;
  };
}

#endif
