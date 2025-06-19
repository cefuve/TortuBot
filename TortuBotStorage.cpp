#include "TortuBotStorage.h"

void TortuBotStorage::begin(const String& ns) {
    _prefs.begin(ns.c_str(), false); // false = RW
}

void TortuBotStorage::saveConfig(const String& key, const String& value) {
    _prefs.putString(key.c_str(), value);
}

String TortuBotStorage::loadConfig(const String& key) {
    return _prefs.getString(key.c_str(), "");
}

void TortuBotStorage::clearConfig() {
    _prefs.clear();
}
