#pragma once
#include <memory>

#include "Log.h"
#include "game/Game.h"
#include "engine/core/deltaTime.h"
#include "engine/core/Window.h"
#include "engine/core/input.h"

class App
{
public:
	App();
	~App();
	void start();
	void run();
	void close();

	void inputs(GLFWwindow* window);
private:
	//ENGINE
	Engine::DeltaTime deltaTime;
	Engine::Input input;
	int m_windowWidth = 1600;
	int m_windowHeight = 900;
	std::unique_ptr<Engine::Window> m_window = std::make_unique<Engine::Window>();
	//GAME
	Game game;
};
