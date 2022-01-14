#include "bluetooth.h"
#include "car.h"
BluetoothModule bluetooth(7,8,9600,6);
Car car(3,5,6,9);
const int in_pins = {2, 4, 7, 8};

void setup () {
  Serial.begin(9600);
  while ( not bluetooth.isEnabled() ){
    Serial.print("null~");
    delay(100);
  }
  Serial.println("Bluetooth connected!");

  for (int i = 0; i < 4; ++i)
    pinMode(in_pin[i], INPUT);
}

void loop () {
  while (bluetooth.serial.available() > 0) 
    Serial.write(bluetooth.serial.read());

  Serial.println();

  if (digitalRead(in_pins[1]) and not digitalRead(in_pins[2]))
    car.turnLeft();
  else if (not digitalRead(in_pins[1]) and digitalRead(in_pins[2])) 
    car.turnRight();
  else 
    car.dontTurn();

  if (digitalRead(in_pins[0]))
    car.goForward();
  else
    car.stop();

  car.update();
  delay(100);
}
