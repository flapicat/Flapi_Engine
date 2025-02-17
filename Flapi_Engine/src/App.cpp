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

	m_window->createWindow(1600, 900, "GAME");

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
		//DELTA TIME
		float currentFrame = glfwGetTime();
		m_deltaTime = currentFrame - m_lastFrame;
		m_lastFrame = currentFrame;

		input(m_window->getWindow());

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

void App::input(GLFWwindow* window)
{
	if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, true);
	}
}

//---------------------------------------------------------
//*GAME KNOWS ABOUT ENGINE BUT ENGINE DONT KNOW ABOUT GAME*
//---------------------------------------------------------