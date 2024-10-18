#ifndef SENSORCON_H
#define SENSORCON_H
#include <BlynkGOv3.h>
#include "GPIO.h"
#include "MEMORY.h"
#include "DataJson.h"
#include "MQTTBROKER.h"
#include "CONFIG.h"

#ifdef ENABLE_LDR_SENSOR  
extern QueueHandle_t sensorQueue;
extern EventGroupHandle_t xEventGroup;
extern int LDR_THRESHOLD;

namespace SENSORCONTROLLER {

    void LDRTask(void *parameter);
    void createSensorQueueAndEvents();
    void LUXCONTROLLER(void *parameter);
   
}

#endif
#endif 
