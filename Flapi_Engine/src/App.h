#pragma once
#include <memory>

#include "Log.h"
#include "game/Game.h"
#include "engine/core/Window.h"
#include "engine/core/input.h"

#include "engine/debug/ImGuiAPI.h"

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
	bool keyPressed = false;
	//ENGINE
	int m_windowWidth = 1920;
	int m_windowHeight = 1080;
	const char* m_title= "APPLICATION";
	std::unique_ptr<Engine::Window> m_window = std::make_unique<Engine::Window>();

	//GAME
	Game game;
};
