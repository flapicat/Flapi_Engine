#include "App.h"

App::App()
{
}

App::~App()
{
}

void App::start()
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	m_window->createWindow(m_windowWidth, m_windowHeight, m_title);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED TO INIT GLAD\n";
		exit(-1);
	}
	glfwSetInputMode(m_window->data.getWindow(), GLFW_CURSOR, GLFW_CURSOR_DISABLED);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_BLEND);

	game.init();

	Engine::Debug::imGuiAPI.initImGui(m_window->data.getWindow());
}

void App::run()
{
	while (!glfwWindowShouldClose(m_window->data.getWindow()))
	{
		inputs(m_window->data.getWindow());

		glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		
		game.run();


		glfwSwapBuffers(m_window->data.getWindow());
		glfwPollEvents();
	}
}

void App::close()
{
	game.close();
	Engine::Debug::imGuiAPI.terminateImGui(m_window->data.getWindow());

	glfwTerminate();
}

void App::inputs(GLFWwindow* window)
{
	if (Engine::input.IsKeyPressed(Engine::Key::Escape, window))
	{
		if (!keyPressed) { 
			game.switchGameState();
			keyPressed = true;
		}
	}
	else if (Engine::input.IsKeyReleased(Engine::Key::Escape, window)) {
		keyPressed = false; 
	}

	game.input(window);
}

//---------------------------------------------------------
//*GAME KNOWS ABOUT ENGINE BUT ENGINE DONT KNOW ABOUT GAME*
//---------------------------------------------------------
