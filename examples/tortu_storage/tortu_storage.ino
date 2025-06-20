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
#include <TortuBotStorage.h>

TortuBot tortu;
TortuBotStorage storage;

void setup() {
    Serial.begin(115200);
    tortu.begin();

    storage.begin();

    // Guardar una configuración
    storage.saveConfig("nombre", "cefuve");
    storage.saveConfig("ssid", "MiRedWiFi");

    // Recuperar una configuración
    String nombre = storage.loadConfig("nombre");
    Serial.print("Nombre almacenado: ");
    Serial.println(nombre);

    // Limpiar configuraciones (opcional)
    // storage.clearConfig();
}

void loop() {
    // Nada aquí, ya que todo se hace en setup()
}