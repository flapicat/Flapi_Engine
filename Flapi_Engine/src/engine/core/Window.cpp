#include "Window.h"

namespace Engine
{
	Window::Window()
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(m_window);
	}

	GLFWwindow* Window::getWindow()
	{
		return m_window;
	}

	void Window::createWindow(int Width, int Height, const char* Title)
	{
		//----------------------------------------------------
		// This funcion creates window and make callbacks 
		//----------------------------------------------------
		//WINDOW CREATE
		data.setWindowWidth(Width);
		data.setWindowHeight(Height);
		m_window = glfwCreateWindow(data.getWindowWidth(), data.getWindowHeight(), Title, NULL, NULL);
		if (m_window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(-1);
		}
		glfwMakeContextCurrent(m_window);

		//CALLBACKS
		glfwSetFramebufferSizeCallback(m_window, [](GLFWwindow* window, int width, int height) {
				glViewport(0, 0, width, height);
			});

		glfwSetCursorPosCallback(m_window, [](GLFWwindow* window, double xpos, double ypos) {
				data.setMousePos(xpos, ypos);
			});

		glfwSetScrollCallback(m_window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				data.setScrollOffset(xOffset, yOffset);
			});

		glfwSetWindowSizeCallback(m_window, [](GLFWwindow* window, int width, int height)
			{
				data.setWindowWidth(width);
				data.setWindowHeight(height);
			});

		glfwSetKeyCallback(m_window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					data.setKeyPressed(key);
					//LOG_ENGINE_INFO("Key pressed: {}", key);
					break;
				}
				case GLFW_RELEASE:
				{
					data.setKeyPressed(NULL);
					data.setKeyReleased(key);
					//LOG_ENGINE_INFO("key released: {}", key);
					break;
				}
				case GLFW_REPEAT:
				{
					data.setKeyRepeated(key);
					//LOG_ENGINE_INFO("key repeat: {}", key);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(m_window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					data.setMouseButtonPressed(button);
					//LOG_ENGINE_INFO("Key pressed: {}", button);
					break;
				}
				case GLFW_RELEASE:
				{
					data.setMouseButtonPressed(NULL);
					data.setMouseButtonReleased(button);
					//LOG_ENGINE_INFO("key released: {}", button);
					break;
				}
				}
			});
	}
}