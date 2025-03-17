#include "assets.h"

Engine::Texture Assets::m_defaultTexture; 
Engine::Texture Assets::m_nullTexture;
Engine::Texture Assets::m_grassTexture;
Engine::Texture Assets::m_conteinerTexture;

void Assets::loadTextures()
{
	m_defaultTexture.loadTexture2D("assets/res/textures/default.png");
	m_grassTexture.loadTexture2D("assets/res/textures/grass.jpg");
	m_conteinerTexture.loadTexture2D("assets/res/textures/container.jpg");
}

Engine::Texture Assets::getTexture(Textures texture)
{
	switch (texture)
	{
	case CONTEINER:
		return m_conteinerTexture;
		break;
	case DEFAULT:
		return m_defaultTexture;
		break;
	case GRASS:
		return m_grassTexture;
		break;
	case NULLTEXTURE:
		return m_nullTexture;
		break;
	default:
		return m_defaultTexture;
		break;
	}
}
