//
// Created by Preston Chao on 4/27/20.
//

#ifndef FINALPROJECT_SCENECONTROLLER_H
#define FINALPROJECT_SCENECONTROLLER_H

#include <Box2D/Box2D.h>
#include <blocksmasher/SceneObject.h>
#include <cinder/gl/draw.h>

#include <vector>

/**
 * The SceneController simulates the Box2d world  and is the main game engine
 */
class SceneController : public b2ContactListener {
 public:
  SceneController();

  /**
   * Set up all the nevessary objects in the world and set instance variables
   *
   * param  b2Wrold&    The b2World that is passed in
   */
  void setup(b2World& w);

  /**
   * Delete any blocks if necessary
   */
  void update();

  /**
   * Draw the ball, paddle, and blocks
   */
  void draw();

  /**
   * Start the game by applying force on the ball
   */
  void startGame();

  /**
   * Apply force on paddle to move it left
   */
  void movePaddleLeft();

  /**
   * Apply force on paddle to move it right
   */
  void movePaddleRight();

  /**
   * Apply force on paddle to stop it
   */
  void stopPaddle();

  /**
   * Set up the ball object in Box2d and assign it to instance variable
   */
  void setupBall();

  /**
   * Set up the block objects in Box2d and assign it to the blocks vector
   */
  void setupBlocks();

  /**
   * Set up the paddle object in Box2d and assign it to instance variable
   */
  void setupPaddle();

  /**
   * Returns if the player has won
   *
   * @return true if the player has won and false otherwise
   */
  bool isWin();

  /**
   * Returns if the player has lost
   *
   * @return true if the player has lost and false otherwise
   */
  bool isLose();

  bool getGameOver() { return gameOver; }
  bool getWin() { return win; }
  b2World* getWorld() { return world; }
  Ball getBall() { return ball; }
  Paddle getPaddle() { return paddle; }
  std::vector<Block> getBlocks() { return blocks; }

 private:
  b2World* world;
  std::vector<Block> blocks;
  std::vector<b2Body*> deleteBlockBodies;
  Ball ball;
  Paddle paddle;
  bool gameOver;
  bool win;

  /**
   * Set up the walls in Box2d
   */
  void setupWalls();

  /**
   * Delete the blocks in the Box2D world in the given vector and clear the
   * vector after
   */
  void deleteBlocks();

  /**
   * Removes the blocks when there is contact
   *
   * param  b2Contact*      the contact in the b2World
   */
  void BeginContact(b2Contact* contact) override;
};

#endif  // FINALPROJECT_SCENECONTROLLER_H
