#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>


namespace Engine
{
	class Window
	{
	public:
		Window();
		~Window();

		void createWindow(int Width, int Height, const char* Title);

		//ACCESORS
		int getWidth();
		int getHidth();
		GLFWwindow* getWindow();

	private:
		GLFWwindow* m_window;

		struct windowData
		{
			const char* title;
			int width;
			int height;
		};

		windowData m_Data;
	};
}