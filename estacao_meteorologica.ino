#include <SPI.h> // Serial Peripheral Interface --> comunicação com os periferais

const int PRESSURE_PIN = A0;

void setup() {
  Serial.begin(9600);
  Serial.println("Terminei o setup");
}

void loop() {
  // put your main code here, to run repeatedly:

}
