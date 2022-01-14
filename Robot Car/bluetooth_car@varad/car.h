#include "bo_motor.h"

class Car {
  MotorShield shield;
  int turning;
  bool goingForward;

  public : 
    Car() : shield(3,5,6,9) {}
    Car(const int out1, const int out2, const int out3, const int out4) : shield(out1, out2, out3, out4) {};
    MotorShield(const int* out_pins) : shield(out_pins) {};
    
  void turnLeft() {
    turning = 1;
  }
  void turnRight() {
    turning = -1;
  }
  void dontTurn() {
    turning = 0;
  }
  void goForward() {
    goingForward = true;
  }
  void stop() {
    goingForward = false;
  }
  void update() {
    if(turning == 1 and goingForward) {
      shield.motors[0].setSpeed(0.5);
      shield.motors[1].setSpeed(1);
      shield.motors[2].setSpeed(0.5);
      shield.motors[3].setSpeed(1);
    } else if(turning == -1 and goingForward) {
      shield.motors[0].setSpeed(1);
      shield.motors[1].setSpeed(0.5);
      shield.motors[2].setSpeed(1);
      shield.motors[3].setSpeed(0.5);
    } else if(turning == 0 and goingForward) {
      shield.motors[0].setSpeed(1);
      shield.motors[1].setSpeed(1);
      shield.motors[2].setSpeed(1);
      shield.motors[3].setSpeed(1);
    } else if(turning == 1 and not goingForward) {
      shield.motors[0].setSpeed(0);
      shield.motors[1].setSpeed(1);
      shield.motors[2].setSpeed(0);
      shield.motors[3].setSpeed(1);
    } else 
    } else if(turning == -1 and not goingForward) {
      shield.motors[0].setSpeed(1);
      shield.motors[1].setSpeed(0);
      shield.motors[2].setSpeed(1);
      shield.motors[3].setSpeed(0);
    } else 
    } else if(turning == 0 and not goingForward) {
      shield.motors[0].setSpeed(0);
      shield.motors[1].setSpeed(0);
      shield.motors[2].setSpeed(0);
      shield.motors[3].setSpeed(0);
    };
  }
}
