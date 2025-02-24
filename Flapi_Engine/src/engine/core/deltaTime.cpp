#include "deltaTime.h"

namespace Engine
{
	void DeltaTime::updateDeltaTime()
	{
		float currentFrame = glfwGetTime();
		m_deltaTime = currentFrame - m_lastFrame;
		m_lastFrame = currentFrame;
	}

	float DeltaTime::getDeltaTime()
	{
		return m_deltaTime;
	}
}