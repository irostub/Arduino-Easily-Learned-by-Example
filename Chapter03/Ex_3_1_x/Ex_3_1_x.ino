/*

  예제 3.1.x
  LCD를 응용하여 만든 예제입니다
  이름과 시계를 포함합니다

*/
#include <LiquidCrystal.h>

int second = 0;
int minute = 0;
int hour = 0;
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
char buf[8];

void setup() 
{
  lcd.begin(16,2);
  lcd.setCursor(0,0);
  lcd.print("Name");
}

void loop() 
{
  second++;
  if(second == 60)
  {
    second = 0;
    minute++;
    if(minute == 60)
    {
      minute = 0;
      hour++;
    }
  }
  sprintf(buf,"%02d:%02d:%02d",hour,minute,second);
  lcd.setCursor(0,1);
  lcd.print(buf);
  delay(100);
}
