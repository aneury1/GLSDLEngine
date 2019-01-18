#pragma once 

#include <fstream>
#include "Window.h"

enum class ShaderTypes{
     VERTEX_SHADER=1, 
     FRAGMENT_SHADER=2,
     SHADER_COUNTER
};


class Shader
{
    GLuint shader;
    public:
    ////Shader(Shader &&sh)     =  delete;
    ////Shader(const Shader &sh) = delete;


    Shader(ShaderTypes shader, const char *filename);

    const GLuint getID()const{return shader;}
   
    ~Shader();
};