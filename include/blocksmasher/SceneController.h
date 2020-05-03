//
// Created by Preston Chao on 4/27/20.
//

#ifndef FINALPROJECT_SCENECONTROLLER_H
#define FINALPROJECT_SCENECONTROLLER_H

#include <Box2D/Box2D.h>
//#include <blocksmasher/Ball.h>
//#include <blocksmasher/Block.h>
//#include <blocksmasher/Paddle.h>
#include <blocksmasher/SceneObject.h>
#include <cinder/gl/draw.h>

#include <vector>

// using namespace blocksmasher;

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

  bool getGameOver() { return gameOver; }
  bool getWin() { return win; }

 private:
  b2World* world;
  std::vector<Block> blocks;
  std::vector<b2Body*> deleteBlockBodies;
  Ball ball;
  Paddle paddle;
  bool gameOver;
  bool win;
  float scalar = 50.0f;

  void setupBall();
  void setupBlocks();
  void setupPaddle();
  void setupWalls();

  void BeginContact(b2Contact* contact) override;
};

#endif  // FINALPROJECT_SCENECONTROLLER_H
