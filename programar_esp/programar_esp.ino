#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiClientSecure.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>


ESP8266WiFiMulti WiFiMulti;
String network_ssid;
String network_pw;
const char* url = "https://script.google.com/";
const char* path = "macros/s/AKfycbxH9zMbxy4dt8LAHt_dszYhfjA-WVSbdXxZ-V8YBTgGDfqnoSL2N_3LCbBcAvyTggjeMg/exec";
const char* fingerprint = "10 90 B3 3F 30 77 D6 5D F3 F1 F4 8D D1 61 AA F5 9C D2 09 E6";

void setup() {
  Serial.begin(9600);
  // Serial.setDebugOutput(true);


  network_ssid = Serial.readStringUntil('\n');
  network_pw = Serial.readStringUntil('\n');
  network_ssid.trim();
  network_pw.trim();

 // ESPhttpUpdate.setClientTimeout(2000);  // default was 8000

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(network_ssid.c_str(), network_pw.c_str());
  while (WiFiMulti.run() != WL_CONNECTED) {}
  Serial.println("Wifi conectado!");
}


void loop() {
  // put your main code here, to run repeatedly:
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClientSecure client;
    HTTPClient http;
    client.setFingerprint(fingerprint);
   /*  for (int i = 0; i < 4; i++) {
      Serial.parseFloat();
    } */
    http.begin(client,url, 443, path );
    http.GET();
    http.addHeader("Content-Type", "application/json");
    http.POST("{\"data\": \"oiiiiiiii\"}");
    // --> do http.POST with the received contents;
  }
}
