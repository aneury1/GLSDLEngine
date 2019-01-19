#pragma once
#include "Window.h"
#include "Shader.h"
#include <vector>


class GLProgram
{
   std::vector<Shader *> shaders;
   GLuint gl_program;
  public:

    GLProgram();
    ~GLProgram();
    void Use();
    void attachShader(Shader* sh);  
    bool compile();

};