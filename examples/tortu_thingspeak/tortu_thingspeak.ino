/*
  TortuBot

  Copyright (c) 2025 CEAR INACAP.  All right reserved.
  License: GPL 3.0.

  This program comes with ABSOLUTELY NO WARRANTY.
  This is free software, and you are welcome to redistribute it
  under certain conditions.

  Created 19 Jun 2025
  Cesar Fuenzalida Vergara @cefuve
*/

#include <TortuBot.h>
#include <TortuBotWiFi.h>
#include <TortuBotThingSpeak.h>

TortuBot tortu;
TortuBotWiFi wifi;
TortuBotThingSpeak cloud;

void setup() {
    Serial.begin(115200);
    tortu.begin();
    wifi.connect("TU_SSID", "TU_PASS", 10);

    // Configura tu canal y API Key de ThingSpeak
    cloud.config("TU_CHANNEL", "TU_API_KEY");
}

void loop() {
    // Leer sensor central y enviar a ThingSpeak campo 1
    int value = tortu.readCenterIR();
    bool ok = cloud.sendField(1, value);

    Serial.print("Enviado a ThingSpeak: ");
    Serial.println(ok ? "OK" : "Fallo");

    delay(15000); // ThingSpeak requiere mínimo 15 s entre envíos
}