#version 400 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;
layout (location = 2) in vec2 in_texture_coord;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

out vec4 v_color;
out vec2 v_texture_coord;

void main()
{
    v_color = in_color;
    v_texture_coord = in_texture_coord;
    gl_Position = u_proj * u_view * u_model * in_position;
}
