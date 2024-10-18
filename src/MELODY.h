#ifndef MELODY_H
#define MELODY_H
#include<BlynkGOv3.h>
#include "GPIO.h"

extern uint8_t SPEAKER_PIN;

namespace MELODY {
   void playMelody();
} 

#endif