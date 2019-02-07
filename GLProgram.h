#pragma once
#include "Window.h"
#include "Shader.h"
#include <vector>
#include <string>

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
   inline GLuint getProgram(){return gl_program;}

    void setBool(const std::string &name, bool value) const;  
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;

};