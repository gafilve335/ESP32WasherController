#ifndef DATAJSON_H
#define DATAJSON_H

#include <ArduinoJson.h>
#include "CONFIG.h"

class StatusDataModel {
public:
    // Methods for JSON serialization and deserialization
    void fromJson(const String& jsonString);    // Convert JSON string to Data Model
    String toJson() const;                      // Convert Data Model to JSON string

    // Getter methods
    String getType() const { return type; }
    String getValue() const { return value; }

    // Setter methods
    void setType(const String& newType) { type = newType; }
    void setValue(const String& newValue) { value = newValue; }

private:
    String type;
    String value;
};

class VerifyDataModel {
public:
    // Methods for JSON serialization and deserialization
    void fromJson(const String& jsonString);    // Convert JSON string to Data Model
    String toJson() const;                      // Convert Data Model to JSON string

    // Getter methods
    String getType() const { return type; }
    String getValue() const { return value; }

    // Setter methods
    void setType(const String& newType) { type = newType; }
    void setValue(const String& newValue) { value = newValue; }

private:
    String type;
    String value;
};

#endif 
