# Materiais necessário
- Arduino UNO
- Sensor BMP 180
- Sensor DHT22

# Conexões
## DHT 22:
Da esquerda para a direita:
- VIN (5V)
- D2
- Vazio (é só para debugging)
- GND
## BMP 180:
- VIN: 5V
- GND
- SCL: A5
- SDA: A4

# Bibliotecas
- Adafruit BMP085 Library
- DHT Sensor Library



# Módulo de WIFI
- Arduino Mega 2560
1. Programar ESP com os pinos 567 ON e 12348 OFF
    - Usar `Serial` para comunicação com o Arduino
    - `begin()` em 115200 baud
    - talvez tenha que apertar o botão MODE na placa enquanto programa (mas nos meus testes não precisou)
2. Programar Arduino com os pinos 34 ON e 125678 OFF
    - Usar `Serial3` para comunicação com o ESP.
    - `begin()` em 115200 baud
    - Usar `Serial` para debugging // printar coisas

3. Para executar:
    - pinos 1234 ON, 5678 OFF


https://forum.arduino.cc/t/esp8266-httpclient-library-for-https/495245/3