#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "KeyCodes.h"
#include "MouseCodes.h"

//------------------------------------------------------------------------------------------------------
// This class give you possibility to get an app informations such as:
// -mouse pos 
// -window size 
// -scroll offset
// -key pressed, released, repeat 
// -mouse button pressed, released
// !!! This class should not be used it was created to make window callbacks in window class,
// it`s recomendet to used only functions that returns values above!!!
//------------------------------------------------------------------------------------------------------

namespace Engine
{
	class DataClass
	{
	public:
		//MOUSE POS
		void setMouseX(double X) { data.mouseX = X; }
		void setMouseY(double Y) { data.mouseY = Y; }
		inline void setMousePos(double X, double Y) { data.mouseX = X; data.mouseY = Y; }
		glm::vec2 getMousePos() { return glm::vec2(data.mouseX, data.mouseY); }
		
		//SCROLL OFFSET
		void setScrollX(double X) { data.scrollX = X; }
		void setScrollY(double Y) { data.scrollY = Y; }
		void setScrollOffset(double X, double Y) { data.scrollX = X; data.scrollY = Y; }
		glm::vec2 getScrollOffset() { return glm::vec2(data.scrollX, data.scrollY); }
		
		//WINDOW HEIGHT WIDTH
		void setWindowWidth(int width) { data.windowWidth = width; }
		void setWindowHeight(int height) { data.windowHeight = height; }
		int getWindowWidth() { return data.windowWidth; }
		int getWindowHeight() { return data.windowHeight; }

		//KEY PRESSED RELEASED REPEAT
		void setKeyPressed(KeyCode key) { data.keyCodePressed = key; };
		void setKeyReleased(KeyCode key) { data.keyCodeReleased = key; };
		void setKeyRepeated(KeyCode key) { data.keyCodeRepeated = key; };

		//MOUSE BUTTON PRESSED RELEASED
		void setMouseButtonPressed(MouseCode button) { data.mouseButtonPressed = button; };
		void setMouseButtonReleased(MouseCode button) { data.mouseButtonReleased = button; };
	private:
		struct Data
		{
		public:
			double mouseX = 0, mouseY = 0;
			double scrollX = 0, scrollY = 0;
			int windowWidth = 0, windowHeight = 0;
			KeyCode keyCodePressed, keyCodeReleased, keyCodeRepeated;
			MouseCode mouseButtonPressed, mouseButtonReleased;
		};
		inline static struct Data data;
	};
	inline static DataClass data;
}