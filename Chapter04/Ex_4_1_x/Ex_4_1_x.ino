
/*

  예제 4.1을 응용하여 만든 예제입니다
  두 led의 점멸주기가 0.1초부터 5초까지 증가하고 5초에 도달하면 0.1초까지 감소를 반복하는 코드입니다

*/
const int ledA = 3;
const int ledB = 5;
int ratio = 1;
boolean switcher = 0;
void setup() 
{
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
}

void loop()
{
  digitalWrite(ledA, HIGH);
  digitalWrite(ledB, LOW);
  delay(ratio*100);
  digitalWrite(ledA, LOW);
  digitalWrite(ledB, HIGH);
  delay(ratio*100);

  if(ratio == 50)switcher = 1;
  else if(ratio == 1)switcher = 0;

  ratio = switcher? ratio - 1: ratio +1;
}
