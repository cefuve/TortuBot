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
    tortu.beep(40);
}

void loop() {
    // Leer sensores
    int left = tortu.readLeftIR();
    int center = tortu.readCenterIR();
    int right = tortu.readRightIR();

    Serial.print("IR Left: ");
    Serial.print(left);
    Serial.print(" | IR Center: ");
    Serial.print(center);
    Serial.print(" | IR Right: ");
    Serial.println(right);

    // Prender LED si el sensor central detecta línea (umbral 500)
    if (center > 500) {
        tortu.setLED(true);
        tortu.beep(100);
    } else {
        tortu.setLED(false);
    }

    delay(500);
}