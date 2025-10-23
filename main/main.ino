#include "DHT.h" // Sensor de temperatura e umidade
#include <Adafruit_BMP085.h> // Sensor de temperatura e pressão
#include <stdio.h>
#include <Arduino.h>

DHT dht(2, DHT22);
Adafruit_BMP085 bmp;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial3.setTimeout(100000);

  Serial.println("Iniciando o setup");

  Serial.println("Enviando dados da rede para o ESP...");
  Serial3.println("a");
  Serial3.println("12345678");

  Serial.println("Iniciando DHT...");
  dht.begin();
  Serial.println("Iniciando BMP...");
  bmp.begin();

  Serial.println("Terminei o setup");
  Serial.println(Serial3.readStringUntil('\n'));
}

void loop() {
  // put your main code here, to run repeatedly:
  float hum = dht.readHumidity();
  float temp_dht = dht.readTemperature();
  float temp_bmp = bmp.readTemperature();
  float pressure = bmp.readPressure();
  float floatarray[4] = {hum, temp_dht, temp_bmp, pressure}; 
  uint8_t send[sizeof(floatarray) *sizeof(float)];
  memcpy(send, floatarray, sizeof(floatarray));
  Serial3.write(send, 16);


  Serial.println("Umidade: " +String(hum) + "%");
  Serial.println("Temperatura (DHT): "+String(temp_dht) + "°C");
  Serial.println("Temperatura (BMP): "+String(temp_bmp) +"°C");
  Serial.println("Pressão: "+String(pressure) + "Pa");

  Serial.println("   ");
  delay(1000);
}
