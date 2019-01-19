#include "GLProgram.h"
#include <iostream>


GLProgram::GLProgram()
{
    this->gl_program =glCreateProgram();
}
GLProgram::~GLProgram()
{
    glDeleteProgram(gl_program);
}
void GLProgram::Use()
{
    glUseProgram(gl_program);
}
void GLProgram::attachShader(Shader* sh)
{
    this->shaders.emplace_back(sh);
}
bool GLProgram::compile()
{
    for(auto it : this->shaders)
       {
           glAttachShader(this->gl_program, it->getID());
       }
        glLinkProgram(this->gl_program);
        {
        int success;
        char infoLog[512];
        glGetProgramiv(this->gl_program, GL_LINK_STATUS, &success);
            if(!success) {
                glGetProgramInfoLog(this->gl_program, 512, NULL, infoLog);
                std::cout <<"infolog compilando el programa trajo...\n"<<infoLog<<"\n";     
            }
            else{
                std::cout<<"program correnct linked\n";
            }

        }
}
