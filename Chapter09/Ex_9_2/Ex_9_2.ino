#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("EX 9.2 DHT11 TEST ");
  Serial.println("");
  dht.begin();
}

void loop() {
  unsigned char t = dht.readTemperature();
  unsigned char h = dht.readHumidity();

  Serial.print("Temperture is ");
  Serial.print(t);
  Serial.println(" C");

  Serial.print("Humisity is ");
  Serial.print(h);
  Serial.println(" %");
  Serial.println(" ");

  delay(2000);

}
