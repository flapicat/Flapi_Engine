#include "Entity.h"

Entity::Entity()
{
}

void Entity::init()
{
	m_vertices = {
        // Positions         // Texture Coords
        // Front face
        -0.5f, -0.5f,  0.5f,  0.0f,  0.0f, // Bottom-left
         0.5f, -0.5f,  0.5f,  1.0f,  0.0f, // Bottom-right
         0.5f,  0.5f,  0.5f,  1.0f,  1.0f, // Top-right
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f, // Top-left 

        // Back face
        -0.5f, -0.5f, -0.5f,  1.0f,  0.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  0.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  1.0f,  1.0f,

        // Left face
        -0.5f, -0.5f, -0.5f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  1.0f,  0.0f,
        -0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
        -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,

        // Right face
        0.5f, -0.5f, -0.5f,  1.0f,  0.0f,
        0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        0.5f,  0.5f,  0.5f,  0.0f,  1.0f,
        0.5f,  0.5f, -0.5f,  1.0f,  1.0f,

        // Top face
        -0.5f,  0.5f, -0.5f,  0.0f,  0.0f,
         0.5f,  0.5f, -0.5f,  1.0f,  0.0f,
         0.5f,  0.5f,  0.5f,  1.0f,  1.0f,
        -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,

        // Bottom face
        -0.5f, -0.5f, -0.5f,  1.0f,  1.0f,
         0.5f, -0.5f, -0.5f,  0.0f,  1.0f,
         0.5f, -0.5f,  0.5f,  0.0f,  0.0f,
        -0.5f, -0.5f,  0.5f,  1.0f,  0.0f 
    };
	m_indices = {
        // Front face
        0, 1, 2, 2, 3, 0,
        // Back face
        4, 5, 6, 6, 7, 4,
        // Left face
        8, 9, 10, 10, 11, 8,
        // Right face
        12, 13, 14, 14, 15, 12,
        // Top face
        16, 17, 18, 18, 19, 16,
        // Bottom face
        20, 21, 22, 22, 23, 20 
    };

    vao.createVAO();
    vao.bind();

    vbo.attachVertices(m_vertices.data() , m_vertices.size() * sizeof(float));
    ebo.attachIndices(m_indices.data(), m_indices.size() * sizeof(unsigned int));

    vao.linkVBO(vbo, 0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);
    vao.linkVBO(vbo, 1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
    
    vao.unbind();
}

void Entity::render(Engine::Shader& shader)
{
    vao.bind();

    glm::mat4 model = glm::mat4(1.0f);
    model = glm::translate(model, m_position);
    shader.setMat4("model", model);

    glDrawElements(GL_TRIANGLES, m_indices.size(), GL_UNSIGNED_INT, 0);
}
