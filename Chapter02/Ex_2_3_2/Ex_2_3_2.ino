/*

  예제 2.3의 응용문제 2번
  컴퓨터로부터 시리얼 통신을 통하여 데이터 수신하기의 응용문제 코드입니다

*/
int receiveNumber;
void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  if(Serial.available())
  {
    int val = Serial.read();    //다른 방법으로 Serial.parseInt() 가능
    if(isDigit(val))
    {
      receiveNumber = (val - '0');
      Serial.println(receiveNumber,BIN);
      Serial.println(receiveNumber,HEX);
    }
  }
}
