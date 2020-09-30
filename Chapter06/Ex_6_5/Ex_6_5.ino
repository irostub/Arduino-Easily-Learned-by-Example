/*

  예제 6.5
  조이스틱 좌표 제어 실험 예제입니다.
 
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

const int xAxisPin = 0;
const int yAxisPin = 1;
const int zAxisPin = 7;

void setup(){
  pinMode(zAxisPin, INPUT_PULLUP);
  lcd.begin(16,2);
  lcd.print("MEP-6 Ex 6.5");
  lcd.setCursor(0,1);
  lcd.print("Joystic");

  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("X:");
  lcd.setCursor(0,1);
  lcd.print("Y:");
  lcd.setCursor(15,1);
}

void loop(){
  int xValue = analogRead(xAxisPin);
  int yValue = analogRead(yAxisPin);
  int zValue = analogRead(zAxisPin);

  int xDisplay = map(xValue, 0, 1023,6, 15);
  int yDisplay = map(yValue, 0, 1023,6, 15);

  lcd.setCursor(2,0);
  lcd.print("              ");
  lcd.setCursor(2,0);
  lcd.print(xValue);
  lcd.setCursor(xDisplay,0);
  lcd.print("|");

  lcd.setCursor(2,1);
  lcd.print("              ");
  lcd.setCursor(2,1);
  lcd.print(yValue);
  lcd.setCursor(yDisplay,1);
  lcd.print("|");

  if(zValue == LOW){
  lcd.setCursor(xDisplay,0);
  lcd.print("-Z-");
  lcd.setCursor(yDisplay,1);
  lcd.print("-Z-");
  }
  delay(100);
}
