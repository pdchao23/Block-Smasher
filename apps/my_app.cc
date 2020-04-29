// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <Box2D/Box2D.h>
#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/app/App.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

using namespace ci;
using namespace ci::app;
using namespace std;

namespace myapp {

using cinder::app::KeyEvent;

b2Vec2 gravity(0.0f, 0.0f);
b2World world(gravity);

MyApp::MyApp() {}

void MyApp::setup() {
  sceneController.setup(world);
}

void MyApp::update() {
  sceneController.update();

  // step physics world
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);
}

void MyApp::draw() {
  gl::clear();
  sceneController.draw();
}  // namespace myapp

void MyApp::keyDown(KeyEvent event) {
  switch (event.getCode()) {
    case KeyEvent::KEY_LEFT:
    case KeyEvent::KEY_a: {
      sceneController.movePaddleLeft();
      break;
    }
    case KeyEvent::KEY_RIGHT:
    case KeyEvent::KEY_d: {
      sceneController.movePaddleRight();
      break;
    }
    case KeyEvent::KEY_DOWN:
    case KeyEvent::KEY_UP:
    case KeyEvent::KEY_w:
    case KeyEvent::KEY_s: {
      sceneController.stopPaddle();
      break;
    }
    case KeyEvent::KEY_SPACE: {
      sceneController.startGame();
      break;
    }
  }
}

}  // namespace myapp
