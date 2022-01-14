#include <AFMotor.h>
#include <SoftwareSerial.h>

AF_DCMotor flmotor(1);
AF_DCMotor frmotor(2);
AF_DCMotor blmotor(3);
AF_DCMotor brmotor(4);

#define rxPin  A0
#define txPin  A1

int data = 0, l_speed = 0, r_speed = 0, f_speed = 0, b_speed = 0, lm_speed = 0, rm_speed = 0;
String dataIn = "", dataInS = "";
bool forward = true;
SoftwareSerial bluetooth(rxPin, txPin);
void setup() {
  // put your setup code here, to run once:
  pinMode(rxPin, INPUT);
  pinMode(txPin, OUTPUT);
  bluetooth.begin(38400);
  bluetooth.setTimeout(1);
  delay(20);

  flmotor.setSpeed(200);
  flmotor.run(RELEASE);
  frmotor.setSpeed(200);
  frmotor.run(RELEASE);
  blmotor.setSpeed(200);
  blmotor.run(RELEASE);
  brmotor.setSpeed(200);
  brmotor.run(RELEASE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (bluetooth.available() > 0) {
    dataIn = bluetooth.readString();

    if (dataIn.startsWith("f")) {
      dataInS = dataIn.substring(2, dataIn.length());
      data = dataInS.toInt();
      if (data < 128) {
        forward = false;
        b_speed = map(data, 127, 0, 0, 255);
        
        lm_speed = b_speed;
        rm_speed = b_speed;
        
      }
      if (data >= 128) {
        forward = true;
        f_speed = map(data, 128, 255, 0, 255);
        
        lm_speed = f_speed;
        rm_speed = f_speed;
      }
    }
    if (dataIn.startsWith("r")) {
      dataInS = dataIn.substring(2, dataIn.length());
      data = dataInS.toInt();
      if (data < 128) {
        l_speed = map(data, 127, 0, 0, 64);

        lm_speed -= l_speed;
        rm_speed += l_speed;
      }
      if (data >= 128) {
        r_speed = map(data, 128, 255, 0, 64);

        lm_speed += r_speed;
        rm_speed -= r_speed;
      }
    }
    if (forward) {
      if (lm_speed < 0) {
         lm_speed *= (-1);
         flmotor.run(BACKWARD);
         blmotor.run(BACKWARD);
      }
      if (lm_speed >= 0) {
         flmotor.run(FORWARD);
         blmotor.run(FORWARD);
      }
      if (rm_speed < 0) {
         rm_speed *= (-1);
         frmotor.run(BACKWARD);
         brmotor.run(BACKWARD);
      }
      if (rm_speed >= 0) {
         frmotor.run(FORWARD);
         brmotor.run(FORWARD);
      }
    }
    if (not forward) {
      if (rm_speed < 0) {
         rm_speed *= (-1);
         frmotor.run(FORWARD);
         brmotor.run(FORWARD);
      }
      if (rm_speed >= 0) {
         frmotor.run(BACKWARD);
         brmotor.run(BACKWARD);
      }
      if (lm_speed < 0) {
         lm_speed *= (-1);
         flmotor.run(FORWARD);
         blmotor.run(FORWARD);
      }
      if (lm_speed >= 0) {
         flmotor.run(BACKWARD);
         blmotor.run(BACKWARD);
      }
    }
    if (100 >= lm_speed > 0 ) {
      lm_speed = 100;
    }
    if (100 >= rm_speed > 0) {
      rm_speed = 100;
    }
    if (lm_speed >= 255) {
      lm_speed = 255;
    }
    if (rm_speed >= 255) {
      rm_speed = 255;
    }
    flmotor.setSpeed(lm_speed);
    blmotor.setSpeed(lm_speed);
    frmotor.setSpeed(rm_speed);
    brmotor.setSpeed(rm_speed);
  }
}
