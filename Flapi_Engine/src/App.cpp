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

	m_window->createWindow(m_windowWidth, m_windowHeight, "APPLICATION");

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "FAILED TO INIT GLAD\n";
		exit(-1);
	}

	game.init();
}

void App::run()
{
	while (!glfwWindowShouldClose(m_window->getWindow()))
	{
		deltaTime.updateDeltaTime();

		inputs(m_window->getWindow());

		glClearColor(0.2f, 0.3f, 0.3f, 0.1f);
		glClear(GL_COLOR_BUFFER_BIT);


		game.run();


		glfwSwapBuffers(m_window->getWindow());
		glfwPollEvents();
	}
}

void App::close()
{
	game.close();
	glfwTerminate();
}

void App::inputs(GLFWwindow* window)
{
	if (input.IsKeyPressed(Engine::Key::Escape, window))
	{
		glfwSetWindowShouldClose(window, true);
	}

	game.input(window);
}

//---------------------------------------------------------
//*GAME KNOWS ABOUT ENGINE BUT ENGINE DONT KNOW ABOUT GAME*
//---------------------------------------------------------
