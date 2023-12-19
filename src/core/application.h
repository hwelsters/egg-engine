// Copyright 2023 hwelsters

#pragma once
#ifndef EGG_CORE_APPLICATION_H
#define EGG_CORE_APPLICATION_H

namespace egg {

class Application {
 public:
  Application();
  ~Application();

  void Run();

 private:
};

// Will be defined by the user.
Application *CreateApplication();

}  // namespace egg

#endif
