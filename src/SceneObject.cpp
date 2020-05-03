//
// Created by Preston Chao on 4/21/20.
//

#include "blocksmasher/SceneObject.h"

#include <cinder/gl/draw.h>
#include <cinder/gl/gl.h>

#include "cinder/Rand.h"

using namespace ci;

void Ball::setup() {
  tag = "ball";
  body->SetUserData(this);
}

void Ball::draw() {
  b2Vec2 pos = body->GetPosition();
  vec2 newVec = vec2(pos.x, pos.y) * scalar;
  gl::drawSolidCircle(newVec, radius * scalar, -1);
}

void Block::setup() {
  tag = "block";
  color = ci::ColorA(ci::Rand::randFloat(0, .8), 0, 1, 1);
  body->SetUserData(this);
}

void Block::draw() {
  gl::color(color);
  b2Vec2 pos = body->GetPosition();
  Rectf rect(pos.x * scalar - halfWidth * scalar,
             pos.y * scalar - halfHeight * scalar,
             pos.x * scalar + halfWidth * scalar,
             pos.y * scalar + halfHeight * scalar);
  gl::drawSolidRect(rect);
}

void Paddle::setup() {
  tag = "paddle";
  body->SetUserData(this);
}

void Paddle::draw() {
  b2Vec2 pos = body->GetPosition();
  Rectf rect(pos.x * scalar - halfWidth * scalar,
             pos.y * scalar - halfHeight * scalar,
             pos.x * scalar + halfWidth * scalar,
             pos.y * scalar + halfHeight * scalar);
  gl::drawSolidRect(rect);
}