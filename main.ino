#include "DHT.h" // Sensor de temperatura e umidade
#include <Adafruit_BMP085.h> // Sensor de temperatura e pressão

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

const int PRESSURE_PIN = A1;

void setup() {
  Serial.begin(9600);
  Serial.println("Iniciando o setup");
  dht.begin();
  Serial.println("DHT iniciado");
  bmp.begin();
  Serial.println("BMP iniciado);
  Serial.println("Terminei o setup");
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp_dht = dht.readTemperature();
  float temp_bmp = bmp.readTemperature();
  float pressure = bmp.readPressure();
  Serial.println("Umidade: " +String(hum) + "%");
  Serial.println("Temperatura (DHT): "+String(temp_dht) + "°C");
  Serial.println("Temperatura (BMP): "+String(temp_bmp) +"°C");
  Serial.println("Pressão: "+String(pressure) + "Pa");

  Serial.println("   ");
  delay(1000);
}
