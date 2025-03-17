#include "ObjectHandlerer.h"

ObjectHandlerer::ObjectHandlerer()
{
}

void ObjectHandlerer::init()
{
	tempObject = Engine::staticObject(objects.size(), glm::vec3(0.0f, 0.0f, 0.0f), m_cubeVertices, m_cubeIndices);
	tempObject.setTexture(Assets::getTexture(Assets::Textures::CONTEINER));
	objects.push_back(tempObject);

	tempObject = Engine::staticObject(objects.size(), glm::vec3(2.0f, 0.0f, 0.0f), m_cubeVertices, m_cubeIndices);
	tempObject.setTexture(Assets::getTexture(Assets::Textures::DEFAULT));
	objects.push_back(tempObject);

	createCube(glm::vec3(- 2.0f, 0.0f, 0.0f), Assets::Textures::GRASS);
	createPyramid(glm::vec3(-2.0f, 0.0f, -2.0f), Assets::Textures::NULLTEXTURE);
}

void ObjectHandlerer::render(Engine::Shader& shader)
{
	for (Engine::staticObject& object : objects)
	{
		object.render(shader);
	}
}

void ObjectHandlerer::createCube(glm::vec3 position, Assets::Textures tex)
{
	tempObject = Engine::staticObject(objects.size(), position, m_cubeVertices, m_cubeIndices);
	tempObject.setTexture(Assets::getTexture(tex));
	objects.push_back(tempObject);
}

void ObjectHandlerer::createPyramid(glm::vec3 position, Assets::Textures tex)
{
	tempObject = Engine::staticObject(objects.size(), position + glm::vec3(0.0f,-0.5f,0.0f), m_pyramidVertices, m_pyramidIndices);
	tempObject.setTexture(Assets::getTexture(tex));
	objects.push_back(tempObject);
}
