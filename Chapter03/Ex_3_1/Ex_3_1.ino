/*

  예제 3.1
  입출력 핀을 이용하여 LCD 모듈에 표시하기 예제입니다

*/
#include <LiquidCrystal.h>

unsigned int time;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() 
{
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
