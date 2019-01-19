#include <memory>
#include "Window.h"
#include "Shader.h"
#include "GLProgram.h"
#include "FloatArray.h"
 
#include <iostream>
const char *vertex_shader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"\n"
"void main()\n"
"{\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char *fragment_shader=
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"void main()\n"
"{\n"
"\n    FragColor = vec4(-1.0f, 1.0f, 0.2f, 1.0f);\n"
"}";

int main(int argc, char *argv[]) {

  std::shared_ptr<Window> window(new Window());
  std::shared_ptr<GLProgram> program(new GLProgram());
///  program->attachShader(new Shader(ShaderTypes::VERTEX_SHADER,"vertex.glsl"));
///  program->attachShader(new Shader(ShaderTypes::FRAGMENT_SHADER, "fragment.glsl"));
  program->attachShader(new Shader(vertex_shader, ShaderTypes::VERTEX_SHADER));
  program->attachShader(new Shader(fragment_shader, ShaderTypes::FRAGMENT_SHADER));
  program->compile();
   float vertices[] = {
     0.5f,  0.5f, 0.0f,  // top right
     0.5f, -0.5f, 0.0f,  // bottom right
    -0.5f, -0.5f, 0.0f,  // bottom left
    -0.5f,  0.5f, 0.0f   // top left 
};
unsigned int indices[] = {  // note that we start from 0!
    0, 1, 3,   // first triangle
    1, 2, 3    // second triangle
};  
  

    GLuint VBO,VAO;
  
    unsigned int EBO;
    glGenBuffers(1, &EBO);
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STREAM_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW); 
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);







  while (window->running) 
  {

  

    window->PollEvent();
    window->setClearColor(0.4,0.4,0.3,1);
    window->clear();
    program->Use();
    
///    glUseProgram(shaderProgram);
    
    
    glBindVertexArray(VAO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    window->updateScreen();
    SDL_Delay(1000/60);
  }
 
  return 0;
}


