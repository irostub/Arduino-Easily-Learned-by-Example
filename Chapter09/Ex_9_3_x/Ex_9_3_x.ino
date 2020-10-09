#include "RTClib.h"
#include <LiquidCrystal.h>
RTC_DS3231 rtc;
LiquidCrystal lcd(12,11,5,4,3,2);
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

void setup () {
  lcd.begin(16,2);
  rtc.begin();
  rtc.adjust(DateTime(2020, 10, 10, 9, 14, 33));

}

void loop () {
    DateTime now = rtc.now();
    
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print(now.year());
    lcd.print('/');
    lcd.print(now.month());
    lcd.print('/');
    lcd.print(now.day());
    lcd.setCursor(0,1);
    lcd.print(daysOfTheWeek[now.dayOfTheWeek()]);
    lcd.print(' ');
    lcd.print(now.hour());
    lcd.print(':');
    lcd.print(now.minute());
    lcd.print(':');
    lcd.print(now.second());

    delay(1000);
}
