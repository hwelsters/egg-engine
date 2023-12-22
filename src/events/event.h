// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_EVENTS_EVENT_H
#define EGG_EVENTS_EVENT_H

#include <functional>
#include <string>

#include "core/core.h"

namespace egg {

enum class EventType {
  kNone = 0,

  /* ======================================
  Window events
  ====================================== */
  kWindowClose,
  kWindowResize,
  kWindowFocus,
  kWindowLostFocus,
  kWindowMoved,

  /* ======================================
  Application events
  ====================================== */
  kAppTick,
  kAppUpdate,
  kAppRender,
  kKeyPressed,
  kKeyReleased,

  /* ======================================
  Mouse events
  ====================================== */
  kMouseButtonPressed,
  kMouseButtonReleased,
  kMouseMoved,
  kMouseScrolled
};

enum EventCategory {
  kNone = 0,
  kEventCategoryApplication = BIT(0),
  kEventCategoryInput = BIT(1),
  kEventCategoryKeyboard = BIT(2),
  kEventCategoryMouse = BIT(3),
  kEventCategoryMouseButton = BIT(4)
};

class Event {
  friend class EventDispatcher;

 public:
  virtual EventType GetEventType() const = 0;
  virtual const char* GetName() const = 0;
  virtual int GetCategoryFlags() const = 0;
  virtual std::string ToString() const { return GetName(); }

  inline bool IsInCategory(EventCategory category) {
    return GetCategoryFlags() & category;
  }

 protected:
  bool handled_ = false;
};

class EventDispatcher {
  template <typename T>
  using EventFn = std::function<bool(T&)>;

 public:
  explicit EventDispatcher(Event& event) : event_(event) {}

  template <typename T>
  bool Dispatch(EventFn<T> func) {
    if (event_.GetEventType() == T::GetStaticType()) {
      event_.handled_ = func(*reinterpret_cast<T*>(&event_));
      return true;
    }
    return false;
  }

 private:
  Event& event_;
};

inline std::ostream& operator<<(std::ostream& os, const Event& e) {
  return os << e.ToString();
}

}  // namespace egg

#endif
