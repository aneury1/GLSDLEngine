#include "Buffer.h"

std::uint32_t rgb_to_u32(uint8_t r, uint8_t g, uint8_t b)
{
    return (r << 24) | (g << 16 )|( b << 8)| 255;
}

void buffer_set(Buffer *buffer, uint32_t color)
{
    if(buffer)
    {
        int counter = buffer->width * buffer->height;
        for(int i=0 ;i < counter ;i++)
        {
            buffer->data[i]=color;
        }
    }
}

Buffer::Buffer(int w, int h,uint32_t color)
{
   this->height = h;
   this->width  = w;
   this->data   = new uint32_t[w * h];
   buffer_set(this, color);
}

Buffer::Buffer(int w, int h)
{
   this->height = h;
   this->width  = w;
   this->data   = new uint32_t[w * h];
   buffer_set(this, 0x00000000);
}
Buffer::Buffer()
{
   this->height = 32;
   this->width  = 32;
   this->data   = new uint32_t[32 * 32];
   buffer_set(this, 0x00000000);
}
#include "Sprite.h"
void Buffer::Draw(const Sprite& sprite,size_t x, size_t y, uint32_t color)
{
    for(size_t xi = 0; xi < sprite.width; ++xi)
    {
        for(size_t yi = 0; yi < sprite.height; ++yi)
        {
            size_t sy = sprite.height - 1 + y - yi;
            size_t sx = x + xi;
            if(sprite.data[yi * sprite.width + xi] &&
               sy < height && sx < width) 
            {
                data[sy * width + sx] = color;
            }
        }
    }
    
    glTexSubImage2D(
        GL_TEXTURE_2D, 0, 0, 0,
        this->width, this->height,
        GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,
        this->data
    );
}



TextureBuffer::TextureBuffer(const Buffer* buffer_data)
{
    if(buffer_data)
    {
        glGenTextures(1, &this->text_id);
        glBindTexture(GL_TEXTURE_2D, text_id);
        glTexImage2D(GL_TEXTURE_2D, 0,GL_RGB8,
                     buffer_data->width, 
                     buffer_data->height,
                      0,GL_RGBA,
                      GL_UNSIGNED_INT_8_8_8_8, buffer_data->data
                      );
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);   
    }
}

 void TextureBuffer::Attach(GLProgram *program, const char *str)
 {
      location = glGetUniformLocation(program->getProgram(), str);
      glUniform1i(location, 0);
 }


 /* 
    buffer_sprite_draw(&buffer_test, alien_sprite, 322, 228, rgb_to_u32(128, 0, 0));

    glTexSubImage2D(
        GL_TEXTURE_2D, 0, 0, 0,
        buffer_test.width, buffer_test.height,
        GL_RGBA, GL_UNSIGNED_INT_8_8_8_8,
        buffer_test.data
    );
 
 */