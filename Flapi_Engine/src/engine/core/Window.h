#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"Log.h"
#include "data.h"

namespace Engine
{
	class Window
	{
	public:
		Window();
		~Window();

		void createWindow(int Width, int Height, const char* Title);
		GLFWwindow* getWindow();

	private:
		GLFWwindow* m_window;
	};
}