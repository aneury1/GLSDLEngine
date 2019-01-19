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
    friend class GLProgram;
    unsigned int shader;
    public:
    ////Shader(Shader &&sh)     =  delete;
    ////Shader(const Shader &sh) = delete;


    Shader(ShaderTypes shader, const char *filename);

    Shader( const char *str, ShaderTypes shader);

     unsigned int getID(){return shader;}
   
    ~Shader();
};