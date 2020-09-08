/*

  예제 4.2
  LED 밝기 조절에 대한 예제입니다

*/
const int ledA = 3;
const int ledB = 5;
int brightness = 0;
int increment = 1;

void setup() 
{
  //analogWrite 핀은 별도 설정 불필요
}

void loop()
{
  analogWrite(ledA, brightness);
  analogWrite(ledB, 255 - brightness);

  brightness = brightness + increment;

  if((brightness >= 255)||(brightness <= 0)) increment = -increment;
  delay(1);
}
