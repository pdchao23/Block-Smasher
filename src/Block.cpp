//
// Created by Preston Chao on 4/21/20.
//

#include "blocksmasher/Block.h"
#include <cinder/gl/gl.h>
#include <cinder/gl/draw.h>

using namespace ci;

blocksmasher::Block::Block() {}

void blocksmasher::Block::setup() {}

void blocksmasher::Block::update() {}

void blocksmasher::Block::draw() {
  b2Vec2 pos =  body->GetPosition();
  float newX = pos.x * .01f;
  float newY = pos.y * .01f;
  gl::translate(newX, newY);
  Rectf rect(-size.x, -size.y, size.x, size.y);
  gl::drawSolidRect(rect);
}