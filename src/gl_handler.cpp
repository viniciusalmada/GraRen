#include "gl_handler.hpp"

#include <GL3H/shader.hpp>
#include <algorithm>

GL3H::VertexLayout GraRen::VertexInfo::getLayout()
{
  std::vector<GL3H::AttribInfo> attrs{ GL3H::AttribInfo{ GL_INT, 2 },
                                       GL3H::AttribInfo{ GL_FLOAT, 3 } };
  return { attrs };
}

const std::string GraRen::GLHandler::VERTEX_SHADER_SRC = R"glsl(
  #version 330 core
  
  layout(location = 0) in ivec2 position;
  layout(location = 1) in vec3 color;

  out vec4 frag_color;

  uniform int width;
  uniform int height;

  void main()
  {
    mat2 SCALE_MAT = mat2(
       1.0/width*2.0, 0.0,        // col 0
       0.0,       1.0/height*2.0  // col 1
    );

    vec2 scale_position = SCALE_MAT * position;
    scale_position = scale_position + vec2(-1.0, -1.0);

    gl_Position = vec4(scale_position, 1.0, 1.0);
    frag_color = vec4(color, 1.0);
  }

)glsl";

const std::string GraRen::GLHandler::FRAGMENT_SHADER_SRC = R"glsl(
  #version 330 core

  in vec4 frag_color;

  out vec4 color;

  void main()
  {
    color = frag_color;
  }
)glsl";

GraRen::GLHandler::GLHandler(unsigned int width, unsigned int height)
    : width(width), height(height), renderer({ InitRenderer() })
{
}

GL3H::Shader GraRen::GLHandler::CreateShader() const
{
  // Start by creating and compile shaders
  GL3H::ShaderSource vertex_src{ VERTEX_SHADER_SRC, GL3H::ShaderType::VERTEX };
  GL3H::ShaderSource frag_src{ FRAGMENT_SHADER_SRC,
                               GL3H::ShaderType::FRAGMENT };

  GL3H::Shader shader{ vertex_src, frag_src };

  shader.bind();
  shader.setUniform1i("width", (int)width);
  shader.setUniform1i("height", (int)height);
  shader.unbind();

  return shader;
}

GL3H::RendererData GraRen::GLHandler::InitRenderer() const
{
  GL3H::Shader shader = CreateShader();

  GL3H::IndexBuffer index_buffer{ nullptr, 0 };
  GL3H::VertexBuffer vertex_buffer{ nullptr, 0 };

  GL3H::VertexArray vertex_array{ vertex_buffer, VertexInfo::getLayout() };

  return GL3H::RendererData{ vertex_array, index_buffer, shader };
}

void GraRen::GLHandler::UpdateBuffers(const std::set<IElement>& elements)
{
  // Update first vertex buffer
  {
    std::vector<VertexInfo::Data> vertices_data;

    for (const IElement& element : elements)
    {
      std::vector<GraRen::Point> positions = element.RetrievePositions();
      GraRen::Color color = element.RetrieveColor();
      for (const GraRen::Point pt : positions)
      {
        VertexInfo info{ pt, color };
        vertices_data.push_back(info.data());
      }
    }

    unsigned int size_of_vertices =
      static_cast<unsigned int>(vertices_data.size()) *
      static_cast<unsigned int>(sizeof(VertexInfo::Data));
    this->renderer.updateVertexBuffer(vertices_data.data(), size_of_vertices);
  }

  // Update second index buffer
  {
    unsigned int current_max_index = 0;
    std::vector<unsigned int> indices_data;

    for (const IElement& element : elements)
    {
      const std::vector<unsigned int> indices = element.RetrieveIndices();
      for (const auto i : indices)
      {
        indices_data.push_back(i + current_max_index);
      }

      const unsigned int max_index =
        *std::max_element(indices.cbegin(), indices.cend());
      current_max_index += max_index + 1;
    }

    this->renderer.updateIndexBuffer(
      indices_data.data(),
      static_cast<unsigned int>(indices_data.size()));
  }
}

void GraRen::GLHandler::Render() const { this->renderer.draw(); }