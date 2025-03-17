#pragma once
#include <vector>

#include "engine/render/ShaderClass.h"
#include "engine/object/Object.h"
#include "assets.h"

class ObjectHandlerer
{
public:
	ObjectHandlerer();

	void init();
	void render(Engine::Shader& shader);
private:
    void createCube(glm::vec3 position, Assets::Textures tex);
    void createPyramid(glm::vec3 position, Assets::Textures tex);
private:
    Engine::staticObject tempObject;
	std::vector<Engine::staticObject> objects;

    //CUBE
	std::vector<float> m_cubeVertices = {
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
    };;
    std::vector<unsigned int> m_cubeIndices = {
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

    //Pyramid
    std::vector<float> m_pyramidVertices = {
        // Positions         // Texture Coords
        // Base (Square)
        -0.5f, 0.0f,  0.5f,  0.0f, 0.0f,  // Bottom-left
         0.5f, 0.0f,  0.5f,  1.0f, 0.0f,  // Bottom-right
         0.5f, 0.0f, -0.5f,  1.0f, 1.0f,  // Top-right
        -0.5f, 0.0f, -0.5f,  0.0f, 1.0f,  // Top-left

        // Apex (Top point)
         0.0f, 1.0f,  0.0f,  0.5f, 0.5f   // Peak of the pyramid
    };
    std::vector<unsigned int> m_pyramidIndices = {
        // Base (two triangles)
        0, 1, 2,   // First triangle
        2, 3, 0,   // Second triangle

        // Side Faces (triangles)
        0, 1, 4,   // Front face
        1, 2, 4,   // Right face
        2, 3, 4,   // Back face
        3, 0, 4    // Left face
    };

};
