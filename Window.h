#pragma once 
#include <cstdio>
#include <cstdlib>
 
#include <SDL2/SDL.h>
#include "glad/glad.h"



struct Rect
{
   int x,y,w,h;
};

struct Window
{
    Rect window_rect;
    SDL_Window *window;
    SDL_GLContext context;
    bool running;
    Window();
    ~Window(){
        SDL_DestroyWindow(window);
        SDL_GL_DeleteContext(context);
    }
    void setClearColor(float r, float g, float b, float a);
    void clear();
    void PollEvent();
    void updateScreen();

};