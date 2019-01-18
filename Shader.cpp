#include "Shader.h"

namespace Priv{

const char *readFile(const char *filename){

    return nullptr;
}


};

Shader::Shader(ShaderTypes shader, const char *filename)
{
     switch(shader)
     {
         case ShaderTypes::VERTEX_SHADER:
         {
            this->shader = glCreateShader(GL_VERTEX_SHADER);
                 const char *file_content = Priv::readFile(filename);
                if(file_content)
                {
                    int len=strlen(file_content);
                    glShaderSource(GL_VERTEX_SHADER, 1,(const GLchar *const*)file_content, &len);
                    glCompileShader(this->shader);
                }
         }
         break;
         case ShaderTypes::FRAGMENT_SHADER:
         {
                this->shader = glCreateShader(GL_FRAGMENT_SHADER);
                const char *file_content = Priv::readFile(filename);
                if(file_content)
                {
                    int len=strlen(file_content);
                    glShaderSource(GL_FRAGMENT_SHADER, 1,(const GLchar *const*)file_content, &len);
                    glCompileShader(this->shader);
                }
         }
         break;
         break;
     }

}

Shader::~Shader()
{


}