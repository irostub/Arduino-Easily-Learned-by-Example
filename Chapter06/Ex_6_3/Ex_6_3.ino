/*

  예제 6.3
  온도값 입력 실험 예제입니다.
 
*/
#include <LiquidCrystal.h>

unsigned int time;
LiquidCrystal lcd(12,11,5,4,3,2);

const int LM35Pin = 0;

void setup() {
  lcd.begin(16,2);
  lcd.print("Arduino MEP-6");
  lcd.print("Checking Temp.");
  
  delay(3000);  

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("ADC : ");
  lcd.setCursor(0,1);
  lcd.print("Temp. is ");

  lcd.setCursor(13,1);
  lcd.write(B11011111);
  lcd.setCursor(14,1);
  lcd.print("C");
}

void loop() {
  int adcValue;
  long temp;

  adcValue = analogRead(LM35Pin);
  temp = (adcValue * 500L) / 1024;

  lcd.setCursor(9,0);
  lcd.print("    ");
  lcd.setCursor(9,0);
  lcd.print(adcValue);

  lcd.setCursor(10,1);
  lcd.print("   ");
  lcd.setCursor(10,1);
  lcd.print(temp);

  delay(1000);
}
