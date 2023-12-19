// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_CORE_ENTRYPOINT_H
#define EGG_CORE_ENTRYPOINT_H

#include "core/application.h"

extern egg::Application* egg::CreateApplication();

int main(int, char*[]) {
  egg::Application* application = egg::CreateApplication();
  application->Run();
  delete application;
}

#endif
