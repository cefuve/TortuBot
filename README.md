# TortuBot

**Librería modular para robótica educativa basada en ESP32**  
Autor: César Fuenzalida Vergara ([cefuve.com](https://cefuve.com))

---

## Descripción

TortuBot es una librería diseñada para facilitar la programación y el control de robots móviles basados en ESP32 en entornos educativos. Permite controlar motores, sensores, encoder, buzzer y LED, además de incluir módulos opcionales para conexión WiFi, ThingSpeak, HTTP y almacenamiento local.

---

## Características principales

- Control de motores DC (con velocidad y dirección)
- Lectura de encoders (contadores, dirección, reset)
- Sensores infrarrojos y expansión de entradas analógicas
- Manejo de LED, buzzer, y salidas auxiliares
- Módulos independientes para:
  - WiFi (con auto-reconexión)
  - HTTP GET/POST
  - ThingSpeak (envío de datos automático)
  - Almacenamiento no volátil de configuraciones

---

## Instalación

1. **Descarga** este repositorio como ZIP o clónalo con Git:
    ```
    git clone https://github.com/cefuve/TortuBot.git
    ```
2. **Copia la carpeta** `TortuBot` dentro de tu carpeta de librerías de Arduino (`~/Arduino/libraries/`).
3. **Reinicia** el IDE de Arduino.

> **Nota:** Asegúrate de tener seleccionada una placa basada en ESP32 y el core actualizado.  
> Para proyectos con control de motores, conecta los drivers y encoders según la documentación.

---

## Uso básico

### Ejemplo: Control de hardware principal

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
