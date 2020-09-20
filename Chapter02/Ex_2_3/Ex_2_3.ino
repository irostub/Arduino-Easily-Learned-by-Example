/*

  예제 2.3
  컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기의 예제입니다

*/
const int ledPin = 13;        //제어할 핀 번호
int blinkNumber = 0;          //핀 점멸 회수제어 변수
void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);     //13번 핀에 대해 output으로 설정
}

void loop() 
{
  if(Serial.available())
  {
    char val = Serial.read(); //시리얼 모니터로부터 값 읽기 block됨
    if(isDigit(val))          //0~9의 숫자이면 True 반환, isDigit()함수
    {         
      blinkNumber=(val-'0');  //ASCII 0~9를 DEC 0~9로 변환하기 위해 ASCII기준 문자 0값 뺄셈
      Serial.print("입력값으로 ");
      Serial.print(blinkNumber);
      Serial.println("이 들어옴");
    }
  }
  for(char i = 0; i < blinkNumber; i++)
  {
    Serial.print("ledPin 13번 점멸 ");
    Serial.print(int(i));
    Serial.println("번째 반복 중");
    digitalWrite(ledPin, HIGH); //led on
    delay(200);
    digitalWrite(ledPin,LOW);   //led off
    delay(200);
  }
  blinkNumber = 0;
}
