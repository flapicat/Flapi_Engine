#pragma once
#include <iostream>

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <stb/stb_image.h>

namespace Engine
{
	class Texture
	{
	public:
		Texture();

		void loadTexture2D(const char* filepath);
		void bindTexture2D();
		void unbindTexture2D();
		unsigned int getTexture() { return texture; };
	private:
		unsigned int texture;
		int width, height, nrChannels;
		unsigned char* data;
	};

}