#include <Arduino.h>

#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>

#include <ESP8266HTTPClient.h>
#include <ESP8266httpUpdate.h>


ESP8266WiFiMulti WiFiMulti;
String ip_servidor;


void setup() {
  Serial.begin(9600);
  // Serial.setDebugOutput(true);


  String network_ssid = Serial.readString();
  String network_pw = Serial.readString();
  ip_servidor = Serial.readString();

  ESPhttpUpdate.setClientTimeout(2000);  // default was 8000

  WiFi.mode(WIFI_STA);
  WiFiMulti.addAP(network_ssid.c_str(), network_pw.c_str());

}


void loop() {
  // put your main code here, to run repeatedly:
  if ((WiFiMulti.run() == WL_CONNECTED)) {

    WiFiClient client;

    // The line below is optional. It can be used to blink the LED on the board during flashing
    // The LED will be on during download of one buffer of data from the network. The LED will
    // be off during writing that buffer to flash
    // On a good connection the LED should flash regularly. On a bad connection the LED will be
    // on much longer than it will be off. Other pins than LED_BUILTIN may be used. The second
    // value is used to put the LED on. If the LED is on with HIGH, that value should be passed
    ESPhttpUpdate.setLedPin(LED_BUILTIN, LOW);

    client.connect(ip_servidor.c_str(), 8000);
    client.print("hiiiii\n\0");
    /* t_httpUpdate_return ret = ESPhttpUpdate.update(client, "http://server/file.bin");
    // Or:
    // t_httpUpdate_return ret = ESPhttpUpdate.update(client, "server", 80, "file.bin");

    switch (ret) {
      case HTTP_UPDATE_FAILED: Serial.printf("HTTP_UPDATE_FAILD Error (%d): %s\n", ESPhttpUpdate.getLastError(), ESPhttpUpdate.getLastErrorString().c_str()); break;

      case HTTP_UPDATE_NO_UPDATES: Serial.println("HTTP_UPDATE_NO_UPDATES"); break;

      case HTTP_UPDATE_OK: Serial.println("HTTP_UPDATE_OK"); break;
    } */
  }
}
