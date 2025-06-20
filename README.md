# TortuBot

**Librería educativa modular para robótica en ESP32**

TortuBot es una librería orientada a la robótica educativa con ESP32. Permite controlar motores DC, encoders, sensores infrarrojos, LED y buzzer, y opcionalmente conectar el robot a Internet mediante WiFi, HTTP o ThingSpeak.  
Está pensada para ser **modular**: puedes usar solo el hardware básico o agregar los módulos de conectividad cuando los necesites.

---

## Instalación

1. Descarga este repositorio como ZIP, o clónalo usando:
    ```sh
    git clone https://github.com/cefuve/TortuBot.git
    ```
2. Copia la carpeta `TortuBot` dentro de tu carpeta de librerías de Arduino (`~/Arduino/libraries/`).
3. Reinicia el IDE de Arduino.

> **Nota:** Se recomienda usar el “core” oficial de ESP32 actualizado.

---

## Características principales

- Control de motores DC con velocidad y dirección
- Lectura y reset de encoders de cuadratura
- Lectura de sensores infrarrojos (3 canales)
- Control de LED y buzzer
- **Módulos opcionales independientes:**
    - WiFi con auto-reconexión y eventos
    - HTTP (GET/POST) con callback
    - ThingSpeak (envío automático a la nube)
    - Almacenamiento de variables en memoria no volátil

---

## Ejemplo básico

```cpp
#include <TortuBot.h>

TortuBot tortu;

void setup() {
    Serial.begin(115200);
    tortu.init();
}

void loop() {
    tortu.moveForward(200);
    delay(1000);
    tortu.turnLeft(200);
    delay(500);
    tortu.stop();
    delay(1000);

    // Lectura de encoders
    Serial.print("Encoder1: ");
    Serial.println(tortu.readEncoder1());
}
```
## Autor

- [César Fuenzalida Vergara](https://www.cefuve.com/)
