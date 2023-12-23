// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_EVENTS_APPLICATION_EVENT_H
#define EGG_EVENTS_APPLICATION_EVENT_H

#include "eggpch.h"
#include "events/event.h"

namespace egg {

class WindowResizeEvent : public Event {
 public:
  WindowResizeEvent(unsigned int width, unsigned int height)
      : width_(width), height_(height) {}

  unsigned int GetWidth() const { return width_; }
  unsigned int GetHeight() const { return height_; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "WindowResizeEvent: " << width_ << ", " << height_;
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kWindowResize; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "WindowResize"; }

  int GetCategoryFlags() const override { return kEventCategoryApplication; }

 private:
  unsigned int width_, height_;
};

class WindowCloseEvent : public Event {
 public:
  WindowCloseEvent() {}

  static EventType GetStaticType() { return EventType::kWindowClose; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "WindowClose"; }

  int GetCategoryFlags() const override { return kEventCategoryApplication; }
};

class AppTickEvent : public Event {
 public:
  AppTickEvent() {}

  static EventType GetStaticType() { return EventType::kAppTick; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "AppTick"; }

  int GetCategoryFlags() const override { return kEventCategoryApplication; }
};

class AppUpdateEvent : public Event {
 public:
  AppUpdateEvent() {}

  static EventType GetStaticType() { return EventType::kAppUpdate; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "AppUpdate"; }

  int GetCategoryFlags() const override { return kEventCategoryApplication; }
};

class AppRenderEvent : public Event {
 public:
  AppRenderEvent() {}

  static EventType GetStaticType() { return EventType::kAppRender; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "AppRender"; }

  int GetCategoryFlags() const override { return kEventCategoryApplication; }
};

}  // namespace egg

#endif
