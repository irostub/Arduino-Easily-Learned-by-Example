/*

  예제 5.1.1
  스위치 입력의 응용 예제입니다.
 
*/
const int ledPin=13;
const int inputPin=2;

void setup(){
  pinMode(ledPin,OUTPUT);
  pinMode(inputPin,INPUT_PULLUP);
}

void loop(){
  int swInput = digitalRead(inputPin);
  int ledOutPut = digitalRead(ledPin);
  
  if(swInput == LOW){
    if(ledOutPut) digitalWrite(ledPin, LOW);
    else digitalWrite(ledPin,HIGH);
  }
}
