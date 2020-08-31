/*

  예제 2.1의 응용문제 2번
  아두이노에서 컴퓨터로 변수와 문자열을 전송하기의 응용문제 코드입니다.
  
*/
int idx = 0;
const char *sets[] = {"Lorem ipsum dolor sit amet", "consectetur adipiscing elit."};

void setup() 
{
  Serial.begin(9600);   //9600bps로 시리얼 통신 설정
}

void loop() 
{
  Serial.println(sets[idx]);
  delay(2000);                                          //2초의 딜레이
  idx += 1;                                             //표시할 문자열 배열 인덱스 값 증가
  if(number == sizeof(sets)/sizeof(char*)) number = 0;  //문자열 배열의 인덱스 반복
}
