// Copyright 2023 hwelsters

#include "core/application.h"

#include "core/log.h"
#include "events/application_event.h"

namespace egg {

Application::Application() {}
Application::~Application() {}

void Application::Run() {
  egg::WindowResizeEvent e(1280, 720);
  if (e.IsInCategory(kEventCategoryApplication)) {
    EGG_CORE_INFO(e);
  }
  if (e.IsInCategory(kEventCategoryInput)) {
    EGG_ERROR(e);
  }
  EGG_TRACE("Trace log! Application is running!");
  EGG_CORE_ERROR("Core error log! Application is RRADSAd!");
  while (true) {}
}

}  // namespace egg
