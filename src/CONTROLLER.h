#ifndef MACHINECONTROL_H
#define MACHINECONTROL_H

#include <BlynkGOv3.h>
#include <GPIO.h>
#include <MODESELECTOR.h>
#include "CONFIG.h"

    namespace CONTROLLER {
        
        void ControllerMode1(void *parameter);
        void ControllerMode2(void *parameter);
        void ControllerMode3(void *parameter);
        void ControllerMode4(void *parameter);    
    } 
    
#endif 