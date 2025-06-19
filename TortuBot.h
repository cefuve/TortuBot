/**
 * @mainpage TortuBot Arduino Library
 * @author cefuve
 * @version 2.0
 * @date 2025
 * 
 * @section intro_sec Introducción
 * Biblioteca modular para el control y programación didáctica del robot TortuBot (INACAP).
 * Permite el manejo de sensores, actuadores, WiFi, ThingSpeak, HTTP y almacenamiento local.
 * 
 * @section modules_sec Módulos principales
 * - TortuBotHardware
 * - TortuBotWiFi
 * - TortuBotThingSpeak
 * - TortuBotHTTP
 * - TortuBotStorage
 */


#ifndef TORTUBOT_H
#define TORTUBOT_H

#include <Arduino.h>

class TortuBot {
private:
    int lastState1A = 0;
    int lastState2A = 0;

public:
    volatile long encoder1_count = 0;
    volatile long encoder2_count = 0;

    /**
     * @brief Constructor vacío. Inicializa el módulo Hardware.
     */
    TortuBot() {}

    /**
     * @brief Inicializa los pines y periféricos del robot.
     */
    void begin();

    /**
     * @brief Lee el sensor infrarrojo izquierdo.
     * @return Valor analógico leído del sensor izquierdo.
     */
    int readLeftIR();

    /**
     * @brief Lee el sensor infrarrojo central.
     * @return Valor analógico leído del sensor central.
     */
    int readCenterIR();

    /**
     * @brief Lee el sensor infrarrojo derecho.
     * @return Valor analógico leído del sensor derecho.
     */
    int readRightIR();

    /**
     * @brief Enciende o apaga el LED integrado.
     * @param on true para encender, false para apagar.
     */
    void setLED(bool on);

    /**
     * @brief Hace sonar el buzzer integrado por un tiempo en milisegundos.
     * @param ms Duración del tono en milisegundos.
     */
    void beep(int ms = 100);

    /**
     * @brief Lee un pin externo de expansión como entrada analógica.
     * @param pin Número de pin a leer.
     * @return Valor analógico leído.
     */
    int readExt(int pin);

    /**
     * @brief Hace parpadear el LED integrado una cantidad de veces.
     * @param times Número de parpadeos.
     * @param msON Tiempo encendido en milisegundos.
     * @param msOFF Tiempo apagado en milisegundos.
     */
    void blinkLED(int times, int msON, int msOFF);

    /**
     * @brief Emite un tono en el buzzer.
     * @param freq Frecuencia en Hertz del tono.
     * @param duration Duración del tono en milisegundos.
     */
    void playTone(int freq, int duration);

    /**
     * @brief Lee todos los sensores infrarrojos y los entrega en un array.
     * @param values Array de 3 enteros donde se almacenan los valores: [izquierdo, central, derecho].
     */
    void readAllIR(int* values);

    /**
     * @brief Hace avanzar el robot con ambos motores hacia adelante.
     * @param speed Velocidad PWM (0 a 255).
     */
    void moveForward(int speed = 255);

    /**
     * @brief Hace retroceder el robot con ambos motores hacia atrás.
     * @param speed Velocidad PWM (0 a 255).
     */
    void moveBackward(int speed = 255);

    /**
     * @brief Gira el robot hacia la izquierda.
     * @param speed Velocidad PWM de giro (0 a 255).
     */
    void turnLeft(int speed = 255);

    /**
     * @brief Gira el robot hacia la derecha.
     * @param speed Velocidad PWM de giro (0 a 255).
     */
    void turnRight(int speed = 255);

    /**
     * @brief Detiene ambos motores del robot.
     */
    void stop();

    /**
     * @brief Controla el motor 1 (lado izquierdo) estableciendo velocidad y dirección.
     * @param speed Velocidad PWM (0 a 255).
     * @param forward true para rotar hacia adelante, false para rotar hacia atrás.
     */
    void setM1(int speed, bool forward);

    /**
     * @brief Controla el motor 2 (lado derecho) estableciendo velocidad y dirección.
     * @param speed Velocidad PWM (0 a 255).
     * @param forward true para rotar hacia adelante, false para rotar hacia atrás.
     */
    void setM2(int speed, bool forward);

    /**
     * @brief Detiene el motor 1 (lado izquierdo).
     */
    void stopM1();

    /**
     * @brief Detiene el motor 2 (lado derecho).
     */
    void stopM2();

    /**
     * @brief Inicializa los pines y variables de los encoders y configura las interrupciones.
     */
    void initEncoders();

    /**
     * @brief Lee el contador acumulado del encoder del motor 1.
     * @return Número de pulsos contados por el encoder 1.
     */
    long readEncoder1();

    /**
     * @brief Lee el contador acumulado del encoder del motor 2.
     * @return Número de pulsos contados por el encoder 2.
     */
    long readEncoder2();

    /**
     * @brief Resetea a cero ambos contadores de los encoders.
     */
    void resetEncoders();
};

#endif
