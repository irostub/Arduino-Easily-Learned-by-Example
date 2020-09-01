/*

  예제 3.2
  I2C를 이용한 LCD 출력 예제입니다

*/
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);
void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.clear();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Arduino LCD");
  delay(1000);
  lcd.setCursor(0,1);
  lcd.print("Welcome");
  delay(250);

  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(250);
  lcd.noBacklight();
  delay(250);
  lcd.backlight();
  delay(3000);

  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Open Serial Mntr");
  lcd.setCursor(0,1);
  lcd.print("Type to display");
}

void loop()
{
  if(Serial.available()){
    delay(1000);
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("Message from PC");
    lcd.setCursor(0,1);

    while(Serial.available()>0){
      lcd.write(Serial.read());
    }
  }
}
