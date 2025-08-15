#include <SPI.h> // Serial Peripheral Interface --> comunicação com os periferais
#include "DHT.h"

DHT dht(2, DHT22);

const int PRESSURE_PIN = A1;

void setup() {
  Serial.begin(9600);
  dht.begin();
  Serial.println("Terminei o setup");
 // SPI.begin();
 // SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  Serial.println(hum);
  Serial.println(temp);

  Serial.println("   ");
  delay(1000);
}
