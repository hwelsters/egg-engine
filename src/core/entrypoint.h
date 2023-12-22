// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_CORE_ENTRYPOINT_H
#define EGG_CORE_ENTRYPOINT_H

#include "core/application.h"
#include "core/log.h"

extern egg::Application* egg::CreateApplication();

int main(int, char*[]) {
  egg::Log::Init();

  egg::Application* application = egg::CreateApplication();
  application->Run();
  delete application;
}

#endif
