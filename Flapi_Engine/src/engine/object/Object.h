#pragma once
#include <iostream>
#include <vector>
#include "Log.h"

#include "engine/render/ShaderClass.h"
#include "engine/render/Texture.h"
#include "engine/render/VAO.h"
#include "engine/render/VBO.h"
#include "engine/render/EBO.h"

//--------------------------------------------------------------------
//This class was desine for making static object that are NOT moving
//--------------------------------------------------------------------

namespace Engine
{
	class staticObject
	{
	public:
		staticObject() {};
		staticObject(unsigned int ID);
		staticObject(unsigned int ID, glm::vec3 position);
		staticObject(unsigned int ID, glm::vec3 position, std::vector<float> vertices);
		staticObject(unsigned int ID, glm::vec3 position, std::vector<float> vertices, std::vector<unsigned int> m_indices);

		void render(Shader& shader);

		unsigned int getID() const { return m_ID; }
		void setTexture(Engine::Texture tex) { m_texture = tex; };
	private:
		void init();
	private:
		unsigned int m_ID = -1;
		glm::vec3 m_position = { 0.0,0.0,0.0 };

		std::vector<float> m_vertices;
		std::vector<unsigned int> m_indices;

		Engine::Texture m_texture;

		Engine::VAO vao;
		Engine::VBO vbo;
		Engine::EBO ebo;
	};

}