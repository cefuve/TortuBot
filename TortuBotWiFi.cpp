#include "TortuBotWiFi.h"

bool TortuBotWiFi::connect(const String& ssid, const String& pass, int retries) {
    _ssid = ssid;
    _pass = pass;
    _retries = retries;

    WiFi.mode(WIFI_STA);
    WiFi.begin(_ssid.c_str(), _pass.c_str());

    int attempts = 0;
    while (WiFi.status() != WL_CONNECTED && attempts < _retries) {
        delay(1000);
        attempts++;
    }
    if (WiFi.status() == WL_CONNECTED) {
        if (_callback) _callback("connected");
        return true;
    } else {
        if (_callback) _callback("failed");
        return false;
    }
}

bool TortuBotWiFi::isConnected() {
    return WiFi.status() == WL_CONNECTED;
}

String TortuBotWiFi::getIP() {
    return WiFi.localIP().toString();
}

void TortuBotWiFi::autoReconnect(bool on) {
    _autoReconnect = on;
}

void TortuBotWiFi::setInterval(unsigned long ms) {
    _interval = ms;
}

void TortuBotWiFi::onEvent(std::function<void(String)> callback) {
    _callback = callback;
}

void TortuBotWiFi::loop() {
    if (_autoReconnect && !isConnected()) {
        unsigned long now = millis();
        // Usa el intervalo configurado
        if (now - _lastConnectAttempt > _interval) {
            connect(_ssid, _pass, _retries);
            _lastConnectAttempt = now;
        }
    }
}
