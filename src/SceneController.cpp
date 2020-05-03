//
// Created by Preston Chao on 4/27/20.
//

#include "blocksmasher/SceneController.h"

#include <Box2D/Box2D.h>
#include <blocksmasher/SceneObject.h>

using namespace std;
using namespace ci;

SceneController::SceneController() {}

void SceneController::setup(b2World& w) {
  world = &w;
  setupBall();
  setupBlocks();
  setupPaddle();
  setupWalls();
  gameOver = false;
}

void SceneController::update() {
  // Go through the blocks supposed to delete and delete them
  for (b2Body* b : deleteBlockBodies) {
    world->DestroyBody(b);
  }
  deleteBlockBodies.clear();

  // If no more blocks the game is over and the player has won
  if (blocks.empty()) {
    gameOver = true;
    win = true;
  }

  // If the ball is below the screen the game is over and the player has lost
  if (ball.body->GetPosition().y > 17) {
    gameOver = true;
    win = false;
  }
}

void SceneController::draw() {
  ball.draw();
  paddle.draw();
  for (Block b : blocks) {
    b.draw();
  }
}

void SceneController::startGame() {
  ball.body->ApplyForce(b2Vec2(0, 300), ball.body->GetPosition());
}

void SceneController::movePaddleLeft() {
  paddle.body->SetLinearVelocity(b2Vec2(-10, 0));
}

void SceneController::movePaddleRight() {
  paddle.body->SetLinearVelocity(b2Vec2(10, 0));
}

void SceneController::stopPaddle() {
  paddle.body->SetLinearVelocity(b2Vec2(0, 0));
}

void SceneController::BeginContact(b2Contact* contact) {
  b2Fixture* a = contact->GetFixtureA();
  b2Vec2 loc = a->GetBody()->GetPosition();

  // Go through the blocks and find the matching position
  for (int i = 0; i < blocks.size(); i++) {
    if (blocks[i].body->GetPosition() == loc) {
      // add to array to delete blocks and remove from vector
      deleteBlockBodies.push_back(blocks[i].body);
      blocks.erase(blocks.begin() + i);
    }
  }
}

void SceneController::setupWalls() {
  // left wall
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

  // right wall
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

  // top wall
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

  //  // bottom wall
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
  ballShape.m_p.Set(0, 0);
  ballShape.m_radius = .5f;
  ball.setRadius(.5f);

  // assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 0.0f;
  ballFixture.friction = 0;
  ballFixture.restitution = 1.0f;

  ball.body->CreateFixture(&ballFixture);
  ball.setup();
}

void SceneController::setupBlocks() {
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 8; j++) {
      // create block
      Block block;
      b2BodyDef blockBodyDef;
      blockBodyDef.type = b2_staticBody;
      blockBodyDef.position.Set(1.0f + 2 * j, .5f + 1 * i);
      blockBodyDef.userData = &block;
      block.body = world->CreateBody(&blockBodyDef);

      // define shape
      b2PolygonShape blockShape;
      blockShape.SetAsBox(1.0f, .5f);
      block.setWidth(1.0f);
      block.setHeight(.5f);

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
  paddleBodyDef.type = b2_dynamicBody;
  paddleBodyDef.position.Set(8.0f, 14.0f);
  paddleBodyDef.userData = &paddle;
  paddle.body = world->CreateBody(&paddleBodyDef);

  // define shape
  b2PolygonShape paddleShape;
  paddleShape.SetAsBox(1.0f, .5f);
  paddle.setWidth(1.0f);
  paddle.setHeight(.5f);

  // assign to fixture
  b2FixtureDef paddleFixture;
  paddleFixture.shape = &paddleShape;
  paddleFixture.density = 1000000.0f;
  paddleFixture.friction = 0;

  paddle.body->CreateFixture(&paddleFixture);
  paddle.setup();
}
