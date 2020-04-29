//
// Created by Preston Chao on 4/21/20.
//

#include "blocksmasher/Paddle.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

using namespace ci;

blocksmasher::Paddle::Paddle() {}

void blocksmasher::Paddle::setup() {}

void blocksmasher::Paddle::update() {}

void blocksmasher::Paddle::draw() {
  b2Vec2 pos = body->GetPosition();
  Rectf rect(pos.x * scalar - 50, pos.y * scalar - 20, pos.x * scalar + 50,
             pos.y * scalar + 20);
  gl::drawSolidRect(rect);
}