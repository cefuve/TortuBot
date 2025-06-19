#include <TortuBot.h>

TortuBot tortu;

void setup() {
    Serial.begin(115200);
    tortu.begin();
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