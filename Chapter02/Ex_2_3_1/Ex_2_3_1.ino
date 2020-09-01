/*

  예제 2.3의 응용문제 1번
  컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기의 응용문제 코드입니다

*/
const int ledPin = 13;        //제어할 핀 번호
int blinkNumber = -1;          //핀 점멸 회수제어 변수

void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);     //13번 핀에 대해 output으로 설정
}

void loop() 
{
  if(Serial.available())
  {
    char val = Serial.read(); //시리얼 모니터로부터 값 읽기 blocking 되지 않음
    if(isDigit(val))          //0~9의 숫자이면 True 반환, isDigit()함수
    {         
      blinkNumber=(val-'0');  //ASCII 0~9를 DEC 0~9로 변환하기 위해 ASCII기준 문자 0값 뺄셈
    }
  }
  
  if (blinkNumber != 0)       //입력값이 0이 아닐 때
  {
    for(int i = 0; i < blinkNumber; i++)
    {
      digitalWrite(ledPin, HIGH); //led on
      delay(blinkNumber*1000);
      digitalWrite(ledPin,LOW);   //led off
      delay(blinkNumber*1000);
    }
  }
  else
  {
      digitalWrite(ledPin, HIGH);
      delay(500);
      digitalWrite(ledPin,LOW); 
      delay(500);
  }
  blinkNumber = -1;           //초기화
}
