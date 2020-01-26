#include <AFMotor.h>
//#include <SoftwareSerial.h>

//#define rxPin  A0
//#define txPin  A1

AF_DCMotor flmotor(1);
AF_DCMotor frmotor(2);
AF_DCMotor blmotor(3);
AF_DCMotor brmotor(4);

//SoftwareSerial bluetooth(rxPin, txPin);

String dataIn = "";

void setup() {
  //pinMode(rxPin, INPUT);
  //pinMode(txPin, OUTPUT);
  
  pinMode(A4, OUTPUT);
  digitalWrite(A4, HIGH);
  //bluetooth.begin(38400);
  //bluetooth.setTimeout(1);
  delay(20);

  flmotor.setSpeed(200);
  flmotor.run(RELEASE);
  frmotor.setSpeed(200);
  frmotor.run(RELEASE);
  blmotor.setSpeed(200);
  blmotor.run(RELEASE);
  brmotor.setSpeed(200);
  brmotor.run(RELEASE);
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    dataIn = Serial.readString();

    if (dataIn.startsWith("forward")) {
      flmotor.run(FORWARD);
      frmotor.run(FORWARD);
      blmotor.run(FORWARD);
      brmotor.run(FORWARD);
    }
    if (dataIn.startsWith("backward")) {
      flmotor.run(BACKWARD);
      frmotor.run(BACKWARD);
      blmotor.run(BACKWARD);
      brmotor.run(BACKWARD);
    }
    if (dataIn.startsWith("right")) {
      flmotor.run(FORWARD);
      frmotor.run(BACKWARD);
      blmotor.run(FORWARD);
      brmotor.run(BACKWARD);
    }
    if (dataIn.startsWith("left")) {
      flmotor.run(BACKWARD);
      frmotor.run(FORWARD);
      blmotor.run(BACKWARD);
      brmotor.run(FORWARD);
    }
    if (dataIn.startsWith("stop")) {
      flmotor.run(RELEASE);
      frmotor.run(RELEASE);
      blmotor.run(RELEASE);
      brmotor.run(RELEASE);
    }
    if (dataIn.startsWith("slow")) {
      flmotor.setSpeed(175);
      frmotor.setSpeed(175);
      blmotor.setSpeed(175);
      brmotor.setSpeed(175);
    }
    if (dataIn.startsWith("fast")) {
      flmotor.setSpeed(250);
      frmotor.setSpeed(250);
      blmotor.setSpeed(250);
      brmotor.setSpeed(250);
    }
  }
}
