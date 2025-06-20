/*
  TortuBot.h - Main include file for pin definitions
  Copyright (c) 2025 CEAR INACAP.

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <https://www.gnu.org/licenses/>.
  License: GPL 3.0.

  Author: César Fuenzalida Vergara @cefuve
*/

#ifndef TORTUBOTTHINGSPEAK_H
#define TORTUBOTTHINGSPEAK_H

#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>

#include <functional>

/**
 * @class TortuBotThingSpeak
 * @brief Permite enviar datos a ThingSpeak de forma sencilla y automática.
 */
class TortuBotThingSpeak {
private:
    String _channel;
    String _apiKey;
    std::function<void(String)> _callback = nullptr;
    unsigned long _interval = 0;
    bool _autoReconnect = false;
    unsigned long _lastSend = 0;

public:
    /**
     * @brief Constructor vacío. Inicializa el módulo Hardware.
     */
    TortuBotThingSpeak() {}

    /**
     * @brief Configura el canal y la API Key de ThingSpeak.
     * @param channel Número o ID del canal.
     * @param apiKey API Key de escritura de ThingSpeak.
     */
    void config(const String& channel, const String& apiKey);

    /**
     * @brief Envía un valor a un campo específico de ThingSpeak.
     * @param field Número de campo (1-8).
     * @param value Valor a enviar.
     * @return true si el envío fue exitoso.
     */
    bool sendField(uint8_t field, int value);

    /**
     * @brief Envía múltiples campos en una sola petición a ThingSpeak.
     * @param values Array de valores a enviar.
     * @param nFields Número de campos a enviar (hasta 8).
     * @return true si el envío fue exitoso.
     */
    bool sendFields(const int* values, uint8_t nFields);

    /**
     * @brief Define el intervalo (en milisegundos) entre envíos automáticos.
     * @param ms Intervalo en milisegundos.
     */
    void setInterval(unsigned long ms);

    /**
     * @brief Activa o desactiva la reconexión automática de ThingSpeak.
     * @param on true para activar, false para desactivar.
     */
    void autoReconnect(bool on);

    /**
     * @brief Asigna una función callback para eventos de respuesta de ThingSpeak.
     * @param callback Función a ejecutar, recibe el String de respuesta.
     */
    void onEvent(std::function<void(String)> callback);

    /**
     * @brief Asigna la función callback que se llamará en cada envío automático.
     * @param callback Función lambda que contiene el envío de datos.
     */
    void setSendCallback(std::function<void()> callback);

    /**
     * @brief Debe llamarse en el loop principal para gestión interna y envíos automáticos.
     */
    void loop();
};

#endif
