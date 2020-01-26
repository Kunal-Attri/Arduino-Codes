int latchPin = 3;
int clockPin = 4;
int dataPin = 2;
//int pot = A7;

void setup() {
  // put your setup code here, to run once:
pinMode(latchPin, OUTPUT);
pinMode(clockPin, OUTPUT);
pinMode(dataPin, OUTPUT);
//pinMode(pot, INPUT);
//Serial.begin(9600);
}

void loop() {
  //float t = millis();
  for (int j = 0; j < 4450; j++) {
  //float a = analogRead(pot);
  //a /= 1023;
  //a *= 1000;
  //Serial.print(a);
digitalWrite(latchPin, LOW);
shiftOut(dataPin, clockPin,LSBFIRST, ~j);
 digitalWrite(latchPin, HIGH);
 delay(1000);
 
}
//float tl = millis();
//float trime = tl - t;
//Serial.print(trime);
//Serial.println("");
//delay(1000);
}
