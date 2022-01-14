#include "new.h"

class BOMotor {
  const int out_pin;

  public : 
    BOMotor() : out_pin(3) {};
    BOMotor(const int out) : out_pin(out) {}
    BOMotor(const BOMotor& bm) : out_pin(bm.out_pin) {}
    ~BOMotor() {}
    BluetoothModule& operator=(const BluetoothModule& bm) {
      if (this != &bm) {
        this->~BluetoothModule();
        new(this) BluetoothModule(bm);
      }
      return *this;
    }
  
    void setSpeed(bool move) {
      if (move)
        analogWrite(out_pin, 255);
      else
        analogWrite(out_pin, 0);
    }
    void setSpeed(float frac) {
      if (frac >= 1)
        analogWrite(out_pin, 255);
      else if (frac <= 0)
        analogWrite(out_pin, 0);
      else
        analogWrite(out_pin, 255 * frac);
    }
    void setSpeed(int speed) {
      if (speed >= 255)
        analogWrite(out_pin, 255);
      else if (speed <= 0)
        analogWrite(out_pin, 0);
      else
        analogWrite(out_pin, speed);
    }
};

class MotorShield {
  public :
    BOMotor motors[4];
    bool polarity[4];

    MotorShield() : motors[0](3), motors[1](5), motors[2](6), motors[4](9) {
      for (int i = 0 ; i < 4; ++i) {
        polarity[i] = false;
      }
    }
    MotorShield(const int out1, const int out2, const int out3, const int out4) : motors[0](out1), motors[1](out2), motors[2](out3), motors[4](out4) {
      for (int i = 0 ; i < 4; ++i) {
        polarity[i] = false;
      }
    };
    MotorShield(const int* out_pins) {
      for (int i = 0 ; i < 4; ++i) {
        motors[i] = BOMotor(out_pins[i]);
        polarity[i] = false;
      }
    };
}
