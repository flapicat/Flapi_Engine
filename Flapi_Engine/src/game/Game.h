#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <Log.h>

#include "engine/core/deltaTime.h"
#include "engine/core/Window.h"
#include "engine/core/input.h"
#include "engine/core/Camera.h"

#include "engine/render/ShaderClass.h"
#include "engine/render/Texture.h"
#include "engine/render/Text.h"

#include "engine/debug/ImGuiAPI.h"

#include "entity/Entity.h"

enum gameState
{
	MENU,
	GAME
};

class Game
{
public:
	Game();
	~Game();

	void init();
	void run();
	void update();
	void render();
	void input(GLFWwindow* window);
	void close();

	void switchGameState();
	void ImGuiMain();
private:
	//ENGINE
	Engine::TextClass m_text;
	Engine::Texture m_defaultTexture;
	Engine::Shader m_shader2D;
	Engine::Shader m_shader3D;
	Engine::Shader m_shaderText;

	//GAME
	gameState m_gameState;
	Engine::Camera m_camera;
	Entity m_testEntity;
};

