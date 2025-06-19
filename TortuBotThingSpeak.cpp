#include "TortuBotThingSpeak.h"

void TortuBotThingSpeak::config(const String& channel, const String& apiKey) {
    _channel = channel;
    _apiKey = apiKey;
}

bool TortuBotThingSpeak::sendField(uint8_t field, int value) {
    if (WiFi.status() != WL_CONNECTED) return false;
    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" + _apiKey + "&field" + String(field) + "=" + String(value);
    http.begin(url);
    int httpCode = http.GET();
    String payload = http.getString();
    http.end();

    if (_callback) _callback(payload);

    return (httpCode == 200 && payload.toInt() > 0);
}

bool TortuBotThingSpeak::sendFields(const int* values, uint8_t nFields) {
    if (WiFi.status() != WL_CONNECTED) return false;
    HTTPClient http;
    String url = "http://api.thingspeak.com/update?api_key=" + _apiKey;
    for (uint8_t i = 0; i < nFields; i++) {
        url += "&field" + String(i + 1) + "=" + String(values[i]);
    }
    http.begin(url);
    int httpCode = http.GET();
    String payload = http.getString();
    http.end();

    if (_callback) _callback(payload);

    return (httpCode == 200 && payload.toInt() > 0);
}

void TortuBotThingSpeak::setInterval(unsigned long ms) {
    _interval = ms;
}

void TortuBotThingSpeak::autoReconnect(bool on) {
    _autoReconnect = on;
}

void TortuBotThingSpeak::onEvent(std::function<void(String)> callback) {
    _callback = callback;
}

static std::function<void()> _sendCallback = nullptr;

void TortuBotThingSpeak::setSendCallback(std::function<void()> callback) {
    _sendCallback = callback;
}

void TortuBotThingSpeak::loop() {
    unsigned long now = millis();
    if (_interval > 0 && (now - _lastSend > _interval)) {
        // Si hay callback, se ejecuta para que el usuario mande sus datos
        if (_sendCallback) {
            _sendCallback();
        }
        _lastSend = now;
    }
}