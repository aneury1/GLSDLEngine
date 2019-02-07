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
"uniform float xOffset;"
"void main()\n"
"{\n"
"    aColor = GColor;\n"
"    gl_Position = vec4(aPos.x + xOffset, aPos.y, aPos.z, 1.0);\n"
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
  ///glEnable(GL_DEPTH_TEST);
  program->attachShader(new Shader(vertex_shader   , ShaderTypes::VERTEX_SHADER));
  program->attachShader(new Shader(fragment_shader , ShaderTypes::FRAGMENT_SHADER));
  program->compile();
  
  float Z = 0.5;
  float MZ= -0.5;
 
 float colors[]={
    0.5f, 0.5f, 1.0f,
     0.5f, 0.5f, 1.0f,
     1.0f,  0.5f, 1.0f};
   vector <float> test({
      -0.5f, -0.5f, Z,
       0.5f, -0.5f, MZ,
       0.0f,  0.5f, Z});
    vector <float> color({
      1.0f, 0.0f, 0.0f,
      1.0f, 1.0f, 1.0f,
      0.0f, 0.0f, 1.0f
    });

 






   VertexModel model(test,3);
   model.addVertices(color, 3);

   vector <float> model2_vertex({
        0.895312, 0.087499,Z,
        0.809374, 0.222916,MZ,
        -0.959375, -0.900000,MZ
       });
   VertexModel model2(model2_vertex,3);
   model2.addVertices(color,3);
  
  

 



  
  while (window->running) 
  {    
    float repeat = 0.2627450980392157;
    window->setClearColor(repeat, repeat, repeat,1);
    window->clear();
    window->PollEvent();
    const Uint8 *keyboard = SDL_GetKeyboardState(NULL);
    program->Use();  
    if(keyboard[SDL_SCANCODE_LEFT])
    {
        float offset = -0.5f;
        program->setFloat("xOffset", offset);
    }
    if(keyboard[SDL_SCANCODE_RIGHT])
    {
        float offset = 0.5f;
        program->setFloat("xOffset", offset);
    }
    model.DrawArray(GL_TRIANGLES);
    model2.DrawArray(GL_TRIANGLES);
    window->updateScreen();
    SDL_Delay(1000/60);
  }
 
  return 0;
}


