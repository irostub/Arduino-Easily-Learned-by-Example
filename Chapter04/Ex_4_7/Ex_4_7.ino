/*

  예제 4.7
  Matrix에 화살표 애니메이션 재생하기 예제입니다.
 
*/
byte arrow1[] = {
  B00000000,
  B00000000,
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001
}

byte arrow2[] = {
  B00000000,
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001,
  B00000000
}

byte arrow3[] = {
  B00011000,
  B00100100,
  B01011010,
  B10100101,
  B01000010,
  B10000001,
  B00000000,
  B00000000
}

const int columPins[] = {2,3,4,5,6,7,8,9};
const int rowPins[] = {10,11,12,15,16,17,18,19};

void setup(){
  for(int i=0; i<8; ++i){
    pinMode(columnPins[i],OUTPUT);
    digitalWrite(columnPins[i],HIGH);
  }
}

void loop(){
  output(arrow1,80);
  output(arrow2,80);
  output(arrow3,80);
  delay(300);
}

void output(byte *image, unsigned long time){
  unsigned long start = millis();

  while(start + time > millis()){
    for(int row=0; row<8; row++){
      digitalWrite(rowPins[row],HIGH);
      for(int column=0; column<8; column++){
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1) digitalWrite(columnPins[column],LOW);
        delayMicroseconds(300);
        digitalWrite(columnPins[column],HIGH);
      }
      digitalWrite(rowPins[row],LOW);
    }
  }
}
