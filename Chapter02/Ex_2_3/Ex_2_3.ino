/*

  예제 2.3
  컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기의 예제입니다

*/
const int ledPin = 13;
int blinkNumber = 0;
void setup() 
{
  Serial.begin(9600);
  pinMode(ledPin.OUTPUT);
}

void loop() 
{
  if(Serial.available()){
    char val = Serial.read();
  }
}
