/*

  예제 2.1의 응용문제 1번
  아두이노에서 컴퓨터로 변수와 문자열을 전송하기의 응용문제 코드입니다.
  
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
  delay(2000);          //2초의 딜레이
  //delay(5000);        //5초의 딜레이
  number += 2;          //표시할 number값 2씩 증가
  //number += 5;        //표시할 number값 5씩 증가
}
