/*

  예제 2.2의 응용문제 2번
  변수 유형별 아두이노에서 컴퓨터로 전송하기의 응용문제 코드입니다

*/
int x = 5;
float y = 1.1;

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.print("Sum:");
  Serial.println(x + y);
  Serial.print("Sub:");
  Serial.println(x - y);
  Serial.print("Mult:");
  Serial.println(x * y);
  Serial.print("Div:");
  Serial.println(x / y);

  Serial.println();
  Serial.println();
  
  delay(1000);

  x += 1;
  y += 0.1;
}
