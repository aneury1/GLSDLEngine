
#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 color;

out vec3 my_color;

void main()
{
    my_color = vec4(1.0, 1.0,0.0, 1.0);
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
};