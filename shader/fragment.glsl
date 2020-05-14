#version 400 core

in vec4 v_color;
in vec2 v_texture_coord;

out vec4 out_color;

uniform sampler2D u_texture;

void main()
{
    out_color = texture(u_texture, v_texture_coord);
}
