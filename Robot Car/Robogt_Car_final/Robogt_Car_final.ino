#include <AFMotor.h>
#include <Servo.h>
int angle = 90, lm1, rm1, lm11, rm11;
Servo turn_servo;
AF_DCMotor motor1(1);
AF_DCMotor motor2(2);
//AF_DCMotor motor3(3);
//AF_DCMotor motor4(4);

char bt='S';
void setup()
{
  //pinMode(A4, OUTPUT);
  //digitalWrite(A4, HIGH);
  Serial.begin(9600);
turn_servo.attach(10);
 turn_servo.write(90);
 delay(500);
  speed_(255, 255);
  lm1 = 255;
  rm1 = 255;
  Stop();
}


void loop() {
 
bt=Serial.read();

if(bt=='F')
{
 forward(); 
}

if(bt=='B')
{
 backward(); 
}

if(bt=='L')
{
 left(); 
}

if(bt=='R')
{
 right(); 
}

if(bt=='S')
{
 Stop(); 
}

if(bt=='0')
{
  speed_(0, 0);
  lm1 = 0;
  rm1 = 0; 
}

if(bt=='1')
{
  speed_(120, 120); 
  lm1 = 120;
  rm1 = 120;
}

if(bt=='2')
{
 speed_(135, 135);
 lm1 = 135;
  rm1 = 135;
}

if(bt=='3')
{
  lm1 = 150;
  rm1 = 150;
speed_(150, 150);
}

if(bt=='4')
{
  lm1 = 165;
  rm1 = 165;
speed_(165, 165);
}

if(bt=='5')
{
  lm1 = 180;
  rm1 = 180;
 speed_(180, 180); 
}

if(bt=='6')
{
  lm1 = 195;
  rm1 = 195;
speed_(195, 195);
}

if(bt=='7')
{
  lm1 = 210;
  rm1 = 210;
speed_(210, 210);
}

if(bt=='8')
{
  lm1 = 225;
  rm1 = 225;
speed_(225, 225);
}

if(bt=='9')
{
  lm1 = 240;
  rm1 = 240;
speed_(240, 240); 
}

if(bt=='q')
{
  lm1 = 255;
  rm1 = 255;
  speed_(255, 255); 
}
}
void forward()
{
  if(angle != 90){
    if(angle > 90) {
      for(int j = angle; j >= 90; j--) {
        turn_servo.write(j);
        angle = j;
        delay(10);
      }
    }
    if(angle < 90) {
      for(int j = angle; j <= 90; j++) {
        turn_servo.write(j);
        angle = j;
        delay(10);
      }
    }
  }
  speed_(lm1, rm1);
     motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  //motor3.run(FORWARD);
  //motor4.run(FORWARD);
}

void backward()
{
  if(angle != 90){
    if(angle > 90) {
      for(int j = angle; j >= 90; j--) {
        turn_servo.write(j);
        angle = j;
        delay(10);
      }
    }
    if(angle < 90) {
      for(int j = angle; j <= 90; j++) {
        turn_servo.write(j);
        angle = j;
        delay(10);
      }
    }
  }
  speed_(lm1, rm1);
     motor1.run(FORWARD);
  motor2.run(FORWARD);
  //motor3.run(BACKWARD);
  //motor4.run(BACKWARD);
}
void left()
{
if(angle>70) {
  angle = angle - 1;
  turn_servo.write(angle);
  delay(10);
  lm11 = lm1 - (90-angle)*2;
  speed_(lm11, rm1);
  
}
  motor1.run(BACKWARD);
  motor2.run(BACKWARD); 
  //motor3.run(RELEASE);
  //motor4.run(FORWARD);
}
void right()
{
  if(angle<110) {
  angle = angle + 1;
  turn_servo.write(angle);
  delay(10);
   rm11 = rm1 - (angle - 90)*2;
  speed_(lm1, rm11);
}
  motor1.run(BACKWARD);
  motor2.run(BACKWARD);
  //motor3.run(FORWARD);
  //motor4.run(RELEASE);
}
void Stop()
{
  motor1.run(RELEASE);
  motor2.run(RELEASE);
  //motor3.run(RELEASE);
  //motor4.run(RELEASE);
}

void speed_(int lm, int rm) {
motor1.setSpeed(lm);
  motor2.setSpeed(rm);
  //motor3.setSpeed(sp);
  //motor4.setSpeed(sp);
}
