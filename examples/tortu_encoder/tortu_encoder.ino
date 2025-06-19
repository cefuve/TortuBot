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