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

	int Window::getWidth()
	{
		return m_Data.width;
	}

	int Window::getHidth()
	{
		return m_Data.height;
	}

	GLFWwindow* Window::getWindow()
	{
		return m_window;
	}

	void Window::createWindow(int Width, int Height, const char* Title)
	{
		m_Data.title = Title;
		m_Data.width = Width;
		m_Data.height = Height;
		m_window = glfwCreateWindow(m_Data.width, m_Data.height, m_Data.title, NULL, NULL);
		if (m_window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(-1);
		}
		glfwMakeContextCurrent(m_window);
	}
}