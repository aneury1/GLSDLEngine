#pragma once
#include "Window.h"
#include "GLProgram.h"

class Texture
{
   GLuint texture_id;
  
  public:

     Texture(const char *src);
     ~Texture();

     void Draw();


};