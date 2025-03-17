#version 330 core

in vec3 fragColor;
out vec4 FragColor;

void main()
{
    vec3 mainColor = fragColor;
    FragColor = vec4(mainColor, 1.0);
}