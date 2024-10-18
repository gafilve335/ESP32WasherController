#ifndef HTTP_CON_H
#define HTTP_CON_H
#include <BlynkGOv3.h>
#include <ArduinoJson.h>
#include <ESPAsyncWebServer.h>
#include <ESPmDNS.h>
#include "MEMORY.h"
#include "MQTTBROKER.h"
#include "GRAPHIC.h"

namespace AsyncWEBSERVER {
  void StartMutiCast();
  void begin();
  void end();
}

#endif