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

#ifndef TORTUBOTWIFI_H
#define TORTUBOTWIFI_H

#include <Arduino.h>
#include <WiFi.h>
#include <functional>

/**
 * @class TortuBotWiFi
 * @brief Maneja la conexión WiFi y la reconexión automática para el TortuBot.
 */
class TortuBotWiFi {
private:
    String _ssid;
    String _pass;
    int _retries;
    std::function<void(String)> _callback;
    bool _autoReconnect = false;
    unsigned long _interval = 5000;
    unsigned long _lastConnectAttempt = 0;

public:
    /**
     * @brief Constructor vacío. Inicializa el módulo WiFi.
     */
    TortuBotWiFi() {}
    
    /**
     * @brief Conecta a una red WiFi.
     * @param ssid Nombre de la red WiFi.
     * @param pass Contraseña de la red WiFi.
     * @param retries Número máximo de intentos de conexión.
     * @return true si se conecta correctamente, false si falla.
     */
    bool connect(const String& ssid, const String& pass, int retries = 3);

    /**
     * @brief Verifica si el módulo está conectado a WiFi.
     * @return true si está conectado, false si no.
     */
    bool isConnected();

    /**
     * @brief Obtiene la dirección IP asignada por la red WiFi.
     * @return IP local como String.
     */
    String getIP();

    /**
     * @brief Activa o desactiva la reconexión automática a WiFi.
     * @param on true para activar, false para desactivar.
     */
    void autoReconnect(bool on);

    /**
     * @brief Define el intervalo (en milisegundos) entre intentos de reconexión.
     * @param ms Intervalo en milisegundos.
     */
    void setInterval(unsigned long ms);

    /**
     * @brief Asigna una función callback para eventos (por ejemplo, cambios de estado).
     * @param callback Función a ejecutar, recibe un String con el evento.
     */
    void onEvent(std::function<void(String)> callback);

    /**
     * @brief Debe llamarse en el loop principal para gestión interna del módulo.
     */
    void loop();
};


#endif
