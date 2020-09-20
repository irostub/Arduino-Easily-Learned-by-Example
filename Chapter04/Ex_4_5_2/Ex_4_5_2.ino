/*

  예제 4.5.2
  4 Digit FND에 1초마다 증가하는 0~9999 숫자 표시하기 예제입니다.
 
*/
const byte number[10] = {
  B00111111,
  B00000110,
  B01011011,
  B01001111,
  B01100110,
  B01101101,
  B01111101,
  B00000111,
  B01111111,
  B01101111,
}

const byte digitNumber[4] = {13,12,11,10};
int count = 0;
int value[4];
int digitSelect;
int count5ms;

void setup(){
  for(int i=2; i<=13; ++i){
    pinMode(i, OUTPUT);
  }
  for(int i=10; i<=13; ++i){
    digitalWrite(i,HIGH);
  }
}

void loop(){
  sampleTime = millis();
  fndDisplay(digitSelect, value[digitSelect-1]);
  ++digitSelect;
  if(digitSelect>=5) digitSelect=1;

  if(count>=9999) count = 0;
  else{
    while(millis()-sampleTime<5);
    ++count;
    if (count5ms>200){
      ++count;

      value[3] = count/1000;
      value[2] = (count - (value[3]*1000))/1000;
      value[1] = (count - (value[3]*1000)-(value[2]*100))/10;
      value[0] = (count - (value[3]*1000)-(value[2]*100)-value[1]*10));     

      count5ms = 0;
    }
  }
  }

void fndDisplay(int displayValue){
  boolean bitValue;
  for(int i=1; i<=4; ++i){
    digitalWrite(digitNumber[i-1],HIGH);
  }
  for(int i=0; i<=7; ++i){
    bitValue = bitRead(number[displayValue]);
    digitalWrite(i+2,bitValue);
  }
  for(int i=1; i<=4; ++i){
    if(digit==i) digitalWrite(digitNumber[i-1],LOW);
    else digitalWrite(digitNumber[i-1],HIGH);
  }
}
