#include "Window.h"

namespace Engine
{
	Window::Window()
	{
	}

	Window::~Window()
	{
		glfwDestroyWindow(data.window);
	}

	void Window::centerWindow()
	{
		const GLFWvidmode* mode = glfwGetVideoMode(glfwGetPrimaryMonitor());

		// Calculate the window position to center it
		int windowPosX = (mode->width - data.windowWidth) / 2;
		int windowPosY = (mode->height - data.windowHeight) / 2;

		glfwSetWindowPos(data.window, windowPosX, windowPosY);
	}

	void Window::createWindow(int Width, int Height, const char* Title)
	{
		//----------------------------------------------------
		// This funcion creates window and make callbacks 
		//----------------------------------------------------
		//WINDOW CREATE
		data.windowWidth = Width;
		data.windowHeight = Height;
		data.window = glfwCreateWindow(data.windowWidth, data.windowHeight, Title, NULL, NULL);
		if (data.window == NULL)
		{
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			exit(-1);
		}
		glfwMakeContextCurrent(data.window);

		//CALLBACKS
		glfwSetFramebufferSizeCallback(data.window, [](GLFWwindow* window, int width, int height) {
				glViewport(0, 0, width, height);
			});

		glfwSetCursorPosCallback(data.window, [](GLFWwindow* window, double xpos, double ypos) {
			data.mouseMoved = true;
			data.mouseX = xpos;
			data.mouseY = ypos;

				if (data.firstMouse)
				{
					data.lastX = xpos;
					data.lastY = ypos;
					data.firstMouse = false;
				}
				data.xMouseOffset = xpos - data.lastX;
				data.yMouseOffset = data.lastY - ypos;
				
				data.lastX = xpos;
				data.lastY = ypos;
			});

		glfwSetScrollCallback(data.window, [](GLFWwindow* window, double xOffset, double yOffset)
			{
				data.scrollX = xOffset;
				data.scrollY = yOffset;
			});

		glfwSetWindowSizeCallback(data.window, [](GLFWwindow* window, int width, int height)
			{
				data.windowWidth = width; 
				data.windowHeight = height;
			});

		glfwSetKeyCallback(data.window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					data.keyCodePressed = key;
					//LOG_ENGINE_INFO("Key pressed: {}", key);
					break;
				}
				case GLFW_RELEASE:
				{
					data.keyCodePressed = NULL;
					data.keyCodeReleased = key;
					//LOG_ENGINE_INFO("key released: {}", key);
					break;
				}
				case GLFW_REPEAT:
				{
					data.keyCodeRepeated =key;
					//LOG_ENGINE_INFO("key repeat: {}", key);
					break;
				}
				}
			});

		glfwSetMouseButtonCallback(data.window, [](GLFWwindow* window, int button, int action, int mods)
			{
				switch (action)
				{
				case GLFW_PRESS:
				{
					data.mouseButtonPressed =button;
					//LOG_ENGINE_INFO("Key pressed: {}", button);
					break;
				}
				case GLFW_RELEASE:
				{
					data.mouseButtonPressed = NULL;
					data.mouseButtonReleased = button;
					//LOG_ENGINE_INFO("key released: {}", button);
					break;
				}
				}
			});
	}
}