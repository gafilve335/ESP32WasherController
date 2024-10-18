#ifndef MQTTBROKER_H
#define MQTTBROKER_H

#include <ArduinoJson.h>
#include <BlynkGOv3.h>
#include "Graphic.h"
#include "MEMORY.h"
#include "GPIO.h"
#include "MODESELECTOR.h"
#include "CONFIG.h"
#include "DataJson.h"
#include "MQTTBROKER.h"
#include "MELODY.h"

namespace MQTTBROKER {
  void MqttConnected();
  void publishStatus(const String& type, const String& value);
  void reMqttMemory();
}

#endif
