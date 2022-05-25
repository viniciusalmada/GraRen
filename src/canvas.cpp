#include "canvas.hpp"

GraRen::Canvas::Canvas(int w, int h)
    : width(w), height(h), gl_handler(w, h),
      rect_x({ { 0, h / 2 }, w, 2, GraRen::Color::WHITE }),
      rect_y({ { w / 2, 0 }, 2, h, GraRen::Color::WHITE })
{

  AddElement(&rect_x);
  AddElement(&rect_y);
}

void GraRen::Canvas::AddElement(const IElement* element)
{
  elements.insert(element);

  gl_handler.UpdateBuffers(elements);
}

void GraRen::Canvas::Render() const { gl_handler.Render(); }

void GraRen::Canvas::UpdateData() { gl_handler.UpdateBuffers(elements); }