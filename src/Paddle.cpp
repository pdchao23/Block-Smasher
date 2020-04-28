//
// Created by Preston Chao on 4/21/20.
//

#include "blocksmasher/Paddle.h"
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>

using namespace ci;

blocksmasher::Paddle::Paddle() {}

void blocksmasher::Paddle::setup() {}

void blocksmasher::Paddle::update() {}

void blocksmasher::Paddle::draw() {
  b2Vec2 pos =  body->GetPosition();
  float newX = pos.x * .01f;
  float newY = pos.y * .01f;
  gl::translate(newX, newY);
  Rectf rect(0,0,50,50);
  gl::drawSolidRect(rect);
}