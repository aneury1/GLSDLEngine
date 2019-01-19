#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
namespace Priv{

const char *readFile(const char *filename){
   return nullptr;
}


};

Shader::Shader( const char *str, ShaderTypes shadertype)
{
switch(shadertype)
     {
         case ShaderTypes::VERTEX_SHADER:
         {
            shader = glCreateShader(GL_VERTEX_SHADER);
                if(str)
                {
                    int len=strlen(str);
                    glShaderSource(shader, 1, &str, NULL);
                    glCompileShader(shader);
                         {
                            int  success=1;
                            char infoLog[2048];
                            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                            if(!success)
                            {
                                glGetShaderInfoLog(shader, 2048, NULL, infoLog);
                                std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" 
                                          << infoLog 
                                          << "codigo del shader es:\n"
                                          << str
                                          <<"\n\\n\n";
                            }
                            else{
                                std::cout <<"Shader compiled successfully vertex...\n\n";
                            }
                         }
                }
         }
         break;
         case ShaderTypes::FRAGMENT_SHADER:
         {
            
            shader = glCreateShader(GL_FRAGMENT_SHADER);
                if(str)
                {
                    int len=strlen(str);
                    glShaderSource(shader, 1, &str, NULL);
                    glCompileShader(shader);
                         {
                            int  success=1;
                            char infoLog[2048];
                            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                            if(!success)
                            {
                                glGetShaderInfoLog(shader, 2048, NULL, infoLog);
                                std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" 
                                          << infoLog 
                                          << "codigo del shader es:\n"
                                          << str
                                          <<"\n\\n\n";
                            }
                            else{
                                std::cout <<"Shader compiled successfully fragmnent...\n\n";
                            }
                         }
                }
         
     
         }
     }
}

Shader::Shader(ShaderTypes shadertype, const char *filename)
{
     switch(shadertype)
     {
         case ShaderTypes::VERTEX_SHADER:
         {
                 shader = glCreateShader(GL_VERTEX_SHADER);
                 const char *file_content = Priv::readFile(filename);
                if(file_content)
                {
                    int len=strlen(file_content);
                    glShaderSource(GL_VERTEX_SHADER, 1,(const GLchar *const*)file_content, &len);
                    glCompileShader(shader);
                         {
                            int  success;
                            char infoLog[512];
                            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
                            if(!success)
                            {
                                glGetShaderInfoLog(shader, 512, NULL, infoLog);
                                std::cout << "ERROR::SHADER::COMPILATION_FAILED\n" << infoLog << std::endl;
                            }
                            else{
                                std::cout <<"Shader compiled successfully fragmnent...\n\n";
                            }
                         }
                }
         }
         break;
         case ShaderTypes::FRAGMENT_SHADER:
         {
                shader = glCreateShader(GL_FRAGMENT_SHADER);
                const char *file_content = Priv::readFile(filename);
                if(file_content)
                {
                    int len=strlen(file_content);
                    glShaderSource(GL_FRAGMENT_SHADER, 1,(const GLchar *const*)file_content, &len);
                    glCompileShader(shader);
                }
         }
         break;
         break;
     }

}

Shader::~Shader()
{


}