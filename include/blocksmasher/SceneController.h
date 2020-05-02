//
// Created by Preston Chao on 4/27/20.
//

#ifndef FINALPROJECT_SCENECONTROLLER_H
#define FINALPROJECT_SCENECONTROLLER_H

#include <Box2D/Box2D.h>
//#include <blocksmasher/Ball.h>
//#include <blocksmasher/Block.h>
//#include <blocksmasher/Paddle.h>
#include <cinder/gl/draw.h>
#include <blocksmasher/SceneObject.h>

#include <vector>

//using namespace blocksmasher;

class SceneController : public b2ContactListener {
 public:
  SceneController();
  void setup(b2World& w);
  void update();
  void draw();

  void startGame();
  void movePaddleLeft();
  void movePaddleRight();
  void stopPaddle();

 private:
  b2World* world;
  std::vector<Block> blocks;
  Ball ball;
  Paddle paddle;
  float scalar = 50.0f;

  void setupBall();
  void setupBlocks();
  void setupPaddle();
  void setupWalls();

  void BeginContact(b2Contact* contact) override;
};

#endif  // FINALPROJECT_SCENECONTROLLER_H
