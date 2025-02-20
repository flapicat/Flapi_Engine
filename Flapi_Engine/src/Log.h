#pragma once

#include"spdlog/spdlog.h"
#include"spdlog/fmt/ostr.h"

class Log
{
public:
	static void init();
	inline static std::shared_ptr<spdlog::logger>& GetEngineLogger() { return m_EngineLogger; }
	inline static std::shared_ptr<spdlog::logger>& GetGameLogger() { return m_GameLogger; }
private:
	static std::shared_ptr<spdlog::logger> m_EngineLogger;
	static std::shared_ptr<spdlog::logger> m_GameLogger;
};


//CLIENT LOG MACROS
#define LOG_ENGINE_TRACE(...)     ::Log::GetEngineLogger()->trace(__VA_ARGS__);
#define LOG_ENGINE_INFO(...)      ::Log::GetEngineLogger()->info(__VA_ARGS__);
#define LOG_ENGINE_WARN(...)      ::Log::GetEngineLogger()->warn(__VA_ARGS__);
#define LOG_ENGINE_ERROR(...)     ::Log::GetEngineLogger()->error(__VA_ARGS__);
#define LOG_ENGINE_FATAL(...)     ::Log::GetEngineLogger()->fatal(__VA_ARGS__);

//CLIENT LOG MACROS
#define LOG_GAME_TRACE(...)     ::Log::GetGameLogger()->trace(__VA_ARGS__);
#define LOG_GAME_INFO(...)      ::Log::GetGameLogger()->info(__VA_ARGS__);
#define LOG_GAME_WARN(...)      ::Log::GetGameLogger()->warn(__VA_ARGS__);
#define LOG_GAME_ERROR(...)     ::Log::GetGameLogger()->error(__VA_ARGS__);
#define LOG_GAME_FATAL(...)     ::Log::GetGameLogger()->fatal(__VA_ARGS__);