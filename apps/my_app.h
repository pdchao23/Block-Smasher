// Copyright (c) 2020 CS126SP20. All rights reserved.

#ifndef FINALPROJECT_APPS_MYAPP_H_
#define FINALPROJECT_APPS_MYAPP_H_

#include <Box2D/Box2D.h>
#include <cinder/app/App.h>
#include <cinder/audio/audio.h>

#include "blocksmasher/SceneController.h"
#include "cinder/Rand.h"
#include "cinder/Text.h"
#include "cinder/Timeline.h"
#include "cinder/app/App.h"
#include "cinder/app/RendererGl.h"
#include "cinder/gl/Texture.h"
#include "cinder/gl/gl.h"

namespace myapp {

/**
 * An app that simulates a brick breaker game and uses cinder and Box2d
 */
class MyApp : public cinder::app::App {
 public:
  MyApp();

  /**
   * Set up the world, contact listener and background music
   */
  void setup() override;

  /**
   * Update the simulated world and scenecontroller
   */
  void update() override;

  /**
   * Draw the game over page which states if the player won or lost
   */
  void drawGameOver();

  /**
   * Draw game over page if over or else call scenecontroller's draw
   */
  void draw() override;

  /**
   * Depending on the key pressed, move paddle left or right
   *
   * param  KeyEvent    The event based on what key was pressed
   */
  void keyDown(cinder::app::KeyEvent) override;

 private:
  SceneController sceneController;
  cinder::audio::VoiceRef backgroundSound;
  bool printedGameOver;
};

}  // namespace myapp

#endif  // FINALPROJECT_APPS_MYAPP_H_
