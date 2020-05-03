//
// Created by Preston Chao on 4/21/20.
//

#ifndef FINALPROJECT_WallSMASHER_PADDLE_H
#define FINALPROJECT_WallSMASHER_PADDLE_H

#include "cinder/Color.h"
#include <Box2D/Box2D.h>

struct SceneObject {
 public:
  std::string getTag() {return tag;}
  b2Body* body;
  ci::Color color;
  float scalar = 50.0f;
  std::string tag;
};

struct Ball : public SceneObject {
 public:
  void setup();
  void draw();
  void setRadius(float r) { radius = r;}

 private:
  float radius;
};

struct Block : public SceneObject {
 public:
  void setup();
  void draw();
  void setHeight(float hheight) { halfHeight = hheight;}
  void setWidth(float hwidth) { halfWidth = hwidth;}

 private:
  float halfHeight;
  float halfWidth;
};

struct Paddle : public SceneObject {
 public:
  void setup();
  void draw();
  void setHeight(float hheight) { halfHeight = hheight;}
  void setWidth(float hwidth) { halfWidth = hwidth;}

 private:
  float halfHeight;
  float halfWidth;
};

#endif  // FINALPROJECT_PADDLE_H