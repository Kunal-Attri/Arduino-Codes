#define del 100
#include <LiquidCrystal.h>
#include <Rtc_Pcf8563.h>
#include "thermistor.h"
String time_sum= ":";
String date_sym = "-";
const int rs = 7, en = 6, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
int temp_update = 0;
float Temperature = 0.0;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
Rtc_Pcf8563 rtc;

void setup() {
  lcd.begin(16, 2);
  pinMode(A3, OUTPUT);
  digitalWrite(A3, HIGH);
  
  lcd.setCursor(0, 0);
  lcd.print("Testing");
  delay(5*del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.setCursor(0, 1);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del);
  lcd.print(".");
  delay(del*5);
  lcd.clear();
  lcd.setCursor(4, 0);
  lcd.print("Made by");
  lcd.setCursor(2, 1);
  lcd.cursor();
  delay(5*del);
  lcd.print("K");
  delay(5*del);
  lcd.print("u");
  delay(5*del);
  lcd.print("n");
  delay(5*del);
  lcd.print("a");
  delay(5*del);
  lcd.print("l");
  delay(5*del);
  lcd.print(" ");
  delay(5*del);
  lcd.print("A");
  delay(5*del);
  lcd.print("t");
  delay(5*del);
  lcd.print("t");
  delay(5*del);
  lcd.print("r");
  delay(5*del);
  lcd.print("i");
  lcd.noCursor();
  delay(20*del);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Date");
  lcd.setCursor(12, 0);
  lcd.print("Temp");
  lcd.setCursor(6, 1);
  lcd.print("Time");
  delay(20*del);
  
  float Therm1{ readCelcius(A6) };
  float Therm2{ readCelcius(A7) };
  Temperature= (Therm1 + Therm2) / 2;
}
void loop() {
  if (temp_update == 15) {
    float Therm1{ readCelcius(A6) };
    float Therm2{ readCelcius(A7) };
    Temperature= (Therm1 + Therm2) / 2;
    temp_update= 0;
  }
  lcd.setCursor(0, 0);
  lcd.print(rtc.getDay());
  lcd.print(date_sym);
  lcd.print(rtc.getMonth());
  lcd.print(date_sym);
  lcd.print(rtc.getYear());
  lcd.setCursor(10, 0);
  lcd.print(Temperature);
  lcd.print("C");
  lcd.setCursor(4, 1);
  lcd.print(rtc.formatTime());
  delay(10*del);
  temp_update += 1;
  lcd.clear();
}
