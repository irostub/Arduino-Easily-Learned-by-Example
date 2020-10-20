#include <Servo.h>

Servo motor1;

int switchPin = 2;
int state = 0;
int servoMotorPin = 9;

void setup() {
  motor1.attach(servoMotorPin, 600, 2400);
  pinMode(switchPin, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  int motorAngle = 0;

  while(digitalRead(switchPin) == LOW){
    if(motorAngle == 180)state = 1;
    else if(motorAngle == 0)state = 0;
    motor1.write(motorAngle);
    if(state)motorAngle--;
    else motorAngle++;
    
    delay(10);
  }
}
