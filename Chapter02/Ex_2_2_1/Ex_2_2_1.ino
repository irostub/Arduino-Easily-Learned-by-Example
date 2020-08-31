/*

  예제 2.2의 응용문제 1번
  변수 유형별 아두이노에서 컴퓨터로 전송하기의 응용문제 코드입니다

*/
int x[16] = {B0000000};
int idx = 0;

void setup() 
{
  for (int i = 1; i < 16; i++)
  {
    x[i] = x[i-1] + B0000001;  
  } 
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Binary:");
  Serial.println(x[idx],BIN);
  Serial.print("Decimal:");
  Serial.println(x[idx],DEC);
  Serial.print("Hexadecimal:");
  Serial.println(x[idx],HEX);
  Serial.println();
  Serial.println();
  idx++;
  if(idx > 15) idx = 0;
  
  delay(1000);
}
