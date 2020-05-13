#version 400 core

layout (location = 0) in vec4 in_position;
layout (location = 1) in vec4 in_color;

uniform mat4 u_model;
uniform mat4 u_view;
uniform mat4 u_proj;

out vec4 v_color;

void main()
{
    v_color = in_color;
    gl_Position = u_proj * u_view * u_model * in_position;
}
