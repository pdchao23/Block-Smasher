// Copyright (c) 2020 [Your Name]. All rights reserved.

#include "my_app.h"

#include <cinder/Font.h>
#include <cinder/Text.h>
#include <cinder/Vector.h>
#include <cinder/audio/audio.h>
#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include <cinder/app/App.h>

#include <Box2D/Box2D.h>

namespace myapp {

using cinder::app::KeyEvent;

MyApp::MyApp() { }

void MyApp::setup() {
  cinder::gl::enableDepthWrite();
  cinder::gl::enableDepthRead();

  // Create world in Box2D
  b2Vec2 gravity(0.0f, -10.0f);
  // Construct a world object, which will hold and simulate the rigid bodies.
  b2World world(gravity);

  // create ball
  b2BodyDef ballBodyDef;
  ballBodyDef.type = b2_dynamicBody;
  ballBodyDef.position.Set(0.0f, 4.0f);
  b2Body* ballBody = world.CreateBody(&ballBodyDef);

  //define shape
  b2CircleShape ballShape;
  // ballShape.m_radius();
  // TODO add circle start position

  //assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 1.0f;
  //ballFixture.friction = 0;

  // create paddle
  b2BodyDef paddleBodyDef;
  paddleBodyDef.type = b2_kinematicBody;
  ballBodyDef.position.Set(0.0f, 0.0f);
  b2Body* paddleBody = world.CreateBody(&paddleBodyDef);

  //define shape
  b2PolygonShape paddleShape;
  paddleShape.SetAsBox(1.0f, 1.0f);

  //assign to fixture
  b2FixtureDef paddleFixture;
  paddleFixture.shape = &paddleShape;
  ballFixture.density = 1.0f;
  //ballFixture.friction = 0;

  paddleBody->CreateFixture(&paddleFixture);

  // create block
  b2BodyDef blockBodyDef;
  blockBodyDef.type = b2_staticBody;
  blockBodyDef.position.Set(0.0f, 6.0f);
  b2Body* blockBody = world.CreateBody(&blockBodyDef);

  //define shape
  b2PolygonShape blockShape;
  blockShape.SetAsBox(1.0f, 1.0f);

  //assign to fixture
  b2FixtureDef blockFixture;
  blockFixture.shape = &blockShape;
  blockFixture.density = 1.0f;
  //ballFixture.friction = 0;

  blockBody->CreateFixture(&blockFixture);

}

void MyApp::update() { }

void MyApp::draw() { }

void MyApp::keyDown(KeyEvent event) { }

}  // namespace myapp
