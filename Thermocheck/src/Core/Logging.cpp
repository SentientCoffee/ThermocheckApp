#include "tcpch.h"
#include "Core/Logging.h"
#include "GUI/ImGuiSink.h"

#include <spdlog/sinks/stdout_color_sinks.h>

std::shared_ptr<spdlog::logger> Logger::_logger = nullptr;

void Logger::init()
{
	std::vector<spdlog::sink_ptr> sinks;
#if TC_DEBUG || TC_RELEASE
	sinks.emplace_back(std::make_shared<spdlog::sinks::stdout_color_sink_mt>()); // stdout console
#endif
	sinks.emplace_back(std::make_shared<ImGuiSinkMT>());                         // ImGui console
	
	_logger = std::make_shared<spdlog::logger>("LOGGER", sinks.begin(), sinks.end());
	spdlog::register_logger(_logger);
	
	spdlog::set_pattern("%^[%H:%M:%S.%e - %l]: %v%$");
	_logger->set_level(spdlog::level::trace);
}

void Logger::shutdown() {
	spdlog::shutdown();
}
