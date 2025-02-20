#include "deltaTime.h"

void Engine::DeltaTime::updateDeltaTime()
{
	float currentFrame = glfwGetTime();
	m_deltaTime = currentFrame - m_lastFrame;
	m_lastFrame = currentFrame;
}

float Engine::DeltaTime::getDeltaTime()
{
	return m_deltaTime;
}
