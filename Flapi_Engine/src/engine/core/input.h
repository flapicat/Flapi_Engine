#pragma once
#include"Log.h"
#include"Window.h"

namespace Engine
{
	class Input
	{
	public:
		static bool IsKeyPressed(KeyCode key, GLFWwindow* window);

		static bool IsMouseButtonPressed(MouseCode button, GLFWwindow* window);
	};
}