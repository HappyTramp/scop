#version 400 core

in vec4 v_color;
in vec2 v_texture_coord;

out vec4 out_color;

uniform sampler2D u_texture;
uniform float u_color_ratio;

void main()
{
    out_color = v_color * u_color_ratio
        + texture(u_texture, v_texture_coord) * (1.0 - u_color_ratio);
}
