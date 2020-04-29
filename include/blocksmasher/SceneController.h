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

class SceneController {
 public:
  SceneController();
  void setup(b2World& w);
  void update();
  void draw();

  void movePaddleLeft();
  void movePaddleRight();

 private:
  b2World* world;
  std::vector<Block> blocks;
  Ball ball;
  Paddle paddle;

  void setupBall();
  void setupBlocks();
  void setupPaddle();
  void setupWalls();
};

#endif  // FINALPROJECT_SCENECONTROLLER_H
