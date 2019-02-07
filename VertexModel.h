#pragma once
#include "Shader.h"
#include "GLProgram.h"
#include<vector>

using std::vector;


class VertexModel
{
   vector<GLuint> buffer_list;
   int  index_counter=0;
   GLuint VAO =0;
   int element_counter=0;
   public:

   VertexModel(const vector<GLfloat>& vertices, int dimension = 1);
  
   void bind();
   void unbind();
   void addVertices(const vector<GLfloat>& vertices, int dimension);
   
   void DrawArray(GLint type);

};