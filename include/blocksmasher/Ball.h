//
// Created by Preston Chao on 4/21/20.
//

#ifndef FINALPROJECT_BLOCKSMASHER_BALL_H
#define FINALPROJECT_BLOCKSMASHER_BALL_H

#include "cinder/Color.h"
#include <Box2D/Box2d.h>

namespace blocksmasher {

class Ball {
 public:
  Ball();

  // pass in a pointer to the particle
  void setup();
  void update();
  void draw();

  // private:
  // store a pointer to the particle in the physics world from the main app
  b2Body* body;
  ci::Color color;
  ci::vec2 size;
};

}  // namespace blocksmasher

#endif  // FINALPROJECT_BLOCKSMASHER_BALL_H
