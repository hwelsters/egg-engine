// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_EVENTS_MOUSE_EVENT_H
#define EGG_EVENTS_MOUSE_EVENT_H

#include <sstream>
#include <string>

#include "events/event.h"

namespace egg {

class MouseMovedEvent : public Event {
 public:
  MouseMovedEvent(float x, float y) : mouse_x_(x), mouse_y_(y) {}

  inline float GetX() const { return mouse_x_; }
  inline float GetY() const { return mouse_y_; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseMovedEvent: " << mouse_x_ << ", " << mouse_y_;
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kMouseMoved; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "MouseMoved"; }

  int GetCategoryFlags() const override {
    return kEventCategoryMouse | kEventCategoryInput;
  }

 private:
  float mouse_x_, mouse_y_;
};

class MouseScrolledEvent : public Event {
 public:
  MouseScrolledEvent(float x_offset, float y_offset)
      : x_offset_(x_offset), y_offset_(y_offset) {}

  inline float GetXOffset() const { return x_offset_; }
  inline float GetYOffset() const { return y_offset_; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseScrolledEvent: " << GetXOffset() << ", " << GetYOffset();
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kMouseScrolled; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "MouseScrolled"; }

  int GetCategoryFlags() const override {
    return kEventCategoryMouse | kEventCategoryInput;
  }

 private:
  float x_offset_, y_offset_;
};

class MouseButtonEvent : public Event {
 public:
  inline int GetMouseButton() const { return button_; }
  int GetCategoryFlags() const override {
    return kEventCategoryMouse | kEventCategoryInput;
  }

 protected:
  explicit MouseButtonEvent(int button) : button_(button) {}
  int button_;
};

class MouseButtonPressedEvent : public MouseButtonEvent {
 public:
  explicit MouseButtonPressedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonPressedEvent: " << button_;
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kMouseButtonPressed; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "MouseButtonPressed"; }
};

class MouseButtonReleasedEvent: public MouseButtonEvent {
 public:
  explicit MouseButtonReleasedEvent(int button) : MouseButtonEvent(button) {}

  std::string ToString() const override {
    std::stringstream ss;
    ss << "MouseButtonReleasedEvent: " << button_;
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kMouseButtonReleased; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "MouseButtonReleased"; }
};

}  // namespace egg

#endif
