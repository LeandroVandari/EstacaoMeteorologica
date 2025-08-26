#include <SPI.h> // Serial Peripheral Interface --> comunicação com os periferais
#include "DHT.h"
#include <Adafruit_BMP085.h>

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

const int PRESSURE_PIN = A1;

void setup() {
  Serial.begin(9600);
  dht.begin();
  bmp.begin();
  Serial.println("Terminei o setup");
 // SPI.begin();
 // SPI.beginTransaction(SPISettings(5000000, MSBFIRST, SPI_MODE0));
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp = dht.readTemperature();
  float pressure = bmp.readPressure();
  Serial.println("Umidade: " +String(hum) + "%");
  Serial.println("Temperatura: "+String(temp) + "°C");
  Serial.println("Pressão: "+String(pressure) + "Pa");

  Serial.println("   ");
  delay(1000);
}
