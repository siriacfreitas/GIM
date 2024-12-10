#ifndef ROBOT_HPP
#define ROBOT_HPP

#include <Arduino.h>
#include "motor.hpp"

class Robot {
  private:
    Motor frontLeft{0}, frontRight{1}, backLeft{2}, backRight{3};

  public:
    Robot();
    ~Robot();

    void begin();

    void stop();

    void forward(uint8_t goal = 0, int16_t vel = 255);
    void backward(uint8_t goal = 0, int16_t vel = 255);

    void sidewaysRight(uint8_t goal = 0, int16_t vel = 255);    
    void sidewaysLeft(uint8_t goal = 0, int16_t vel = 255);

    void rotateLeft(uint8_t goal = 0, int16_t vel = 255);
    void rotateRight(uint8_t goal = 0, int16_t vel = 255);

    void moveRightForward(uint8_t goal = 0, int16_t vel = 255);
    void moveRightBackward(uint8_t goal = 0, int16_t vel = 255);

    void moveLeftForward(uint8_t goal = 0, int16_t vel = 255);
    void moveLeftBackward(uint8_t goal = 0, int16_t vel = 255);

    void smoothRotateLeft();
    void smoothRotateRight();

};

#endif  // ROBOT_HPP
