//
// Created by Preston Chao on 4/21/20.
//
#include "blocksmasher/Ball.h"
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>


using namespace ci;

blocksmasher::Ball::Ball() {}

void blocksmasher::Ball::setup() {}

void blocksmasher::Ball::update() {}

void blocksmasher::Ball::draw() {
  b2Vec2 pos =  body->GetPosition();
  vec2 newVec = vec2(pos.x, pos.y) * 50.0f;
  gl::drawSolidCircle(newVec, 50.0f, -1);
}
