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

#ifndef TORTUBOTSTORAGE_H
#define TORTUBOTSTORAGE_H

#include <Arduino.h>
#include <Preferences.h>

/**
 * @class TortuBotStorage
 * @brief Permite almacenar y recuperar configuraciones (clave-valor) en memoria no volátil.
 */
class TortuBotStorage {
private:
    Preferences _prefs;
    
public:
    /**
     * @brief Constructor vacío. Inicializa el módulo Hardware.
     */
    TortuBotStorage() {}

    /**
     * @brief Inicializa el espacio de almacenamiento.
     * @param ns Espacio de nombres (por defecto: "tortubot").
     */
    void begin(const String& ns = "tortubot");

    /**
     * @brief Guarda un valor asociado a una clave.
     * @param key Clave.
     * @param value Valor a almacenar.
     */
    void saveConfig(const String& key, const String& value);

    /**
     * @brief Recupera el valor asociado a una clave.
     * @param key Clave.
     * @return Valor almacenado o cadena vacía si la clave no existe.
     */
    String loadConfig(const String& key);

    /**
     * @brief Elimina todas las configuraciones almacenadas.
     */
    void clearConfig();
};

#endif
