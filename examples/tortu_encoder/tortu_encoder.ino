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
    tortu.initEncoders();
}

void loop() {
    Serial.print("Encoder1: ");
    Serial.print(tortu.readEncoder1());
    Serial.print(" | Encoder2: ");
    Serial.println(tortu.readEncoder2());

    delay(500);
}