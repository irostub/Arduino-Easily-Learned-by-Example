/*

  예제 3.1
  입출력 핀을 이용하여 LCD 모듈에 표시하기 예제입니다

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

unsigned int time;
LiquidCrystal_I2C lcd(0x27,16,2);

void setup() 
{
  lcd.init();
  lcd.clear();
  lcd.backlight();
  lcd.begin(16, 2);
  lcd.print("Arduino");
}

void loop() 
{
  lcd.setCursor(0, 1);
  lcd.print(time);
  ++time;
  delay(1000);
}
