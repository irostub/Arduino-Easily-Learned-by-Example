/*
 예제 9.2 응용실험
 온/습도 센서를 이용한 온습도 측정하여
 온/습도의 변화가 있을 시, LCD 모듈에 온/습도 값을 출력하기.
 */

// DHT 라이브러리를 추가한다.
#include "DHT.h"
#include <LiquidCrystal.h>

#define DHTPIN 6    // DHT11이 연결된 핀을 설정한다.
#define DHTTYPE DHT11     // 연결된 센서의 종류를 설정한다. DHT 11

// DHT 이란 이름으로 센서 이름을 설정한다.
DHT dht(DHTPIN, DHTTYPE);

unsigned char t1=0;     // 다음에 얻을 온도 값과 비교를 위해 이전에 읽은 온도 값을 저장 
unsigned char h1=0;     // 다음에 얻을 습도 값과 비교를 위해 이전에 읽은 습도 값을 저장

// LCD 설정
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

void setup() {
  // 16x2 LCD 설정
  lcd.begin(16, 2);
  lcd.clear();

  // 시리얼 통신을 설정하고 초기 메세지를 출력한다.
  Serial.begin(9600);
  Serial.println("EX 9.2 DHT11 Test ");
  Serial.println("");
  dht.begin();    // DHT11 센서를 시작한다.
}

void loop() {
  unsigned char t = dht.readTemperature();    // 온도를 읽는다.
  unsigned char h = dht.readHumidity();       // 습도를 읽는다.

  // LCD 첫 번째 줄을 출력 위치로 설정
  lcd.setCursor(0, 0);
  // 온도 출력
  lcd.print("Temp is ");
  lcd.print(t);
  // LCD 두 번째 줄을 출력 위치로 설정
  lcd.setCursor(0, 1);
  // 습도 출력
  lcd.print("Humidity is ");
  lcd.print(h);
  
  // 현재 얻은 온도 값과 이전 온도 값을 비교
  if(t1 != t || h1 != h) { 
    Serial.print("Temperature is ");
    Serial.print(t);
    Serial.println("20 C");
    Serial.print("Humidity is ");
    Serial.print(h);
    Serial.println(" %");
    Serial.println(" ");
    t1 = t;
    h1 = h;
  }

  // 온습도를 다시 측정하기 위해 2초를 쉰다.
  delay(2000);
}
