#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include"imgui.h"
#include"imgui_impl_glfw.h"
#include"imgui_impl_opengl3.h"

namespace Engine
{
	namespace Debug
	{
		class ImGuiAPI
		{
		public:
			ImGuiAPI() {};
			void initImGui(GLFWwindow* window);
			void terminateImGui(GLFWwindow* window);
			void resetImGui(GLFWwindow* window);
		};
		static inline ImGuiAPI imGuiAPI;
	}
}