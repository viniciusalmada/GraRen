#ifndef GRAREN_CANVAS
#define GRAREN_CANVAS

#include "element.hpp"
#include "gl_handler.hpp"
#include "graren.hpp"
#include "rectangle.hpp"

#include <memory>
#include <vector>

namespace GraRen
{
  /**
   * @brief Canvas representation
   *
   * A canvas is a user-defined rectangle that is ported for the viewport in
   * host window.
   *
   * A canvas also had a oriented coordinates system that starts in (0,0) at
   * bottom-left corner and goes to maximum point at (width, height) in
   * top-right corner.
   *
   */
  class Canvas
  {
  public:
    GRAREN Canvas(int w, int h);

    virtual GRAREN ~Canvas(){};

    void GRAREN Render() const;

    void GRAREN UpdateData(const std::vector<IElement*>& elements);

  private:
    int width;
    int height;

    GLHandler gl_handler;
  };
}

#endif
