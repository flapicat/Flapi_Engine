#pragma once
#include <iostream>
#include <vector>

#include "engine/render/ShaderClass.h"
#include "engine/render/VAO.h"
#include "engine/render/VBO.h"
#include "engine/render/EBO.h"


class Entity
{
public:
	Entity();

	void init();
	void render(Engine::Shader& shader);
public:

private:

private:
	glm::vec3 m_position = { 0.0,0.0,0.0 };

	std::vector<float> m_vertices;
	std::vector<unsigned int> m_indices;

	Engine::VAO vao;
	Engine::VBO vbo;
	Engine::EBO ebo;
};

