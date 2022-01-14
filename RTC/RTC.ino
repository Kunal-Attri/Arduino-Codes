/*
Demonstration of Rtc_Pcf8563 Date Time individual functions. 
Set the clock to a time then loop over reading time and output the time and date to the serial console.

I used a RBBB with Arduino IDE, the pins are mapped a bit differently. 
SCK - A5, SDA - A4, INT - D3/INT1

After loading and starting the sketch, use the serial monitor
to see the clock output.

Setup:  see Pcf8563 data sheet.
        1x 10Kohm pullup on Pin3 INT
        No pullups on Pin5 or Pin6 (I2C internals used)
        1x 0.1pf on power
        1x 32khz chrystal
*/

#include <Rtc_Pcf8563.h>

Rtc_Pcf8563 rtc;

void setup() {
  Serial.begin(9600);
  Serial.println("Setting RTC Date and Time");
  //to clear previous registers
  rtc.initClock();
  //set date (day, weekday, month, century(1=19, 0=20), year(0-99)
  rtc.setDate(16, 3, 12, 0, 20);
  //set time (hr, min, sec)
  rtc.setTime(13, 17, 45);
  Serial.print("Date set to : "); Serial.println(rtc.formatDate());
  Serial.print("Time set to: "); Serial.println(rtc.formatTime());
  Serial.print("Now reading back from chip\n");
}

void loop() {
  Serial.print("Hour: "); Serial.println(rtc.getHour());
  Serial.print("Minutes: "); Serial.println(rtc.getMinute());
  Serial.print("Seconds: "); Serial.println(rtc.getSecond());
  Serial.print("Weekday: "); Serial.println(rtc.getWeekday());
  Serial.print("Day: "); Serial.println(rtc.getDay());
  Serial.print("Month: "); Serial.println(rtc.getMonth());
  Serial.print("Year: "); Serial.println(rtc.getYear());
  delay(1000);
}
