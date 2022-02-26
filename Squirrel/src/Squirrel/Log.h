#pragma once

#include <memory>
#include "Core.h"
#include "spdlog/spdlog.h"

namespace Squirrel {


	class SQUIRREL_API Log
	{
	public:

		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return coreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return clientLogger; }

	private:

		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;

	};
}

//Core logging macros
#define SQ_CORE_ERROR(...) ::Squirrel::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SQ_CORE_WARN(...) ::Squirrel::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SQ_CORE_INFO(...) ::Squirrel::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SQ_CORE_TRACE(...) ::Squirrel::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SQ_CORE_FATAL(...) ::Squirrel::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client logging macros
#define SQ_ERROR(...) ::Squirrel::Log::GetClientLogger()->error(__VA_ARGS__)
#define SQ_WARN(...) ::Squirrel::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SQ_INFO(...) ::Squirrel::Log::GetClientLogger()->info(__VA_ARGS__)
#define SQ_TRACE(...) ::Squirrel::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SQ_FATAL(...) ::Squirrel::Log::GetClientLogger()->fatal(__VA_ARGS__)
