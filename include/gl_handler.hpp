#ifndef GRAREN_GL_HANDLER
#define GRAREN_GL_HANDLER

#include "element.hpp"
#include "graren.hpp"

#include <GL3H/index_buffer.hpp>
#include <GL3H/renderer.hpp>
#include <GL3H/vertex_buffer.hpp>
#include <GL3H/vertex_layout.hpp>
#include <memory>
#include <set>
#include <string>

namespace GraRen
{
  class GRAREN VertexInfo
  {
  public:
    VertexInfo(GraRen::Point pt, GraRen::Color color) : point(pt), color(color)
    {
    }
    VertexInfo() : point({ 0, 0 }), color({ 0, 0, 0 }) {}

    struct Data
    {
      int x;
      int y;
      float red;
      float green;
      float blue;
    };

    Data data() const
    {
      return { point.GetX(),
               point.GetY(),
               color.Red(),
               color.Green(),
               color.Blue() };
    };

    static GL3H::VertexLayout getLayout();

  private:
    GraRen::Point point;
    GraRen::Color color;
  };

  class GLHandler
  {
  public:
    GRAREN GLHandler(unsigned int width, unsigned int height);

    void GRAREN UpdateBuffers(const std::set<IElement>& elements);

    void GRAREN Render() const;

  private:
    GL3H::Shader GRAREN CreateShader() const;

    GL3H::RendererData GRAREN InitRenderer() const;

    static const std::string VERTEX_SHADER_SRC;
    static const std::string FRAGMENT_SHADER_SRC;

    unsigned int width = 0;
    unsigned int height = 0;
    GL3H::Renderer renderer;
  };
}

#endif