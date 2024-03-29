
// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  // print out the value you read:
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability
  if (sensorValue >= 0 && sensorValue <= 15){
  Serial.println("Switch 1 pressed");}
  else if (sensorValue >= 516 && sensorValue <= 531){
  Serial.println("Switch 2 pressed");}
   else if (sensorValue >= 675 && sensorValue <= 690){
  Serial.println("Switch 3 pressed");}
   else if (sensorValue >= 765 && sensorValue <= 780){
  Serial.println("Switch 4 pressed");}
   else if (sensorValue >= 810 && sensorValue <= 825){
  Serial.println("Switch 5 pressed");}
  else{
    Serial.print("No switch pressed");}
  delay(500);
}
  
  
