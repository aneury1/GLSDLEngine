#include "Shader.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
namespace Priv{

const char *readFile(const char *filename){
   using namespace std;
   ifstream ss(filename);
   if(ss.good())
     return std::string(std::istreambuf_iterator<char>(ss), std::istreambuf_iterator<char>()).c_str();
   else{
       std::cout <<"Errororororror \n\n\n\n\n";
     return  "invalid shader...";
   }
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
    std::fstream ss(filename, std::ios::in);
    if(!ss.is_open())
    {
        std::cout <<"Archivo Invalido\n";
    }
    ss.seekg(0,std::ios::end );
    int len = ss.tellg();
    ss.seekg(0,std::ios::beg);
    char *str= new char[len];
    ss.read(str, len);
    str[len]=0;
    ss.close();
    std::cout <<"shader\n"<<str;
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
    delete[] str;
    str= nullptr;
}

Shader::~Shader()
{


}