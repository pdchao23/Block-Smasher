//
// Created by Preston Chao on 4/27/20.
//

#include "blocksmasher/SceneController.h"

#include <Box2D/Box2D.h>
#include "cinder/gl/gl.h"
#include <cinder/gl/draw.h>
#include <cinder/gl/wrapper.h>

#include "blocksmasher/Ball.h"

using namespace std;
using namespace ci;

SceneController::SceneController() {}

void SceneController::setup(b2World& w) {
  world = &w;
  setupBall();
  setupBlocks();
  setupPaddle();
  setupWalls();
}

void SceneController::update() {
  ball.update();
  paddle.update();
}

void SceneController::draw() {
  ball.draw();
  paddle.draw();
  for (Block b : blocks) {
    b.draw();
  }
}

void SceneController::setupWalls() {
//  b2BodyDef groundBodyDef;
//  groundBodyDef.position.Set(0.0f, -10.0f);
//  b2Body* groundBody = world->CreateBody(&groundBodyDef);
//  b2PolygonShape groundBox;
//
//  // The extents are the half-widths of the box.
//  groundBox.SetAsBox(50.0f, 10.0f);
//
//  // Add the ground fixture to the ground body.
//  groundBody->CreateFixture(&groundBox, 0.0f);
  //  // create block
  //  b2BodyDef blockBodyDef;
  //  blockBodyDef.type = b2_staticBody;
  //  blockBodyDef.position.Set(0.0f, 6.0f);
  //  b2Body* blockBody = world->CreateBody(&blockBodyDef);
  //
  //  //define shape
  //  b2PolygonShape blockShape;
  //  blockShape.SetAsBox(1.0f, 1.0f);
  //
  //  //assign to fixture
  //  b2FixtureDef blockFixture;
  //  blockFixture.shape = &blockShape;
  //  // density = 0 means it is static
  //  blockFixture.density = 0;
  //  blockFixture.friction = 0;
  //
  //  blockBody->CreateFixture(&blockFixture);
}

void SceneController::setupBall() {
  // create ball
  b2BodyDef ballBodyDef;
  ballBodyDef.type = b2_dynamicBody;
  ballBodyDef.position.Set(8.0f, 0.0f);
  ballBodyDef.userData = &ball;
  ball.body = world->CreateBody(&ballBodyDef);

  // define shape
  b2CircleShape ballShape;
  // position
  ballShape.m_p.Set(2.0f, 3.0f);
  ballShape.m_radius = 1.0f;

  // assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 1.0f;
  ballFixture.friction = 0;

  ball.body->CreateFixture(&ballFixture);
}

void SceneController::setupBlocks() {
  for (int i = 0; i < 8; i++) {
      Block block;
      b2BodyDef blockBodyDef;
      blockBodyDef.type = b2_staticBody;
      blockBodyDef.position.Set(2.0f * i, 0.0f);
      blockBodyDef.userData = &block;
      block.body = world->CreateBody(&blockBodyDef);

      // define shape
      b2PolygonShape blockShape;
      blockShape.SetAsBox(2.0f, 1.0f);

      // assign to fixture
      b2FixtureDef blockFixture;
      blockFixture.shape = &blockShape;
      // density = 0 means it is static
      blockFixture.density = 0;
      blockFixture.friction = 0;

      block.body->CreateFixture(&blockFixture);
      block.setup();
      blocks.push_back(block);
  }
}

void SceneController::setupPaddle() {
  // create paddle
  b2BodyDef paddleBodyDef;
  paddleBodyDef.type = b2_kinematicBody;
  paddleBodyDef.position.Set(9.0f, 15.0f);
  paddleBodyDef.userData = &paddle;
  paddle.body = world->CreateBody(&paddleBodyDef);

  // define shape
  b2PolygonShape paddleShape;
  paddleShape.SetAsBox(1.0f, 1.0f);

  // assign to fixture
  b2FixtureDef paddleFixture;
  paddleFixture.shape = &paddleShape;
  paddleFixture.density = 0.0f;
  paddleFixture.friction = 0;

  paddle.body->CreateFixture(&paddleFixture);
}
