/*

  예제 4.2.2
  LED 밝기 조절에 대한 예제의 2번 응용문제 코드입니다

*/
const int leds[5] = {3, 5, 6, 9, 10};
int ledBrightness[5] = {255, 255, 255, 255, 255};
boolean switcher = 1;

void setup() 
{
  for(int i = 0; i < 5; i++)
  {
    analogWrite(leds[i],ledBrightness[i]);
  }
}

void loop()
{
  for(int i = 0; i < 5; i++)
  {
    for(int j = 0; j < 255; j++){
      if(switcher)ledBrightness[i]--;
      else ledBrightness[i]++;
      analogWrite(leds[i],ledBrightness[i]);
      delay(5);
    }
  }
  switcher = !switcher;
}
