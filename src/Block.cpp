//
// Created by Preston Chao on 4/21/20.
//

#include "blocksmasher/Block.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>
#include "cinder/Rand.h"

using namespace ci;

blocksmasher::Block::Block() {}

void blocksmasher::Block::setup() {
  color = ci::ColorA(ci::Rand::randFloat(0,.8), 0, 1, 1);
}

void blocksmasher::Block::update() {}

void blocksmasher::Block::draw() {
  gl::color(color);
  b2Vec2 pos = body->GetPosition();
  Rectf rect(pos.x * 50. - 100, pos.y * 50. - 50, pos.x * 50 + 100,
             pos.y * 50 + 50);
  gl::drawSolidRect(rect);
}