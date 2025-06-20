#include <TortuBot.h>
#include <TortuBotWiFi.h>

TortuBot tortu;
TortuBotWiFi wifi;

void wifiEvent(String respuesta){
  if(respuesta == "connected"){
    Serial.print("WiFi conectado, IP: ");
    Serial.println(wifi.getIP());
  }
  if(respuesta == "failed"){
    Serial.println("WiFi desconectado...");
  }
}

void setup() {
    Serial.begin(115200);
    tortu.begin();

    bool conectado = wifi.connect("TU_SSID", "TU_PASSWORD", 5);

    if (conectado) {
        Serial.print("WiFi conectado, IP: ");
        Serial.println(wifi.getIP());
    } else {
        Serial.println("No se pudo conectar a WiFi");
    }
    
    wifi.autoReconnect(true);
    wifi.setInterval(2000);
    wifi.onEvent(wifiEvent);
}

void loop() {
    wifi.loop();
}