//
// Created by Preston Chao on 4/21/20.
//

#ifndef FINALPROJECT_WallSMASHER_PADDLE_H
#define FINALPROJECT_WallSMASHER_PADDLE_H

#include <Box2D/Box2D.h>

#include "cinder/Color.h"

/**
 * Represents a object that is displayed on the screen
 */
struct SceneObject {
 public:
  b2Body* body;
  ci::Color color;
  float scalar = 50.0f;
  std::string tag;
};

/**
 * Represents a ball on the screen
 */
struct Ball : public SceneObject {
 public:
  /**
   * Set up userData and necessary tag
   */
  void setup();

  /**
   * Draw the ball in cinder based on instance variables
   */
  void draw();
  void setRadius(float r) { radius = r; }

 private:
  float radius;
};

/**
 * Represents a block on the screen
 */
struct Block : public SceneObject {
 public:
  /**
   * Set up userData, necessary tag, and random color
   */
  void setup();

  /**
   * Draw the block in cinder based on instance variables
   */
  void draw();
  void setHeight(float hheight) { halfHeight = hheight; }
  void setWidth(float hwidth) { halfWidth = hwidth; }

 private:
  float halfHeight;
  float halfWidth;
};

/**
 * Represents a paddle on the screen
 */
struct Paddle : public SceneObject {
 public:
  /**
   * Set up userData, and the necessary tag
   */
  void setup();

  /**
   * Draw the paddle in cinder based on instance variables
   */
  void draw();
  void setHeight(float hheight) { halfHeight = hheight; }
  void setWidth(float hwidth) { halfWidth = hwidth; }

 private:
  float halfHeight;
  float halfWidth;
};

#endif  // FINALPROJECT_PADDLE_H