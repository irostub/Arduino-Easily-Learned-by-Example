/*
 예제 5.3 응용실험
 16x2 LCD에 스위치 입력 시간을 출력하기
 */

// LCD 모듈 라이브러리를 불러온다.
#include <LiquidCrystal.h>

// time 변수 설정
unsigned int time;

// LCD 설정
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

// 7번 핀을 스위치 입력으로 설정
const int inputPin = 7;

// 현재의 시간을 저장하기 위한 변수
long startTime = 0;

// 실제 스위치가 눌린 후 지연되는 시간
long swCountTimer = 0;

void setup() {
  // 스위치 입력을 위하여 7번 핀을 입력으로 설정하고 풀업시킨다.
  pinMode(inputPin, INPUT_PULLUP);
  
  // 16x2 LCD 설정
  lcd.begin(16, 2);
  
  // 시리얼 통신을 설정한다.
  Serial.begin(9600);
  lcd.clear();
}

void loop() {
  // 스위치 입력이 발생하였을 경우 실행
  if (digitalRead(inputPin) == LOW) {
    
    // 현재의 시간을 startTime 변수에 넣는다.
    startTime = millis();
    // 스위치가 입력되는 동안 지연시킨다.
    while(digitalRead(inputPin) == HIGH);
    
    // swCountTimer 변수에 스위치가 눌려진 시간을 넣는다.
    // 여기까지 측정된 시간에서 앞서 저장한 시간이 스위치가 눌려진 시간이 된다.
    swCountTimer = millis();
    swCountTimer = swCountTimer - startTime;
    // lcd로 값을 출력한다.
    lcd.setCursor(0, 0);
    lcd.clear();
    lcd.print(swCountTimer);
    lcd.print("ms");
    Serial.println(swCountTimer);
  };
}
