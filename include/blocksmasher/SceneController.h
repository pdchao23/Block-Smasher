//
// Created by Preston Chao on 4/27/20.
//

#ifndef FINALPROJECT_SCENECONTROLLER_H
#define FINALPROJECT_SCENECONTROLLER_H

#include <Box2D/Box2D.h>
#include <blocksmasher/Ball.h>
#include <blocksmasher/Block.h>
#include <blocksmasher/Paddle.h>
#include <cinder/gl/draw.h>

#include <vector>

using namespace blocksmasher;


struct Conversions {
  static float getScaling() {
    static float scaling = 50.0f;
    return scaling;
  }

  static ci::vec2 toScreen(b2Vec2 fin) {
    return ci::vec2(fin.x, fin.y) * getScaling();
  }

  static b2Vec2 toPhysics(ci::vec2 fin) {
    return b2Vec2(fin.x / getScaling(), fin.y / getScaling());
  }

  static float toPhysics(float fin) { return fin / getScaling(); }

  static float toScreen(float fin) { return fin * getScaling(); }

  static float radiansToDegrees(float rad) { return rad * 180.0f / M_PI; }
};

class SceneController {
 public:
  SceneController();
  void setup(b2World& w);
  void update();
  void draw();

 private:
  b2World* world;
//  std::vector<Wall> walls;
  std::vector<Block> blocks;
  Ball ball;
  Paddle paddle;

  void setupBall();
  void setupBlocks();
  void setupPaddle();
  void setupWalls();
};

#endif  // FINALPROJECT_SCENECONTROLLER_H
