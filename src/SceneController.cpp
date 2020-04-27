//
// Created by Preston Chao on 4/27/20.
//

#include "blocksmasher/SceneController.h"

#include <Box2D/Box2D.h>

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

void SceneController::setupWalls() {
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
  ballBodyDef.position.Set(0.0f, 4.0f);
  ballBodyDef.userData = &ball;
  ball.body = world->CreateBody(&ballBodyDef);

  // define shape
  b2CircleShape ballShape;
  // position
  ballShape.m_p.Set(2.0f, 3.0f);
  ball.radius = .05f;
  ballShape.m_radius = 0.5f;

  // assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 1.0f;
  ballFixture.friction = 0;

  ball.body->CreateFixture(&ballFixture);
}

void SceneController::setupBlocks() {
  //  for (int i = 0; i < 3; i++) {
  //    for (int j = 0; j < 8; j++) {
  Block block;
  b2BodyDef blockBodyDef;
  blockBodyDef.type = b2_staticBody;
  blockBodyDef.position.Set(4.0f, 4.0f);
  blockBodyDef.userData = &block;
  block.body = world->CreateBody(&blockBodyDef);

  // define shape
  b2PolygonShape blockShape;
  blockShape.SetAsBox(1.0f, 1.0f);

  // assign to fixture
  b2FixtureDef blockFixture;
  blockFixture.shape = &blockShape;
  // density = 0 means it is static
  blockFixture.density = 0;
  blockFixture.friction = 0;

  block.body->CreateFixture(&blockFixture);
}

void SceneController::setupPaddle() {
  // create paddle
  b2BodyDef paddleBodyDef;
  paddleBodyDef.type = b2_kinematicBody;
  paddleBodyDef.position.Set(0.0f, 0.0f);
  paddleBodyDef.userData = &paddle;
  paddle.body = world->CreateBody(&paddleBodyDef);

  // define shape
  b2PolygonShape paddleShape;
  paddleShape.SetAsBox(1.0f, 1.0f);

  // assign to fixture
  b2FixtureDef paddleFixture;
  paddleFixture.shape = &paddleShape;
  paddleFixture.density = 1.0f;
  paddleFixture.friction = 0;

  paddle.body->CreateFixture(&paddleFixture);
}
