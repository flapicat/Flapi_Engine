#include "input.h"
#include "App.h"

namespace Engine
{
	bool Input::IsKeyPressed(KeyCode key, GLFWwindow* window)
	{
		if (glfwGetKey(window, key) == GLFW_PRESS)
		{
			return true;
		}
		return false;
	}

	bool Input::IsKeyReleased(KeyCode key, GLFWwindow* window)
	{
		if (glfwGetKey(window, key) == GLFW_RELEASE)
		{
			return true;
		}
		return false;
	}

	bool Input::IsMouseButtonPressed(MouseCode button, GLFWwindow* window)
	{
		if (glfwGetMouseButton(window, button) == GLFW_PRESS)
		{
			return true;
		}
		return false;
	}
}