#include "DataJson.h"


void StatusDataModel::fromJson(const String& jsonString) {
    StaticJsonDocument<1024> doc;
    DeserializationError error = deserializeJson(doc, jsonString);

    if (!error) {
        setType(doc["type"].as<String>());
        setValue(doc["value"].as<String>());
    } else {
        DEBUG_PRINT(F("deserializeJson() failed: "));
        DEBUG_PRINT(error.f_str());
    }
}

void VerifyDataModel::fromJson(const String& jsonString) {
    StaticJsonDocument<512> doc;
    DeserializationError error = deserializeJson(doc, jsonString);

    if (!error) {
        setType(doc["type"].as<String>());
        setValue(doc["value"].as<String>());
    } else {
        DEBUG_PRINT(F("deserializeJson() failed: "));
        DEBUG_PRINT(error.f_str());
    }
}

String StatusDataModel::toJson() const {
    
    StaticJsonDocument<1024> doc;
    doc["type"] = getType();
    doc["value"] = getValue();

    String jsonString;
    serializeJson(doc, jsonString);
    return jsonString;
}

String VerifyDataModel::toJson() const {
    
    StaticJsonDocument<1024> doc;
    doc["type"] = getType();
    doc["value"] = getValue();

    String jsonString;
    serializeJson(doc, jsonString);
    return jsonString;
}