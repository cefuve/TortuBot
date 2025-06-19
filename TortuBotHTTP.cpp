#include "TortuBotHTTP.h"
#include <WiFi.h>

void TortuBotHTTP::onEvent(std::function<void(String)> callback) {
    _callback = callback;
}

String TortuBotHTTP::get(const String& url) {
    if (WiFi.status() != WL_CONNECTED) return "";

    HTTPClient http;
    http.begin(url);
    int httpCode = http.GET();
    String payload = "";
    if (httpCode > 0) {
        payload = http.getString();
    }
    http.end();

    if (_callback) _callback(payload);
    return payload;
}

String TortuBotHTTP::post(const String& url, const String& payload, const String& contentType) {
    if (WiFi.status() != WL_CONNECTED) return "";

    HTTPClient http;
    http.begin(url);
    int httpCode = http.POST(payload);
    String response = "";
    if (httpCode > 0) {
        response = http.getString();
    }
    http.end();

    if (_callback) _callback(response);
    return response;
}