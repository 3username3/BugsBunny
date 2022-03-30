#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

//We want to create a Log class that wraps up spdlog, in order to make the use more hasslefree,
//as we don't want the spdlog API in our own engine or in case we might change the 
//logging library.

namespace BugsBunny
{
	class BB_API Log
	{
		public:
			static void Init();
		  
			inline static std::shared_ptr<spdlog::logger> &GetCoreLogger() {
				return s_CoreLogger;
			}
			inline static std::shared_ptr<spdlog::logger> &GetClientLogger() {
				return s_ClientLogger;
			}
		
		private:
		
			static std::shared_ptr<spdlog::logger> s_CoreLogger;
			static std::shared_ptr<spdlog::logger> s_ClientLogger;
		
	};
}

	//Core Log macros for my engine
#define BB_CORE_TRACE(...) ::BugsBunny::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define BB_CORE_INFO(...)  ::BugsBunny::Log::GetCoreLogger()->info(__VA_ARGS__)
#define BB_CORE_WARN(...)  ::BugsBunny::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define BB_CORE_ERROR(...) ::BugsBunny::Log::GetCoreLogger()->error(__VA_ARGS__)
#define BB_CORE_FATAL(...) ::BugsBunny::Log::GetCoreLogger()->fatal(__VA_ARGS__)

	//Client Log macros for client who uses the engine
#define BB_TRACE(...) ::BugsBunny::Log::GetClientLogger()->trace(__VA_ARGS__)
#define BB_INFO(...)  ::BugsBunny::Log::GetClientLogger()->info(__VA_ARGS__)
#define BB_WARN(...)  ::BugsBunny::Log::GetClientLogger()->warn(__VA_ARGS__)
#define BB_ERROR(...) ::BugsBunny::Log::GetClientLogger()->error(__VA_ARGS__)
#define BB_FATAL(...) ::BugsBunny::Log::GetClientLogger()->fatal(__VA_ARGS__)

#define BB_CORE_INFO
