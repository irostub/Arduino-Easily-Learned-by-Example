/*

  예제 6.6
  마이크 입력 실험 예제입니다.
 
*/
#include <LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);

int soundInputPin = 0;

void setup() {
 lcd.begin(16,2);
 lcd.print("MEP-6 Ex 6.6");
 lcd.setCursor(0,1);
 lcd.print("MIC level");
 delay(3000);
 lcd.clear();
 lcd.setCursor(0,0);
 lcd.print("ADC :");
 lcd.setCursor(0,1);
 lcd.print("MIC :");
 lcd.setCursor(15,1);

}

void loop() {
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ADC :");
  lcd.setCursor(0,1);
  lcd.print("MIC :");
  lcd.setCursor(15,1);
  int soundInput = analogRead(soundInputPin);
  int soundLevel = map(soundInput, 50, 900, 0, 100);
  lcd.setCursor(6,0);
  lcd.print(soundInput);
  lcd.setCursor(6,1);
  lcd.print(soundLevel);
  
  delay(100);
}
