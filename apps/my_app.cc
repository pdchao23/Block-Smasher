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
using cinder::Color;
using cinder::ColorA;
using cinder::Rectf;
using cinder::TextBox;
using cinder::app::KeyEvent;
using namespace ci::app;
using namespace std;

namespace myapp {

// Set up the world
b2Vec2 gravity(0.0f, 0.0f);
b2World world(gravity);

MyApp::MyApp() {}

void MyApp::setup() {
  // Set up Box2d world
  sceneController.setup(world);
  world.SetContactListener(&sceneController);

  // Set up background music
  cinder::audio::SourceFileRef sourceFile1 =
      cinder::audio::load(cinder::app::loadAsset("ChillingMusic.wav"));
  backgroundSound = cinder::audio::Voice::create(sourceFile1);
  backgroundSound->start();
}

void MyApp::update() {
  if (sceneController.getGameOver()) {
    return;
  }

  // step physics world
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);

  sceneController.update();
  backgroundSound->start();
}

void MyApp::drawGameOver() {
  const cinder::vec2 center = vec2(150, 375);
  const cinder::ivec2 size = {500, 50};
  const Color color = Color::black();
  string win;
  Color backGroundColor;
  if (sceneController.getWin()) {
    win = "You Won!";
    backGroundColor = Color(0, 0, 1);
  } else {
    win = "You Lost!";
    backGroundColor = Color(1, 0, 0);
  }
  auto box = TextBox()
                 .alignment(TextBox::CENTER)
                 .font(cinder::Font("Arial", 50))
                 .size(size)
                 .color(color)
                 .backgroundColor(backGroundColor)
                 .text(win);

  const auto box_size = box.getSize();
  const cinder::vec2 locp = {center};
  const auto surface = box.render();
  const auto texture = cinder::gl::Texture::create(surface);
  cinder::gl::draw(texture, locp);
}

void MyApp::draw() {
  cinder::gl::enableAlphaBlending();

  // print game over page if someone won or lost
  if (sceneController.getGameOver()) {
    drawGameOver();
    return;
  }

  gl::clear();
  sceneController.draw();
}

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
