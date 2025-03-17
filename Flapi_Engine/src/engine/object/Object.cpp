#include "Object.h"

namespace Engine
{
	staticObject::staticObject(unsigned int ID)
		:m_ID(ID) {
		init();
	}

	staticObject::staticObject(unsigned int ID, glm::vec3 position)
		:m_ID(ID), m_position(position){
		init();
	}

	staticObject::staticObject(unsigned int ID, glm::vec3 position, std::vector<float> vertices)
		:m_ID(ID), m_position(position), m_vertices(vertices){
		init();
	}

	staticObject::staticObject(unsigned int ID, glm::vec3 position, std::vector<float> vertices, std::vector<unsigned int> indices)
		:m_ID(ID), m_position(position), m_vertices(vertices), m_indices(indices){
		init();
	}

	void staticObject::init()
	{
		if (m_vertices.empty() == false)
		{
			vao.createVAO();
			vao.bind();

			vbo.attachVertices(m_vertices.data(), m_vertices.size() * sizeof(float));
			if (m_indices.empty() == false)
			{
				ebo.attachIndices(m_indices.data(), m_indices.size() * sizeof(unsigned int));
			}

			vao.linkVBO(vbo, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
			vao.linkVBO(vbo, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

			vao.unbind();
		}
		else
		{
			LOG_ENGINE_WARN("FAILD TO LOAD VERTICES FOR OBJECT ID: {}", m_ID);
		}
	}

	void staticObject::render(Shader& shader)
	{
		if (m_texture.getTexture() != NULL){
			m_texture.bindTexture2D();
		}
		else{
			m_texture.unbindTexture2D();
		}
		vao.bind();

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, m_position);
		shader.setMat4("model", model);

		glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
	}
}