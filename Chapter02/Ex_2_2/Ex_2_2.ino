/*

  예제 2.2
  변수 유형별 아두이노에서 컴퓨터로 전송하기의 예제입니다

*/
char charValue = 65;
int intValue = 65;
float floatValue = 65;

String stringValue[] = {"Binary:","Decimal:","Hexadecimal:","ASCII:"};

void setup() 
{
  Serial.begin(9600);
}

void loop() 
{
  Serial.println("*** char Value ***");
  Serial.print(stringValue[0]);
  Serial.println(charValue,BIN);
  Serial.print(stringValue[1]);
  Serial.println(charValue,DEC);
  Serial.print(stringValue[2]);
  Serial.println(charValue,HEX);
  Serial.print(stringValue[3]);
  Serial.write(charValue);

  Serial.println();
  Serial.println();

  Serial.println("*** int Value ***");
  Serial.print(stringValue[0]);
  Serial.println(intValue,BIN);
  Serial.print(stringValue[1]);
  Serial.println(intValue,DEC);
  Serial.print(stringValue[2]);
  Serial.println(intValue,HEX);
  Serial.print(stringValue[3]);
  Serial.write(intValue);

  Serial.println();
  Serial.println();

  Serial.println("*** float Value ***");
  Serial.print(floatValue);

  Serial.println();
  Serial.println();

  charValue++;
  intValue++;
  floatValue += 0.1;
  delay(1000);
  
}
