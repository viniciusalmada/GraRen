#include "canvas.hpp"

GraRen::Canvas::Canvas(int w, int h) : width(w), height(h), gl_handler(w, h) {}

void GraRen::Canvas::Render() const { gl_handler.Render(); }

void GraRen::Canvas::UpdateData(const std::vector<IElement> elements)
{
  gl_handler.UpdateBuffers(elements);
}