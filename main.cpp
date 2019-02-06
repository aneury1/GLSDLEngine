#include <memory>
#include "Window.h"
#include "Shader.h"
#include "GLProgram.h"
#include "FloatArray.h"
#include "Buffer.h" 
#include "Sprite.h"
#include <iostream>
#include "Vector.h"
#include "VertexModel.h"

const char *vertex_shader =

"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 GColor;\n"
"\n"
"out vec3 aColor;\n"
"void main()\n"
"{\n"
"    aColor = GColor;\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char *fragment_shader=
"#version 330 core\n"
"out vec4 FragColor;\n"
"in vec3 aColor;\n"
"void main()\n"
"{\n"
"\n    FragColor = vec4(aColor , 1.0f);\n"
"}";



 



int main(int argc, char *argv[]) {

  std::shared_ptr<Window> window(new Window());
  std::shared_ptr<GLProgram> program(new GLProgram());
  program->attachShader(new Shader(vertex_shader   , ShaderTypes::VERTEX_SHADER));
  program->attachShader(new Shader(fragment_shader , ShaderTypes::FRAGMENT_SHADER));
  ///program->attachShader(new Shader(ShaderTypes::VERTEX_SHADER, "C:\\Aneury\\GLSDLEngine\\bin\\Debug\\v.glsl"));
  ///program->attachShader(new Shader(ShaderTypes::FRAGMENT_SHADER, "C:\\Aneury\\GLSDLEngine\\bin\\Debug\\f.glsl"));
  program->compile();
 

   float my_vertices[]={
    // first triangle
      //  -0.120312f, 0.050000f, 0.0f, 1 , 0 ,0,
      // -0.048437f, 0.208333f, 0.0f, 0 , 1 ,0,
      // -0.217187f, 0.195833f, 0.0f, 0 , 0 ,1,
    -0.5f, -0.5f, 0.0f,
     0.5f, -0.5f, 0.0f,
     0.0f,  0.5f, 0.0f
      // 0.735937, -0.524999 , 0.0f, 0 , 0 ,1,
      // 0.860937, -0.810416 , 0.0f, 0 , 1 ,0,
      //  0.584375, -0.829166 , 0.0f, 1 , 0 ,0,

      // 0.800000, 0.056249, 0.0f, 0.78 , 0.34344 ,1,
      //  0.181250, -0.787500, 0.0f, 0.898 , 0.787 ,0.7878871,
      // 0.929687, 0.627083, 0.0f, 0.56767 , 0.78787 ,1,
 };
 float colors[]={
    // first triangle
      //  -0.120312f, 0.050000f, 0.0f, 1 , 0 ,0,
      // -0.048437f, 0.208333f, 0.0f, 0 , 1 ,0,
      // -0.217187f, 0.195833f, 0.0f, 0 , 0 ,1,
    0.5f, 0.5f, 1.0f,
     0.5f, 0.5f, 1.0f,
     1.0f,  0.5f, 1.0f};
   vector <float> test({
      -0.5f, -0.5f, 0.0f,
       0.5f, -0.5f, 0.0f,
       0.0f,  0.5f, 0.0f});
    vector <float> color({
      1.0f, 0.0f, 0.0f,
      0.0f, 1.0f, 0.0f,
      0.0f, 0.0f, 1.0f
    });

 

   VertexModel model(test,3);
   model.addVertices(color, 3);
   model.unbind();
  
    GLuint VAO, VBO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof( my_vertices), my_vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float) , (void *)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    GLuint color_vBo;
    glGenBuffers(1, &color_vBo);
    glBindBuffer(GL_ARRAY_BUFFER, color_vBo);
    glBufferData(GL_ARRAY_BUFFER, sizeof( colors), colors, GL_STATIC_DRAW);
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3*sizeof(float) , (void *)0);
    glEnableVertexAttribArray(1);
    glBindVertexArray(0);
 



 
  while (window->running) 
  {    
    window->setClearColor(0.3,0.2,0.0,1);
    window->clear();
    window->PollEvent();
    program->Use();  

     model.bind();
     glDrawArrays(GL_TRIANGLES,0, 3);
    //  glBindVertexArray(VAO);
    //  glDrawArrays(GL_TRIANGLES,0, 3);
     ///glDrawElements(GL_TRIANGLES, 3 ,GL_UNSIGNED_INT , 0); 
    window->updateScreen();
    SDL_Delay(1000/60);
  }
 
  return 0;
}


