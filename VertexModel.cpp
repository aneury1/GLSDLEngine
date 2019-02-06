#include "VertexModel.h"

#include <stdio.h>
VertexModel::VertexModel(const vector<float>& vertices, int dimension)
{
     index_counter = 0;
     glGenVertexArrays(1, &VAO);
     glBindVertexArray(VAO);
     this->addVertices(vertices, dimension); 
}
  
void VertexModel::bind()
{
    glBindVertexArray(VAO); 
}

  
void VertexModel::unbind()
{
    glBindVertexArray(0); 
}

void VertexModel::addVertices(const vector<GLfloat>& vertices, int dimension)
{
     GLuint VBO;
     printf("index counter =%d\n", index_counter);
     glGenBuffers(1, &VBO);
     glBindBuffer(GL_ARRAY_BUFFER, VBO);
     glBufferData(GL_ARRAY_BUFFER, vertices.size()*sizeof(vertices[0]), vertices.data(),GL_STATIC_DRAW);
     glVertexAttribPointer(index_counter, dimension ,GL_FLOAT, GL_FALSE, 0, (void *)0);
     glEnableVertexAttribArray(this->index_counter);
     buffer_list.push_back(VBO);
     glBindVertexArray(0);  
     glBindBuffer(GL_ARRAY_BUFFER, 0);
     this->index_counter++;
}

 