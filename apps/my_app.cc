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

MyApp::MyApp() {}

void MyApp::setup() {
  b2Vec2 gravity(0.0f, 10.0f);
  b2World world(gravity);
}

void MyApp::update() {}

void MyApp::draw() {
  gl::clear();
  gl::drawSolidRect(Rectf(0, 0, 100, 100));

}  // namespace myapp

void MyApp::keyDown(KeyEvent event) {}

}  // namespace myapp
