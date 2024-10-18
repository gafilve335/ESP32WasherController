#include "CONTROLLER.h"

namespace CONTROLLER {

    // Function to control a relay
    void controlRelay(int relayPin, int times) {
        for (int i = 0; i < times; i++) {
            digitalWrite(relayPin, HIGH);
            vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
            digitalWrite(relayPin, LOW);
            vTaskDelay(DELAY_TIME_MS / portTICK_PERIOD_MS);
        }
    }

    void ControllerMode1(void *parameter) {
        controlRelay(RELAY_1, 1);
        controlRelay(RELAY_2, 1);
        vTaskDelete(NULL); 
    }

    void ControllerMode2(void *parameter) {
        controlRelay(RELAY_1, 1);
        controlRelay(RELAY_3, 1);
        controlRelay(RELAY_2, 1);
        vTaskDelete(NULL); 
    }

    void ControllerMode3(void *parameter) {
        controlRelay(RELAY_1, 1);
        controlRelay(RELAY_3, 3);
        controlRelay(RELAY_4, 1);
        controlRelay(RELAY_2, 1);
        vTaskDelete(NULL); 
    }

    void ControllerMode4(void *parameter) {
        controlRelay(RELAY_1, 1);
        controlRelay(RELAY_3, 4);
        controlRelay(RELAY_4, 2);
        controlRelay(RELAY_2, 1);
        vTaskDelete(NULL); 
    }
}
