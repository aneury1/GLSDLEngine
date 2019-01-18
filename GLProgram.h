#pragma once
#include "Window.h"
#include "Shader.h"
#include <vector>


class GLProgram
{
   std::vector<Shader *> shader;
  public:

    GLProgram();
    ~GLProgram();
    void Use();
    void attachShader(Shader* sh);  

};