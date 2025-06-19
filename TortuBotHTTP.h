#ifndef TORTUBOTHTTP_H
#define TORTUBOTHTTP_H

#include <Arduino.h>
#include <HTTPClient.h>
#include <functional>

/**
 * @class TortuBotHTTP
 * @brief Cliente HTTP simple para GET y POST.
 */
class TortuBotHTTP {
private:
    std::function<void(String)> _callback = nullptr;

public:
    /**
     * @brief Constructor vacío. Inicializa el módulo Hardware.
     */
    TortuBotHTTP() {}

    /**
     * @brief Realiza una petición HTTP GET a la URL especificada.
     * @param url Dirección del recurso.
     * @return Respuesta del servidor como String.
     */
    String get(const String& url);

    /**
     * @brief Realiza una petición HTTP POST a la URL especificada.
     * @param url Dirección del recurso.
     * @param data Cuerpo de la petición.
     * @param contentType Tipo de contenido (por defecto: "application/x-www-form-urlencoded").
     * @return Respuesta del servidor como String.
     */
    String post(const String& url, const String& data, const String& contentType = "application/x-www-form-urlencoded");

    /**
     * @brief Asigna una función callback que se ejecuta después de cada petición HTTP.
     * @param callback Función que recibe el String con la respuesta del servidor.
     */
    void onEvent(std::function<void(String)> callback);
};

#endif
