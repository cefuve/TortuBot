#include <TortuBot.h>
#include <TortuBotWiFi.h>

TortuBot tortu;
TortuBotWiFi wifi;

void setup() {
    Serial.begin(115200);
    tortu.begin();

    bool conectado = wifi.connect("TU_SSID", "TU_PASS", 5);

    if (conectado) {
        Serial.print("WiFi conectado, IP: ");
        Serial.println(wifi.getIP());
    } else {
        Serial.println("No se pudo conectar a WiFi");
    }
}

void loop() {
    // Verificar conexión continuamente
    if (!wifi.isConnected()) {
        Serial.println("WiFi desconectado");
    }
    delay(2000);
}