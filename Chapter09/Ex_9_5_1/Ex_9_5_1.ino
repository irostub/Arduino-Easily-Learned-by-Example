const char trigPin = 13;
const char echoPin = 12;
const int ledb = 7;
const int ledg = 6;
const int ledr = 5;

int pulseWidth;
int distance;

void setup() {
  Serial.begin(9600);
  pinMode(trigPin,OUTPUT);
  pinMode(echoPin,INPUT);
  pinMode(ledb, OUTPUT);
  pinMode(ledg, OUTPUT);
  pinMode(ledr, OUTPUT);
  digitalWrite(trigPin,LOW);
  
}

void loop() {
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);

  pulseWidth = pulseIn(echoPin,HIGH);
  distance = pulseWidth /58;

  if(distance <=200||distance >=2){
    if(distance > 0 && distance <= 30){
      digitalWrite(ledb, HIGH);
      digitalWrite(ledg, LOW);
      digitalWrite(ledr, LOW);
    }    
    else if(distance <= 60){
      digitalWrite(ledg, HIGH);
      digitalWrite(ledb, LOW);
      digitalWrite(ledr, LOW);
    }
    else{
      digitalWrite(ledr, HIGH);
      digitalWrite(ledb, LOW);
      digitalWrite(ledg, LOW);
    }
  }
  delay(100);
}
