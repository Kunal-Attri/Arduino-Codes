// connect a ground also

int a = 2; // 1 to d2
int b = 3;  // 2 to d3
int c = 4;  // 3 to d4
int d = 5; // 4 to d5
int e = 6;  // 5 to d6
int f = 7;  // 6 to d7
int g = 8;  // 7 to d8
int h = 9;  // 8 to d9
int t = 5;

void setup() {
  // put your setup code here, to run once:
pinMode(a, INPUT);
pinMode(b, INPUT);
pinMode(c, INPUT);
pinMode(d, INPUT);
pinMode(e, OUTPUT);
pinMode(f, OUTPUT);
pinMode(g, OUTPUT);
pinMode(h, OUTPUT);
Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
digitalWrite(e, HIGH);
int v1 = digitalRead(a);
int v2 = digitalRead(b);
int v3 = digitalRead(c);
int v4 = digitalRead(d);
if(v1 == HIGH) {
 
  Serial.println("S13 pressed");
}
else if (v2 == HIGH) {
  Serial.println("S9 pressed");
}
else if (v3 == HIGH) {
  Serial.println("S5 pressed");
}
else if (v4 == HIGH) {
  Serial.println("S1 pressed");
}
delay(t);
digitalWrite(e, LOW);

digitalWrite(f, HIGH);
v1 = digitalRead(a);
v2 = digitalRead(b);
v3 = digitalRead(c);
v4 = digitalRead(d);
if(v1 == HIGH) {
  Serial.println("S14 pressed");
}
else if (v2 == HIGH) {
  Serial.println("S10 pressed");
}
else if (v3 == HIGH) {
  Serial.println("S6 pressed");
}
else if (v4 == HIGH) {
  Serial.println("S2 pressed");
}
delay(t);
digitalWrite(f, LOW);

digitalWrite(g, HIGH);
v1 = digitalRead(a);
v2 = digitalRead(b);
v3 = digitalRead(c);
v4 = digitalRead(d);
if(v1 == HIGH) {
  Serial.println("S15 pressed");
}
else if (v2 == HIGH) {
 Serial.println("S11 pressed");
}
else if (v3 == HIGH) {
  Serial.println("S7 pressed");
}
else if (v4 == HIGH) {
  Serial.println("S3 pressed");
}
delay(t);
digitalWrite(g, LOW);

digitalWrite(h, HIGH);
v1 = digitalRead(a);
v2 = digitalRead(b);
v3 = digitalRead(c);
v4 = digitalRead(d);
if(v1 == HIGH) {
  Serial.println("S16 pressed");
}
else if (v2 == HIGH) {
  Serial.println("S12 pressed");
}
else if (v3 == HIGH) {
  Serial.println("S8 pressed");
}
else if (v4 == HIGH) {
  Serial.println("S4 pressed");
}
delay(t);
digitalWrite(h, LOW);
}
