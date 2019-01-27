#pragma once 
#include "glad/glad.h"
#include <cstdint>

#include "GLProgram.h"

static const char* default_space_vertex_shader =
    "\n"
    "#version 330\n"
    "\n"
    "noperspective out vec2 TexCoord;\n"
    "\n"
    "void main(void){\n"
    "\n"
    "    TexCoord.x = (gl_VertexID == 2)? 2.0: 0.0;\n"
    "    TexCoord.y = (gl_VertexID == 1)? 2.0: 0.0;\n"
    "    \n"
    "    gl_Position = vec4(2.0 * TexCoord - 1.0, 0.0, 1.0);\n"
    "}\n";
static const char* default_space_fragment_shader =
    "\n"
    "#version 330\n"
    "\n"
    "uniform sampler2D buffer;\n"
    "noperspective in vec2 TexCoord;\n"
    "\n"
    "out vec3 outColor;\n"
    "\n"
    "void main(void){\n"
    "    outColor = texture(buffer, TexCoord).rgb;\n"
    "}\n";


std::uint32_t rgb_to_u32(uint8_t r, uint8_t g, uint8_t b);


struct Buffer
{
    std::size_t width, height;
    std::uint32_t *data;
    Buffer(int w, int h, uint32_t color);
    Buffer(int w, int h);
    Buffer();

};

struct TextureBuffer{
   GLuint text_id;
   GLint location;
   TextureBuffer(const Buffer* buffer_data);
   void Attach(GLProgram *program, const char *str);
};


void buffer_set(Buffer *buffer, uint32_t color);


