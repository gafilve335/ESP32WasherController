#include "GPIO.h"
uint8_t RELAY_1 = 4;   // GPIO4
uint8_t RELAY_2 = 0;   // GPIO0
uint8_t RELAY_3 = 5;   // GPIO5
uint8_t RELAY_4 = 25;  // GPIO25
uint8_t LDR = 35;      // GPIO35
Buzzer buzzer(2);


namespace PINMODE {

    void SET_GPIO() {
        pinMode(RELAY_1, OUTPUT); // RELAY1 SET OUTPUT
        pinMode(RELAY_2, OUTPUT); // RELAY2 SET OUTPUT
        pinMode(RELAY_3, OUTPUT); // RELAY3 SET OUTPUT      
        pinMode(RELAY_4, OUTPUT); // RELAY4 SET OUTPUT
        pinMode(SPEAKER_PIN,OUTPUT);
        pinMode(LDR, INPUT);      // LDR SET INPUT 
      
    }
}
