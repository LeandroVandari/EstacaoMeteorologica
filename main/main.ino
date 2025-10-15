#include <Arduino.h>
#include <stdio.h>

int i = 0;

void setup() {
  Serial.begin(9600);
  Serial3.begin(9600);
  Serial3.setTimeout(100000);

  Serial3.println("a");
  Serial3.println("12345678");
  Serial3.println("10.228.245.176");

}

void loop() {

  if (i < 10) {
      i += 1;
  Serial.println("MESSAGE FROM ESP: " + Serial3.readStringUntil('\n'));
  Serial.println(i);
  }
}