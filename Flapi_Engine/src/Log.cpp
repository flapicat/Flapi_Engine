#include "Log.h"

#include"spdlog/sinks/stdout_color_sinks.h"

std::shared_ptr<spdlog::logger> Log::m_EngineLogger;
std::shared_ptr<spdlog::logger> Log::m_GameLogger;

void Log::init()
{
	spdlog::set_pattern("%^[%T] %n: %v%$");
	m_EngineLogger = spdlog::stdout_color_mt("ENGINE");
	m_EngineLogger->set_level(spdlog::level::trace);

	m_GameLogger = spdlog::stdout_color_mt("GAME");
	m_GameLogger->set_level(spdlog::level::trace);
}
