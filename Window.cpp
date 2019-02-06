#include "Window.h"


Window::Window()
{
  SDL_Init(SDL_INIT_EVERYTHING);
  atexit (SDL_Quit);
  SDL_GL_LoadLibrary(NULL); // Default OpenGL is fine.

  // Request an OpenGL 4.5 context (should be core)
  SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
  SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
  // Also request a depth buffer
  SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
  SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
  window = SDL_CreateWindow( "OPENGL",   SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 
      640, 480, SDL_WINDOW_OPENGL
    );
   context=SDL_GL_CreateContext(window);
     printf("OpenGL loaded\n");
  gladLoadGLLoader(SDL_GL_GetProcAddress);
  printf("Vendor:   %s\n", glGetString(GL_VENDOR));
  printf("Renderer: %s\n", glGetString(GL_RENDERER));
  printf("Version:  %s\n", glGetString(GL_VERSION));

  // Use v-sync
  SDL_GL_SetSwapInterval(1);

  // Disable depth test and face culling.
  glDisable(GL_DEPTH_TEST);
  glDisable(GL_CULL_FACE);

  int w,h;
  SDL_GetWindowSize(window, &w, &h);
  glViewport(0, 0, w, h);
  glClearColor(0.0f, 0.5f, 1.0f, 0.0f);
  running = true;
}

void Window::setClearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}
    
    
void Window::clear()
{
   glClear(GL_COLOR_BUFFER_BIT);
}

void Window::updateScreen()
{   
    SDL_GL_SwapWindow(window);
}

void Window::PollEvent()
{
  SDL_Event event;
    while (SDL_PollEvent(&event)) 
    {
      if (event.type == SDL_QUIT) {
          running = false;
      }
      if(event.key.keysym.sym==SDLK_q)
      {
        glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
      }
      if(event.key.keysym.sym==SDLK_f)
      {
        glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
      }
      if(event.key.keysym.sym==SDLK_l)
      {
           int x,y;
           SDL_GetMouseState(&x, &y);
           SDL_Log("mouse down %f, %f", (x/640.0f), (y/480.0f) );
      }
    }
}