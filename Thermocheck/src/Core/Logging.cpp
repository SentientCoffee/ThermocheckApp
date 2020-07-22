#include "tcpch.h"
#include "Core/Logging.h"

#include <memory>
#include <spdlog/sinks/stdout_color_sinks.h>

Ref<spdlog::logger> Logger::_logger = nullptr;

void Logger::init()
{
#if TC_DEBUG || TC_RELEASE

	spdlog::set_pattern("%^[%H:%M:%S.%e - %l]: %v%$");
	_logger = spdlog::stdout_color_mt("LOGGER");
	_logger->set_level(spdlog::level::trace);
	
#endif
}

void Logger::shutdown() {
#if TC_DEBUG || TC_RELEASE
	
	spdlog::shutdown();
	
#endif
}

Ref<spdlog::logger> Logger::getLogger() { return _logger; }