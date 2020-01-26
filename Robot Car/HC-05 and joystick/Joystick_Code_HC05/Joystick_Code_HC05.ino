int xAxis, yAxis;
int xPin = A0;
int yPin = A1;

void setup() {
  Serial.begin(38400); // Default communication rate of the Bluetooth module
}

void loop() {
  xAxis = analogRead(xPin); // Read Joysticks X-axis
  yAxis = analogRead(yPin); // Read Joysticks Y-axis
  
   // Send the values via the serial port to the slave HC-05 Bluetooth device
  Serial.write(xAxis/4);  // Dividing by 4 for converting from 0 - 1023 to 0 - 256, (1 byte) range
  Serial.write(yAxis/4);
  delay(20);
}
