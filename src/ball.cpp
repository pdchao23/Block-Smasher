//
// Created by Preston Chao on 4/21/20.
//
#include <Box2D/Box2D.h>
#include "blocksmasher/ball.h"

blocksmasher::Ball::Ball(int posX, int posY) {
  this->posX = posX;
  this->posY = posY;
}

void blocksmasher::Ball::initialize() {
  //define body
  b2BodyDef ballBody;
  ballBody.type = b2_dynamicBody;
  ballBody.position.Set(0.0f, 4.0f);

  //define shape
  b2CircleShape ballShape;
  // TODO add circle start position

  //assign to fixture
  b2FixtureDef ballFixture;
  ballFixture.shape = &ballShape;
  ballFixture.density = 1.0f;

  //add shape to fixture
  //ballBody->CreateFixture

  // Add the shape to the body.
  //body->CreateFixture(&fixtureDef);
}
