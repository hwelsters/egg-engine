// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_CORE_LOG_H
#define EGG_CORE_LOG_H

// The order of imports matter.
// spdlog must be imported before fmt and stdout_color_sinks.
#include <spdlog/spdlog.h>
#include <spdlog/fmt/ostr.h>
#include <spdlog/sinks/stdout_color_sinks.h>

#include <memory>

namespace egg {

class Log {
 public:
  static void Init();

  inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {
    return coreLogger_;
  }

  inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {
    return clientLogger_;
  }

 private:
  static std::shared_ptr<spdlog::logger> coreLogger_;
  static std::shared_ptr<spdlog::logger> clientLogger_;
};

}  // namespace egg

// Macros were used for logging to make it easier to remove in distribution.
// This just prevents us from writing tons of ifdef ... endif blocks
// Core logging
#define EGG_CORE_FATAL(...) ::egg::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define EGG_CORE_ERROR(...) ::egg::Log::GetCoreLogger()->error(__VA_ARGS__)
#define EGG_CORE_WARN(...) ::egg::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define EGG_CORE_INFO(...) ::egg::Log::GetCoreLogger()->info(__VA_ARGS__)
#define EGG_CORE_TRACE(...) ::egg::Log::GetCoreLogger()->trace(__VA_ARGS__)

// Client logging
#define EGG_FATAL(...) ::egg::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define EGG_ERROR(...) ::egg::Log::GetClientLogger()->error(__VA_ARGS__)
#define EGG_WARN(...) ::egg::Log::GetClientLogger()->warn(__VA_ARGS__)
#define EGG_INFO(...) ::egg::Log::GetClientLogger()->info(__VA_ARGS__)
#define EGG_TRACE(...) ::egg::Log::GetClientLogger()->trace(__VA_ARGS__)

#endif
