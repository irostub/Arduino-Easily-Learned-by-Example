
int motorPin1 = 8;
int motorPin2 = 9;
int motorPin3 = 10;
int motorPin4 = 11;

int switchPin = 2;
int state = 1;
int stopRange = 100;

int steps[] = {B1000,B1100,B0100,B0110,B0010,B0011,B0001,B1001,B0000};

void setup() {
  pinMode(motorPin1, OUTPUT);
  pinMode(motorPin2, OUTPUT);
  pinMode(motorPin3, OUTPUT);
  pinMode(motorPin4, OUTPUT);
  pinMode(switchPin, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  int switchInput = digitalRead(switchPin);
  
  if(switchInput == LOW){
    if(state == 1)state = 0;
    else if(state == 0)state = -1;
    else state = 1;
    delay(300);
  }
  
  if(state == 1){
    Serial.println("State : CW Motor");
    clockwise();
  }
  else if(state == -1){
    Serial.println("State : CCW Motor");
    counterClockwise();
  }
  else{
    Serial.println("State : Motor Stop");
    motorStop();
  }
}

void clockwise(){
  for(int i = 7; i>=0; i--){
  motorSignalOutput(i);
  delayMicroseconds(1000);
  }
}

void counterClockwise(){
  for(int i = 0; i<8; i++){
    motorSignalOutput(i);
    delayMicroseconds(1000);
  }
}

void motorStop(){
  motorSignalOutput(8);
}

void motorSignalOutput(int out){
  digitalWrite(motorPin1, bitRead(steps[out], 0));
  digitalWrite(motorPin2, bitRead(steps[out], 1));
  digitalWrite(motorPin3, bitRead(steps[out], 2));
  digitalWrite(motorPin4, bitRead(steps[out], 3));
}
