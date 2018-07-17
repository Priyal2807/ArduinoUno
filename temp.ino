#include <dht.h>
#define dht_apin A0
dht DHT;
int temp=0;
int hum=0;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  delay(500);
  Serial.println("Evaluating a greenhouse tmp");
  delay(1000);
}

void loop() {
    DHT.read11(dht_apin);
  temp=DHT.temperature;
  hum=DHT.humidity;
  Serial.println("Temp is:");
  Serial.println(temp);
  Serial.print("Humidity is");
  Serial.print(hum);
  // put y0ur main code here, to run repeatedly:
delay(5000);
}
