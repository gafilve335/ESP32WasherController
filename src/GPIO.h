#include <BlynkGOv3.h>
#include <BlynkGO_Buzzer.h>
#include <CONFIG.h>
#include "MELODY.h"
#ifndef GPIO_H
#define GPIO_H

extern uint8_t RELAY_1;  
extern uint8_t RELAY_2;   
extern uint8_t RELAY_3;  
extern uint8_t RELAY_4;  
extern uint8_t LDR;      
extern Buzzer buzzer;

namespace PINMODE {
    void SET_GPIO();
}

#endif 
