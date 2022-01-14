#define DELAYbwDIGITS 1
#define DELAYbwTWOnos 1

void setup() {
  for(int i = 2; i<= 13; i++) {
    pinMode(i, OUTPUT);
  }                         //D1-D4:2-5; a-g,dp: 6-13
  Serial.begin(9600);
}

/*abcdefg
  1111110 = 0
  0110000 = 1
  1101101 = 2
  1111001 = 3
  0110011 = 4
  1011011 = 5
  1011111 = 6
  1110000 = 7
  1111111 = 8
  1111011 = 9
*/

int displaytable[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},  //0
  {0, 1, 1, 0, 0, 0, 0},  //1
  {1, 1, 0, 1, 1, 0, 1},  //2
  {1, 1, 1, 1, 0, 0, 1},  //3
  {0, 1, 1, 0, 0, 1, 1},  //4
  {1, 0, 1, 1, 0, 1, 1},  //5
  {1, 0, 1, 1, 1, 1, 1},  //6
  {1, 1, 1, 0, 0, 0, 0},  //7
  {1, 1, 1, 1, 1, 1, 1},  //8
  {1, 1, 1, 1, 0, 1, 1}   //9  
};

void printdigit(int place, int digit, int decimal = 0) {
  digitalWrite(place+1, HIGH);
  for(int i = 6; i <= 12; i++) {
    digitalWrite(i, displaytable[digit][i-6]);
  }
  digitalWrite(13, decimal);
  delay(DELAYbwDIGITS);
  //digitalWrite(place+1, LOW);
  for(int i = 2; i <= 13; i++) {
    digitalWrite(i, LOW);
  }
}

void show(int num, int decplace = 0) {
  long a = millis();
  while(millis() - a <= DELAYbwTWOnos) {
    for(int i = 1; i <= 4; ++i) {
      if(int(num/pow(10,(4-i))) != 0) {
        if(i != decplace) {
          printdigit(i, ((num/pow(10,(4-i))) - (10*int(num/pow(10,(5-i))))));
        }
        if(i == decplace) {
          printdigit(i, ((num/pow(10,(4-i))) - (10*int(num/pow(10,(5-i))))), 1);
        }
      }
    }
  }
}

void loop() {
  //.................................Temperature on ssd......................................
  show(1206);
}
