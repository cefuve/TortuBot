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

TortuBot tortu;

void setup() {
    Serial.begin(115200);
    tortu.begin();
}

void loop() {
    tortu.moveForward(200); // Avanza a 80% de velocidad
    delay(1500);
    tortu.turnLeft(200);    // Gira a la izquierda a 80%
    delay(1000);
    tortu.moveBackward(128); // Retrocede a 50% de velocidad
    delay(1500);
    tortu.stop();           // Se detiene
    delay(2000);

    // Control individual de motores (prueba de hardware)
    tortu.setM1(255, true); // Solo motor 1 adelante velocidad al 100%
    tortu.setM2(0, true);   // Motor 2 apagado
    delay(1000);
    tortu.stopM1();
    tortu.stopM2();
    delay(1000);
}