#pragma once
#include <cstdint>
#include "Buffer.h"

struct Sprite
{
    std::size_t width, height;
    std::uint8_t* data;
};

#if 0
struct Buffer;

void buffer_sprite_draw(Buffer* buffer, const Sprite& sprite,size_t x, size_t y, uint32_t color)
{
    for(size_t xi = 0; xi < sprite.width; ++xi)
    {
        for(size_t yi = 0; yi < sprite.height; ++yi)
        {
            size_t sy = sprite.height - 1 + y - yi;
            size_t sx = x + xi;
            if(sprite.data[yi * sprite.width + xi] &&
               sy < buffer->height && sx < buffer->width) 
            {
                buffer->data[sy * buffer->width + sx] = color;
            }
        }
    }
}


#endif