//
// Created by Preston Chao on 4/21/20.
//

#ifndef FINALPROJECT_BLOCKSMASHER_BALL_H
#define FINALPROJECT_BLOCKSMASHER_BALL_H

namespace blocksmasher {

class Ball {
 private:
  int posX;
  int posY;

 public:
  Ball(int posX, int posY);
  void initialize();
};

}

#endif  // FINALPROJECT_BLOCKSMASHER_BALL_H
