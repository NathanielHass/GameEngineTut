#pragma once
#include <memory>

#include "Core.h"

#include "spdlog\spdlog.h"

namespace GE
{
	class GE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

/* Defining Macros to use the logger helps make the API easier to use,
   But it also makes it easier to remove these functions from the
   release build. Macros can be null defined, whereas function calls
   would need to be manually removed. 
*/
// Core Log Macros
#define GE_CORE_TRACE(...)	::GE::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GE_CORE_INFO(...)	::GE::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GE_CORE_WARN(...)	::GE::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GE_CORE_ERROR(...)	::GE::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GE_CORE_FATAL(...)	::GE::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Macros
#define GE_TRACE(...)		::GE::Log::GetClientLogger()->trace(__VA_ARGS__)
#define GE_INFO(...)		::GE::Log::GetClientLogger()->info(__VA_ARGS__)
#define GE_WARN(...)		::GE::Log::GetClientLogger()->warn(__VA_ARGS__)
#define GE_ERROR(...)		::GE::Log::GetClientLogger()->error(__VA_ARGS__)
#define GE_FATAL(...)		::GE::Log::GetClientLogger()->fatal(__VA_ARGS__)
