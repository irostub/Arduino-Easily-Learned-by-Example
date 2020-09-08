/*

  예제 4.2.1
  LED 밝기 조절에 대한 예제의 1번 응용문제 코드입니다

*/
const int leds[5] = {3, 5, 6, 9, 10};
int brightness = 0;
boolean switcher = 0;

void setup() 
{
  //analogWrite 핀은 별도 설정 불필요
}

void loop()
{
  for(int i = 0; i < sizeof(leds)/sizeof(int); i++)
  {
    analogWrite(leds[i], brightness);
  }
  
  if(brightness == 0)switcher = 1;
  else if(brightness == 255)switcher = 0;

  brightness = switcher? brightness+1 : brightness-1;
  
  delay(10);
}
