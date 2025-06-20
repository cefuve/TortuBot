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
#include <TortuBotHTTP.h>

TortuBotWiFi wifi;
TortuBotHTTP http;

void onHTTPResponse(String respuesta) {
    Serial.println("HTTP Server respondió:");
    Serial.println(respuesta);
}

void setup() {
    Serial.begin(115200);
    wifi.connect("SSID", "PASSWORD");

    http.onEvent(onHTTPResponse);

    // Usar GET
    String data = http.get("http://httpbin.org/get");

    // Usar POST
    String payload = "name=cefuve&value=123";
    String resp = http.post("http://httpbin.org/post", payload);
}

void loop() {

}
