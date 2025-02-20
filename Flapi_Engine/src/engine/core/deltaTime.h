#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{
	struct DeltaTime
	{
		float m_deltaTime = 0, m_lastFrame = 0;
		void updateDeltaTime();
		float getDeltaTime();
	};
}