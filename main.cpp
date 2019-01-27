#include <memory>
#include "Window.h"
#include "Shader.h"
#include "GLProgram.h"
#include "FloatArray.h"
#include "Buffer.h" 
#include <iostream>


const char *vertex_shader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 my_color;\n"
"void main()\n"
"{\n"
"    my_color = vec3(color);\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char *fragment_shader=
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"in vec3 my_color;"
"void main()\n"
"{\n"
"\n    FragColor = vec4(my_color, 1.0f);\n"
"}";



struct Triangle{
    Triangle()
   {
     
    GLuint MyVBO, MyVAO;
    glGenVertexArrays(1, &MyVAO);
    glBindVertexArray(MyVAO);
    float my_vertex[]=
    {
        1.0f, 0.0,   1.0, 1.0, 0.0,
       -1.0f, 0.3,   1.0, 0.1, 1.0,
       -1.0 , -1.0,  0.5, 1.0, 0.8
    };
     glGenBuffers(1, &MyVBO);
     glBindBuffer(GL_ARRAY_BUFFER, MyVBO);
     glBufferData(GL_ARRAY_BUFFER, sizeof(my_vertex), my_vertex, GL_STATIC_DRAW);
     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void *)0);
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 *sizeof(float),((void *)(sizeof(float) * 2)));
     glEnableVertexAttribArray(1);
     glBindVertexArray(0);
   
   }

};



int main(int argc, char *argv[]) {

  std::shared_ptr<Window> window(new Window());
  std::shared_ptr<GLProgram> program(new GLProgram());
  ///program->attachShader(new Shader(vertex_shader, ShaderTypes::VERTEX_SHADER));
  ///program->attachShader(new Shader(fragment_shader, ShaderTypes::FRAGMENT_SHADER));
 
  program->attachShader(new Shader(default_space_vertex_shader, ShaderTypes::VERTEX_SHADER));
  program->attachShader(new Shader(default_space_fragment_shader, ShaderTypes::FRAGMENT_SHADER));
  Buffer buffer_test(640, 480, 0X43434300);
  TextureBuffer texture(&buffer_test);
  
  GLuint fullscreen_triangl_vao;
  glGenVertexArrays(1, &fullscreen_triangl_vao);
  glBindVertexArray(fullscreen_triangl_vao);

  program->compile();
  texture.Attach(program.get(), "buffer");


  glDisable(GL_DEPTH_TEST);


  while (window->running) 
  {
    window->PollEvent();
    window->setClearColor(1,0.0,0.0,1);
    window->clear();
    program->Use();  
    glBindVertexArray(fullscreen_triangl_vao);
    glDrawArrays(GL_TRIANGLES,0, 3);  
    window->updateScreen();
    SDL_Delay(1000/60);
  }
 
  return 0;
}


