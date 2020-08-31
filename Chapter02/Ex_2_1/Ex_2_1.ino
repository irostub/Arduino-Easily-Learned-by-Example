/*

  예제 2.1
  아두이노에서 컴퓨터로 변수와 문자열을 전송하기의 예제입니다
  
*/
int number = 0;

void setup() 
{
  Serial.begin(9600);   //9600bps로 시리얼 통신 설정
}

void loop() 
{
  Serial.print(number);
  Serial.println(" sec");
  delay(1000);          //단위 ms
  number++;
}
