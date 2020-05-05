// Copyright (c) 2020 CS126SP20. All rights reserved.

#define CATCH_CONFIG_MAIN

#include <Box2D/Box2D.h>
#include <blocksmasher/SceneController.h>
#include <blocksmasher/SceneObject.h>
#include <cinder/Rand.h>

#include <catch2/catch.hpp>

/**
 * Ball Struct
 */
/*
* setup()
*/
TEST_CASE("create ball", "[ball]") {
  Ball ball;
  ball.setup();
  REQUIRE(ball.tag == "ball");
}

/**
 * Paddle Struct
 */
/*
* setup()
*/
TEST_CASE("create paddle", "[paddle]") {
  Paddle paddle;
  paddle.setup();
  REQUIRE(paddle.tag == "paddle");
}

/**
 * Block Struct
 */
/*
* setup()
*/
TEST_CASE("create block", "[block]") {
  Block block;
  block.setup();
  REQUIRE(block.tag == "block");
}

/**
 * SceneController Class
 */

/*
 * Setup()
 */
TEST_CASE("setup", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);

  SECTION("Gameover Initialized") { REQUIRE(!sceneController.getGameOver()); }

  SECTION("World Initialized") {
    REQUIRE(sceneController.getWorld() != nullptr);
  }
}

/*
 * setupBall
 */
TEST_CASE("setup ball", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  sceneController.setupBall();
  REQUIRE(sceneController.getBall().tag == "ball");
}

/*
 * setupPaddle
 */
TEST_CASE("setup paddle", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  sceneController.setupPaddle();
  REQUIRE(sceneController.getPaddle().tag == "paddle");
}

/*
 * setupBlocks
 */
TEST_CASE("setup blocks", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  sceneController.setupBlocks();
  REQUIRE(sceneController.getBlocks().size() == 48);
}

/*
 * isWin
 */
TEST_CASE("isWin", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  sceneController.isWin();
  SECTION("Win") { REQUIRE(!sceneController.getWin()); }
  SECTION("Gameover") { REQUIRE(!sceneController.getGameOver()); }
}

/*
 * isLose
 */
TEST_CASE("isLose", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  sceneController.isLose();
  SECTION("Lose") { REQUIRE(!sceneController.getWin()); }
  SECTION("Gameover") { REQUIRE(!sceneController.getGameOver()); }
}

void stepWorld(b2World world) {
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);
}

/*
 * startGame()
 */
TEST_CASE("startGame", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  Ball ball = sceneController.getBall();
  b2Vec2 startPosition = ball.body->GetPosition();
  sceneController.startGame();
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);
  b2Vec2 endPosition = ball.body->GetPosition();
  REQUIRE(startPosition.y < endPosition.y);
}

/*
 * movePaddleLeft()
 */
TEST_CASE("movePaddleLeft", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  Paddle paddle = sceneController.getPaddle();
  b2Vec2 startPosition = paddle.body->GetPosition();
  sceneController.movePaddleLeft();
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);
  b2Vec2 endPosition = paddle.body->GetPosition();
  REQUIRE(startPosition.x > endPosition.x);
}

/*
 * movePaddleRight()
 */
TEST_CASE("movePaddleRight", "[sceneController]") {
  b2Vec2 gravity(0.0f, 0.0f);
  b2World world(gravity);
  SceneController sceneController;
  sceneController.setup(world);
  Paddle paddle = sceneController.getPaddle();
  b2Vec2 startPosition = paddle.body->GetPosition();
  sceneController.movePaddleRight();
  float32 timeStep = 1.0f / 60.0f;
  int32 velocityIterations = 6;
  int32 positionIterations = 2;
  world.Step(timeStep, velocityIterations, positionIterations);
  b2Vec2 endPosition = paddle.body->GetPosition();
  REQUIRE(startPosition.x < endPosition.x);
}



