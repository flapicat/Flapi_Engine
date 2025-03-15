#pragma once
#include <glad/glad.h>
#include <GLFW/glfw3.h>

namespace Engine
{
	class DeltaTime
	{
	public:
		void updateDeltaTime();
		float getDeltaTime();
	private:
		float m_deltaTime = 0, m_lastFrame = 0;
	};
	static inline DeltaTime deltaTime;
}
