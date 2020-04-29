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
  //left wall
  b2BodyDef leftWallBodyDef;
  leftWallBodyDef.type = b2_staticBody;
  leftWallBodyDef.position.Set(-1.0f, 8.0f);
  b2Body* leftWallBody = world->CreateBody(&leftWallBodyDef);

  b2PolygonShape leftWallShape;
  leftWallShape.SetAsBox(1.0f, 8.0f);

  b2FixtureDef leftWallFixture;
  leftWallFixture.shape = &leftWallShape;
  leftWallFixture.density = 0;
  leftWallFixture.friction = 0;

  leftWallBody->CreateFixture(&leftWallFixture);

  //right wall
  b2BodyDef rightWallBodyDef;
  rightWallBodyDef.type = b2_staticBody;
  rightWallBodyDef.position.Set(17.0f, 8.0f);
  b2Body* rightWallBody = world->CreateBody(&rightWallBodyDef);

  b2PolygonShape rightWallShape;
  rightWallShape.SetAsBox(1.0f, 8.0f);

  b2FixtureDef rightWallFixture;
  rightWallFixture.shape = &rightWallShape;
  rightWallFixture.density = 0;
  rightWallFixture.friction = 0;

  rightWallBody->CreateFixture(&rightWallFixture);

  //top wall
  b2BodyDef topWallBodyDef;
  topWallBodyDef.type = b2_staticBody;
  topWallBodyDef.position.Set(8.0f, -1.0f);
  b2Body* topWallBody = world->CreateBody(&topWallBodyDef);

  b2PolygonShape topWallShape;
  topWallShape.SetAsBox(8.0f, 1.0f);

  b2FixtureDef topWallFixture;
  topWallFixture.shape = &topWallShape;
  topWallFixture.density = 0;
  topWallFixture.friction = 1;

  topWallBody->CreateFixture(&topWallFixture);

//  //bottom wall
//  b2BodyDef bottomWallBodyDef;
//  bottomWallBodyDef.type = b2_staticBody;
//  bottomWallBodyDef.position.Set(8.0f, 15.0f);
//  b2Body* bottomWallBody = world->CreateBody(&bottomWallBodyDef);
//
//  b2PolygonShape bottomWallShape;
//  bottomWallShape.SetAsBox(8.0f, 1.0f);
//
//  b2FixtureDef bottomWallFixture;
//  bottomWallFixture.shape = &bottomWallShape;
//  bottomWallFixture.density = 0;
//  bottomWallFixture.friction = 1;
//
//  bottomWallBody->CreateFixture(&bottomWallFixture);
}

void SceneController::setupBall() {
  // create ball
  b2BodyDef ballBodyDef;
  ballBodyDef.type = b2_dynamicBody;
  ballBodyDef.position.Set(8.0f, 8.0f);
  ballBodyDef.userData = &ball;
  ball.body = world->CreateBody(&ballBodyDef);

  // define shape
  b2CircleShape ballShape;
  // position
  ballShape.m_p.Set(0, 0);
  ballShape.m_radius = .5f;
  ball.radius = .5f;

  // assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 1.0f;
  ballFixture.friction = 0;

  ball.body->CreateFixture(&ballFixture);
}

void SceneController::setupBlocks() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      Block block;
      b2BodyDef blockBodyDef;
      blockBodyDef.type = b2_staticBody;
      blockBodyDef.position.Set(1.0f + 2 * j, .5f + 1 * i);
      blockBodyDef.userData = &block;
      block.body = world->CreateBody(&blockBodyDef);

      // define shape
      b2PolygonShape blockShape;
      blockShape.SetAsBox(1.0f, .5f);
      block.halfWidth = 1.0f;
      block.halfHeight = .5f;

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
}

void SceneController::setupPaddle() {
  // create paddle
  b2BodyDef paddleBodyDef;
  paddleBodyDef.type = b2_kinematicBody;
  paddleBodyDef.position.Set(8.0f, 14.0f);
  paddleBodyDef.userData = &paddle;
  paddle.body = world->CreateBody(&paddleBodyDef);

  // define shape
  b2PolygonShape paddleShape;
  paddleShape.SetAsBox(1.0f, .5f);
  paddle.halfWidth = 1.0f;
  paddle.halfHeight = .5f;

  // assign to fixture
  b2FixtureDef paddleFixture;
  paddleFixture.shape = &paddleShape;
  paddleFixture.density = 0.0f;
  paddleFixture.friction = 0;

  paddle.body->CreateFixture(&paddleFixture);
}

void SceneController::movePaddleLeft() {
  paddle.body->SetLinearVelocity( b2Vec2( -1, 0 ) );
}

void SceneController::movePaddleRight() {
//  b2Vec2 move = b2Vec2(0,0);
//  move.x -= 100;
//  paddle.body->ApplyForce(move, paddle.body->GetPosition());
  paddle.body->SetLinearVelocity( b2Vec2( 1, 0 ) );
}
void SceneController::stopPaddle() {
//  b2Vec2 move = b2Vec2(0,0);
//  move.x -= 100;
//  paddle.body->ApplyForce(move, paddle.body->GetPosition());
  paddle.body->SetLinearVelocity( b2Vec2( 0, 0 ) );
}
