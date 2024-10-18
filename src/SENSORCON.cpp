#include "SENSORCON.h"
EventGroupHandle_t xEventGroup;
QueueHandle_t sensorQueue;
int LDR_THRESHOLD;

namespace SENSORCONTROLLER {

    void createSensorQueueAndEvents() {

        sensorQueue = xQueueCreate(10, sizeof(uint16_t)); 
        if (sensorQueue == NULL) {
            DEBUG_PRINT("Failed to create the queue.");
        }
        
        xEventGroup = xEventGroupCreate();
        if (xEventGroup == NULL) {
            DEBUG_PRINT("Failed to create Event Group.");
        }
    }

    void LDRTask(void *parameter) {
        uint16_t ldrValue;
        DEBUG_PRINT("LDR TASK Created");
        while (true) {
            ldrValue = analogRead(LDR);                           
            if (xQueueSendToBack(sensorQueue, &ldrValue, portMAX_DELAY) != pdTRUE) {
                DEBUG_PRINT("Failed to send to queue");
            } 
            vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);                   
        }
    }
   
 void LUXCONTROLLER(void *parameter) {
    uint16_t receivedValue;                                          
    bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
    bool DebugState = MEMORY::getFlashMemState(DEBUG_KEY);     
    String ldr = MEMORY::getFlashMemString(LDR_THRESHOLD_KEY);
    LDR_THRESHOLD = ldr.toInt();  
    DEBUG_PRINT("LUX CONTROLLER Created");
    
    while (true) {
        if (xQueueReceive(sensorQueue, &receivedValue, portMAX_DELAY) == pdTRUE) {

            Serial.println(receivedValue);
            char output[40];
            snprintf(output, sizeof(output), "LIGHT %d", receivedValue);
            if (DebugState){Serial.println(output);}
            xEventGroupClearBits(xEventGroup, BIT_PROCESS_IDLE | BIT_PROCESS_WASHER);
            if (receivedValue > LDR_THRESHOLD) {
                xEventGroupSetBits(xEventGroup, BIT_PROCESS_WASHER);
                MQTTBROKER::publishStatus("WasherStatus", "ON");
            } else {
                xEventGroupSetBits(xEventGroup, BIT_PROCESS_IDLE);
                MQTTBROKER::publishStatus("WasherStatus", "OFF");
            }
            

        } else {
            DEBUG_PRINT("Failed to receive from queue");
            xEventGroupSetBits(xEventGroup, BIT_ERROR_OCCURRED);
        }
        vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
    }
}

}