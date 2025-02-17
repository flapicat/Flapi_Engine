#pragma once
#include <memory>
#include <engine/Window.h>

#include "game/Game.h"

class App
{
public:
	App();
	~App();
	void start();
	void run();
	void close();

	void input(GLFWwindow* window);
private:
	Game game;
	float m_deltaTime = 0, m_lastFrame = 0;
	std::unique_ptr<Engine::Window> m_window = std::make_unique<Engine::Window>();
};
