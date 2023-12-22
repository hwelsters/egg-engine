// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_EVENTS_KEY_EVENT_H
#define EGG_EVENTS_KEY_EVENT_H

#include <sstream>
#include <string>

#include "events/event.h"

namespace egg {

class KeyEvent : public Event {
 public:
  inline int GetKeyCode() const { return keycode_; }
  int GetCategoryFlags() const override {
    return kEventCategoryKeyboard | kEventCategoryInput;
  }

 protected:
  explicit KeyEvent(int keycode) : keycode_(keycode) {}
  int keycode_;
};

class KeyPressedEvent : public KeyEvent {
 public:
  KeyPressedEvent(int keycode, int repeat_count)
      : KeyEvent(keycode), repeat_count_(repeat_count) {}

  inline int GetRepeatCount() const { return repeat_count_; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyPressedEvent: " << keycode_ << " (" << repeat_count_
       << " repeats)";
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kKeyPressed; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "KeyPressed"; }

 private:
  int repeat_count_;
};

class KeyReleasedEvent : public KeyEvent {
 public:
  explicit KeyReleasedEvent(int keycode) : KeyEvent(keycode) {}

  inline int GetRepeatCount() const { return repeat_count_; }

  std::string ToString() const override {
    std::stringstream ss;
    ss << "KeyReleasedEvent: " << keycode_ << " (" << repeat_count_
       << " repeats)";
    return ss.str();
  }

  static EventType GetStaticType() { return EventType::kKeyReleased; }
  EventType GetEventType() const override { return GetStaticType(); }
  const char* GetName() const override { return "KeyReleased"; }

 private:
  int repeat_count_;
};

}  // namespace egg

#endif
