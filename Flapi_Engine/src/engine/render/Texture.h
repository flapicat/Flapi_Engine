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
		static void bindTexture2D(unsigned int tex);
		void bindTexture2D();
		void unbindTexture2D();
		unsigned int getTexture() { return texture; };
	private:
		unsigned int texture = 0;
		int width, height, nrChannels;
		unsigned char* data;
	};

}