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
