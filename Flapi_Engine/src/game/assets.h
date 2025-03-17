#pragma once
#include "engine/render/Texture.h"



class Assets
{
public:
	enum Textures
	{
		NULLTEXTURE = 0,
		DEFAULT = 1,
		GRASS = 2,
		CONTEINER = 3
	};
	void loadTextures();
	static Engine::Texture getTexture(Textures texture);
private:
	static Engine::Texture m_nullTexture;
	static Engine::Texture m_defaultTexture;
	static Engine::Texture m_grassTexture;
	static Engine::Texture m_conteinerTexture;
};