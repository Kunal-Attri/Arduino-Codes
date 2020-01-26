#include <SoftwareSerial.h>
#include "new.h"

class BluetoothModule {
  const int enable_pin;
  const int key_pin;
  const int rx_pin;
  const int tx_pin;
  const int baud_rate;
  public : 
  SoftwareSerial serial;
  
    BluetoothModule() : enable_pin(0), key_pin(0), rx_pin(0), tx_pin(1), baud_rate(9600), serial(0,1) {}
    BluetoothModule(const int rx, const int tx, const int baud) : enable_pin(0), key_pin(0), rx_pin(rx), tx_pin(tx), baud_rate(baud), serial(rx_pin,tx_pin) {
      serial.begin(baud_rate);
    }
    BluetoothModule(const int rx, const int tx, const int baud, const int enable) : enable_pin(enable), key_pin(0), rx_pin(rx), tx_pin(tx), baud_rate(baud), serial(rx_pin,tx_pin) {
      serial.begin(baud_rate);
      pinMode(enable_pin, INPUT);
    }
    BluetoothModule(const int rx, const int tx, const int baud, const int enable, const int key) : enable_pin(enable), key_pin(key), rx_pin(rx), tx_pin(tx), baud_rate(baud), serial(rx_pin,tx_pin) {
      serial.begin(baud_rate);
      pinMode(enable_pin, INPUT);
      pinMode(key_pin, OUTPUT);
      digitalWrite(key_pin, LOW);
    }
    BluetoothModule(const BluetoothModule& bm) : enable_pin(bm.enable_pin), key_pin(bm.key_pin), rx_pin(bm.rx_pin), tx_pin(bm.tx_pin), baud_rate(bm.baud_rate), serial(rx_pin,tx_pin) {
      serial.begin(baud_rate);
      pinMode(enable_pin, INPUT);
      pinMode(key_pin, OUTPUT);
      digitalWrite(key_pin, LOW);
    }
    ~BluetoothModule() {
      serial.end();
    }
    BluetoothModule& operator=(const BluetoothModule& bm) {
      if (this != &bm) {
        this->~BluetoothModule();
        new(this) BluetoothModule(bm);
      }
      return *this;
    }

    bool isEnabled() {
      if (enable_pin != 0)
        return digitalRead(enable_pin);
      return false;
    }
    void sendATCom() {
      digitalWrite(key_pin, HIGH);
      Serial.println("AT mode enabled.");
      Serial.print("Enter command ~$ ");
      while (Serial.available() > 0) 
        serial.write(Serial.read());
      while (serial.available() > 0) 
        Serial.write(serial.read());
    }
};
