/*
 예제 4.5.1 응용실험
 4-digit FND에 'XXX1', 'XX2X', 'X3XX', '4XXX' 의 표시가 1초 간격으로 반복하는 제어 프로그램
 */

// 0~9까지 LED 표시를 위한 상수
const byte number[10] = {
 B00111111,    // 0
 B00000110,    // 1
 B01011011,    // 2
 B01001111,    // 3
 B01100110,    // 4
 B01101101,    // 5
 B01111101,    // 6
 B00000111,    // 7
 B01111111,    // 8
 B01101111    // 9

// B11000000,    // 0
// B11111001,    // 1
// B10100100,    // 2
// B10110000,    // 3
// B10011001,    // 4
// B10010010,    // 5
// B10000010,    // 6
// B11111000,    // 7
// B10000000,    // 8
// B10010000    // 9
};

// 표시할 숫자 변수
int count = 0;

void setup()
{
  // 2~9번 핀을 a b c d e f g dot의 순서로 사용한다.
  // 10~13번 핀을 Digit 1~4의 순서로 사용한다.
  for (int i = 2; i<=13; i++) {
    pinMode(i, OUTPUT);   // 2~13번 핀을 출력으로 설정한다.
  };

  // 4 digit와 연결된 10~13번 핀에 모두 LOW 신호를 줘서 점등시킨다.
  for(int i = 10; i<=13; i++) { 
    digitalWrite(i, HIGH);
  };
}

void loop() 
{
  // 4 digit중 표시를 원하는 digit만 켠다.
  for(int i =13; i>=10; --i)
  {
     // count 변수 값을 FND에 출력한다.
    fndDisplay(count);
    digitalWrite(i, LOW);
    delay(1000);
    digitalWrite(i, HIGH);
    count++;
  }

  
  // count 변수 값이 0~9의 범위를 갖도록 한다.
  if(count >= 9) count = 1;
}

// LED 켜는 루틴
void fndDisplay(int displayValue) {
  // bitValue 변수를 선언한다.
  boolean bitValue;
  int i = 13;

  // 2~9번 핀에 모두 LOW 신호를 줘서 소등시킨다.
  for(int i=2; i<=9; ++i) {
    digitalWrite(i, LOW);
  };

  for(int i=0; i<=7; ++i) {
    // number 상수의 하나의 비트 값을 읽는다.
    bitValue = bitRead(number[displayValue], i);
    // 앞서 읽은 비트 값을 2~9번 핀에 출력시킨다.
    digitalWrite(i+2, bitValue);
  };  
}
