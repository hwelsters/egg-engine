// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_CORE_ENTRYPOINT_H
#define EGG_CORE_ENTRYPOINT_H

#include "core/application.h"
#include "core/log.h"

extern egg::Application* egg::CreateApplication();

int main(int, char*[]) {
  egg::Log::Init();
  egg::Log::GetCoreLogger()->warn("Let's get this core party started!");
  egg::Log::GetClientLogger()->info("Let's get this client party started!");

  egg::Application* application = egg::CreateApplication();
  application->Run();
  delete application;
}

#define EGG_CORE_TRACE(...) egg::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define EGG_CORE_TRACE(...) egg::Log::GetCoreLogger()->trace(__VA_ARGS__)

#endif
