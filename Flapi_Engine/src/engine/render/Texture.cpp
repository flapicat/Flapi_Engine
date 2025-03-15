#include "Texture.h"

namespace Engine
{
	Texture::Texture()
	{
	}

	void Texture::loadTexture2D(const char* filepath)
	{
		// load and create a texture 
		// -------------------------
		glGenTextures(1, &texture);
		glBindTexture(GL_TEXTURE_2D, texture);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		stbi_set_flip_vertically_on_load(true);
		data = stbi_load(filepath, &width, &height, &nrChannels, 0);
		if (data)
		{
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
			glGenerateMipmap(GL_TEXTURE_2D);
		}
		else
		{
			std::cout << "Failed to load BLOCK texture" << std::endl;
		}
		stbi_image_free(data);
	}

	void Texture::bindTexture2D()
	{
		glBindTexture(GL_TEXTURE_2D, texture);
	}
	void Texture::unbindTexture2D()
	{
		glBindTexture(GL_TEXTURE_2D, 0);
	}
}