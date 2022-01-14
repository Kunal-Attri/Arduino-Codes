#define charlie1 8
#define charlie2 9
#define charlie3 10

int light1() {
  pinMode(charlie1, OUTPUT);
  pinMode(charlie2, INPUT);
  pinMode(charlie3, OUTPUT);
  digitalWrite(charlie1, HIGH);
  digitalWrite(charlie2, HIGH);
  digitalWrite(charlie3, LOW);
}

int light2() {
  pinMode(charlie1, OUTPUT);
  pinMode(charlie2, OUTPUT);
  pinMode(charlie3, INPUT);
  digitalWrite(charlie1, LOW);
  digitalWrite(charlie2, HIGH);
  digitalWrite(charlie3, HIGH);
}

int light3() {
  pinMode(charlie1, OUTPUT);
  pinMode(charlie2, OUTPUT);
  pinMode(charlie3, INPUT);
  digitalWrite(charlie1, HIGH);
  digitalWrite(charlie2, LOW);
  digitalWrite(charlie3, HIGH);
}

int light4() {
  pinMode(charlie1, OUTPUT);
  pinMode(charlie2, INPUT);
  pinMode(charlie3, OUTPUT);
  digitalWrite(charlie1, LOW);
  digitalWrite(charlie2, HIGH);
  digitalWrite(charlie3, HIGH);
}

int light5() {
  pinMode(charlie1, INPUT);
  pinMode(charlie2, OUTPUT);
  pinMode(charlie3, OUTPUT);
  digitalWrite(charlie1, HIGH);
  digitalWrite(charlie2, LOW);
  digitalWrite(charlie3, HIGH);
}

int light6() {
  pinMode(charlie1, INPUT);
  pinMode(charlie2, OUTPUT);
  pinMode(charlie3, OUTPUT);
  digitalWrite(charlie1, HIGH);
  digitalWrite(charlie2, HIGH);
  digitalWrite(charlie3, LOW);
}

int clockwise(int dela) {
  light1();
  delay(dela);
  light2();
  delay(dela);
  light3();
  delay(dela);
  light4();
  delay(dela);
  light5();
  delay(dela);
  light6();
  delay(dela);
}

int anticlockwise(int dela) {
  light6();
  delay(dela);
  light5();
  delay(dela);
  light4();
  delay(dela);
  light3();
  delay(dela);
  light2();
  delay(dela);
  light1();
  delay(dela);
}
