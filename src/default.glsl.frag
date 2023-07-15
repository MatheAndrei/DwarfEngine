#version 460 core

in vec2 v_TexCoord;

out vec4 o_Color;

uniform sampler2D u_Texture0;

void main() {
    vec4 textureColor = texture(u_Texture0, v_TexCoord);
    vec4 color = textureColor;
    o_Color = color;
}
