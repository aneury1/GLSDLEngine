#include <memory>
#include "Window.h"
#include "Shader.h"
#include "GLProgram.h"
#include "FloatArray.h"
#include "Buffer.h" 
#include "Sprite.h"
#include <iostream>


const char *vertex_shader =
"#version 330 core\n"
"layout (location = 0) in vec3 aPos;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 my_color;\n"
"void main()\n"
"{\n"
"    my_color = vec3(color);\n"
"    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
"}\n";

const char *fragment_shader=
"#version 330 core\n"
"out vec4 FragColor;\n"
"\n"
"in vec3 my_color;"
"void main()\n"
"{\n"
"\n    FragColor = vec4(my_color, 1.0f);\n"
"}";



struct Triangle{
    Triangle()
   {
     
    GLuint MyVBO, MyVAO;
    glGenVertexArrays(1, &MyVAO);
    glBindVertexArray(MyVAO);
    float my_vertex[]=
    {
        1.0f, 0.0,   1.0, 1.0, 0.0,
       -1.0f, 0.3,   1.0, 0.1, 1.0,
       -1.0 , -1.0,  0.5, 1.0, 0.8
    };
     glGenBuffers(1, &MyVBO);
     glBindBuffer(GL_ARRAY_BUFFER, MyVBO);
     glBufferData(GL_ARRAY_BUFFER, sizeof(my_vertex), my_vertex, GL_STATIC_DRAW);
     glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 5 *sizeof(float), (void *)0);
     glEnableVertexAttribArray(0);
     glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 5 *sizeof(float),((void *)(sizeof(float) * 2)));
     glEnableVertexAttribArray(1);
     glBindVertexArray(0);
   
   }

};



int main(int argc, char *argv[]) {

  std::shared_ptr<Window> window(new Window());
  std::shared_ptr<GLProgram> program(new GLProgram());
  ///program->attachShader(new Shader(vertex_shader, ShaderTypes::VERTEX_SHADER));
  ///program->attachShader(new Shader(fragment_shader, ShaderTypes::FRAGMENT_SHADER));
 
  program->attachShader(new Shader(default_space_vertex_shader, ShaderTypes::VERTEX_SHADER));
  program->attachShader(new Shader(default_space_fragment_shader, ShaderTypes::FRAGMENT_SHADER));
  Buffer buffer_test(640, 480, 0X00210000);
  TextureBuffer texture(&buffer_test);
  
  GLuint fullscreen_triangl_vao;
  glGenVertexArrays(1, &fullscreen_triangl_vao);
  glBindVertexArray(fullscreen_triangl_vao);

  program->compile();
  texture.Attach(program.get(), "buffer");
////Game space...
Sprite alien_sprite;
alien_sprite.width = 11;
alien_sprite.height = 8;
alien_sprite.data = new uint8_t[11 * 8]
{
    0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
    0,0,0,1,0,0,0,1,0,0,0, // ...@...@...
    0,0,1,1,1,1,1,1,1,0,0, // ..@@@@@@@..
    0,1,1,0,1,1,1,0,1,1,0, // .@@.@@@.@@.
    1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
    1,0,1,1,1,1,1,1,1,0,1, // @.@@@@@@@.@
    1,0,1,0,0,0,0,0,1,0,1, // @.@.....@.@
    0,0,0,1,1,0,1,1,0,0,0  // ...@@.@@...
};

Sprite player_sprite;
player_sprite.width = 11;
player_sprite.height = 7;
player_sprite.data = new uint8_t[77]
{
    0,0,0,0,0,1,0,0,0,0,0, // .....@.....
    0,0,0,0,1,1,1,0,0,0,0, // ....@@@....
    0,0,0,0,1,1,1,0,0,0,0, // ....@@@....
    0,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@.
    1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
    1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
    1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
};



Sprite alien_sprite1;
alien_sprite1.width = 11;
alien_sprite1.height = 8;
alien_sprite1.data = new uint8_t[88]
{
    0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
    1,0,0,1,0,0,0,1,0,0,1, // @..@...@..@
    1,0,1,1,1,1,1,1,1,0,1, // @.@@@@@@@.@
    1,1,1,0,1,1,1,0,1,1,1, // @@@.@@@.@@@
    1,1,1,1,1,1,1,1,1,1,1, // @@@@@@@@@@@
    0,1,1,1,1,1,1,1,1,1,0, // .@@@@@@@@@.
    0,0,1,0,0,0,0,0,1,0,0, // ..@.....@..
    0,1,0,0,0,0,0,0,0,1,0  // .@.......@.
};


struct Alien
{
   std::size_t x,y;
   uint8_t type;
};


struct Player
{
   std::size_t x,y,life;
};

struct SpriteAnimation
{
    bool loop;
    size_t num_frames;
    size_t frame_duration;
    size_t time;
    Sprite** frames;
};

struct Game
{
    size_t width, height;
    size_t num_aliens;
    Alien* aliens;
    Player player;
};

SpriteAnimation* alien_animation = new SpriteAnimation;

alien_animation->loop = true;
alien_animation->num_frames = 2;
alien_animation->frame_duration = 10;
alien_animation->time = 0;

alien_animation->frames = new Sprite*[2];
alien_animation->frames[0] = &alien_sprite;
alien_animation->frames[1] = &alien_sprite1;

Game game;
game.width = 640;
game.height = 480;
game.num_aliens = 55;
game.aliens = new Alien[game.num_aliens];

game.player.x = 112 - 5;
game.player.y = 32;

game.player.life = 3;

for(size_t yi = 0; yi < 5; ++yi)
{
    for(size_t xi = 0; xi < 11; ++xi)
    {
        game.aliens[yi * 11 + xi].x = 16 * xi + 20;
        game.aliens[yi * 11 + xi].y = 17 * yi + 128;
    }
}










  glDisable(GL_DEPTH_TEST);
  while (window->running) 
  {
    window->PollEvent();
    window->setClearColor(1,0.0,0.0,1);
    window->clear();
    program->Use();  
    buffer_set(&buffer_test, 0x001f0000);

    ///buffer_test.Draw( alien_sprite, 100,100,0xff0000ff);

for(size_t ai = 0; ai < game.num_aliens; ++ai)
{
    const Alien& alien = game.aliens[ai];
                        buffer_test.Draw(alien_sprite,
                                        alien.x, alien.y, 
                                        rgb_to_u32(128, 0, 0));
}

    buffer_test.Draw(player_sprite, 
                     game.player.x, 
                     game.player.y, 
                     rgb_to_u32(128, 0, 0));

        for(size_t ai = 0; ai < game.num_aliens; ++ai)
        {
            const Alien& alien = game.aliens[ai];
            size_t current_frame = alien_animation->time / alien_animation->frame_duration;
            const Sprite& sprite = *alien_animation->frames[current_frame];
            buffer_test.Draw( sprite, alien.x, alien.y, rgb_to_u32(128, 0, 0));
        }
        
        ++alien_animation->time;
        if(alien_animation->time == alien_animation->num_frames * alien_animation->frame_duration)
        {
            if(alien_animation->loop) alien_animation->time = 0;
            else
            {
                delete alien_animation;
                alien_animation = nullptr;
            }
        }

    glDrawArrays(GL_TRIANGLES,0, 3);  
    window->updateScreen();
    SDL_Delay(1000/60);
  }
 
  return 0;
}


