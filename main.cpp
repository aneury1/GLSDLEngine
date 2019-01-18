#include <memory>
#include "Window.h"
#include "Shader.h"
#include "GLProgram.h"
#include "FloatArray.h"
 

int main(int argc, char *argv[]) {

  std::shared_ptr<Window> window(new Window());
  std::shared_ptr<GLProgram> program(new GLProgram());
  FloatArray<9> vertices(1);
 

  while (window->running) 
  {
    window->PollEvent();
    window->setClearColor(0.4,0.4,0.3,1);
    window->clear();
    program->Use();
    window->updateScreen();
    SDL_Delay(1000/60);
  }
  return 0;
}


