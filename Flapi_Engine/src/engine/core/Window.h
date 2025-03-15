#pragma once
#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include"Log.h"
#include "KeyCodes.h"
#include "MouseCodes.h"

namespace Engine
{
	class Window
	{
	public:
		Window();
		~Window();

		void centerWindow();
		void createWindow(int Width, int Height, const char* Title);

		struct Data
		{
		public:
			friend class Window;
			//WINDOW
			GLFWwindow* getWindow() { return data.window; };
			int getWindowWidth() { return data.windowWidth; }
			int getWindowHeight() { return data.windowHeight; }
			//MOUSE
			glm::vec2 getMousePos() { return glm::vec2(data.mouseX, data.mouseY); }
			glm::vec2 getMouseOffset() { return glm::vec2(data.xMouseOffset, data.yMouseOffset); }
			glm::vec2 getMouseLast() { return glm::vec2(data.lastX, data.lastY); }
			bool getMouseFirst() { return data.firstMouse; }
			//SCROLL
			glm::vec2 getScrollOffset() { return glm::vec2(data.scrollX, data.scrollY); }
			//DATA
			glm::mat4 getProjection() { return glm::ortho(0.0f, static_cast<float>(getWindowWidth()), 0.0f, static_cast<float>(getWindowHeight())); }
			//BOOLS
			void setMouseMoved(bool x) { data.mouseMoved = x; }
			bool getMouseMoved() { return data.mouseMoved; }
		private:
			//MOUSE
			double mouseX = 0, mouseY = 0;
			double xMouseOffset = 0, yMouseOffset = 0;
			float lastX = 800.0f / 2.0, lastY = 600.0 / 2.0;
			bool firstMouse = true;
			//SCROLL
			double scrollX = 0, scrollY = 0;
			//WINDOW
			GLFWwindow* window = nullptr;
			int windowWidth = 0, windowHeight = 0;
			//KEYCODES
			KeyCode keyCodePressed, keyCodeReleased, keyCodeRepeated;
			MouseCode mouseButtonPressed, mouseButtonReleased;
			//BOOLS
			bool mouseMoved = false;
		};
		inline static struct Data data;	
	};
}