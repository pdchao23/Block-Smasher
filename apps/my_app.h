// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/Timeline.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"
//#include "cinder/CinderImGui.h"
//
//#include "cinder/audio/Utilities.h"
//#include "AudioController.h"
//
//#include "Config.h"
#include "blocksmasher/SceneController.h"
#include <cinder/app/App.h>
#include <Box2D/Box2D.h>

namespace myapp {

class MyApp : public cinder::app::App {
 public:
  MyApp();
  void setup() override;
  void update() override;
  void draw() override;
  void keyDown(cinder::app::KeyEvent) override;

 private:
  SceneController sceneController;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
