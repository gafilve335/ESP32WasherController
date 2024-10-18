#include "MODESELECTOR.h"

// Namespace สำหรับการสร้าง Task ตามโหมดที่เลือก
namespace SELECTOR {

    void createTaskForMode() {
        unsigned char modeCount = 0; // ตัวแปรนับจำนวนโหมดที่ถูกเลือก
        unsigned char selectedMode = 0; // ตัวแปรเก็บโหมดที่ถูกเลือก

        // ตรวจสอบค่าใน Flash Memory และเลือกโหมด
        if (MEMORY::getFlashMemState(DELAY_1KEY)) {
            modeCount++; 
            selectedMode = 1; 
        }

        if (MEMORY::getFlashMemState(DELAY_2KEY)) {
            modeCount++;
            selectedMode = 2;
        }

        if (MEMORY::getFlashMemState(DELAY_3KEY)) {
            modeCount++;
            selectedMode = 3;
        }

        if (MEMORY::getFlashMemState(DELAY_4KEY)) {
            modeCount++;
            selectedMode = 4;
        }

        // ตรวจสอบว่ามีโหมดที่ถูกเลือกเพียงโหมดเดียว
        if (modeCount == 1) {
            // สร้าง Task ใหม่ตามโหมดที่เลือก
            switch (selectedMode) {
                case 1:
                    xTaskCreate(CONTROLLER::ControllerMode1, "ControllerMode1", 2048, NULL, 1, NULL);
                    DEBUG_PRINT("Task for ControllerMode1 created.");
                    break;
                case 2:
                    xTaskCreate(CONTROLLER::ControllerMode2, "ControllerMode2", 2048, NULL, 1, NULL);
                    DEBUG_PRINT("Task for ControllerMode2 created.");
                    break;
                case 3:
                    xTaskCreate(CONTROLLER::ControllerMode3, "ControllerMode3", 2048, NULL, 1, NULL);
                    DEBUG_PRINT("Task for ControllerMode3 created.");
                    break;
                case 4:
                    xTaskCreate(CONTROLLER::ControllerMode4, "ControllerMode4", 2048, NULL, 1, NULL);
                    DEBUG_PRINT("Task for ControllerMode4 created.");
                    break;
                default:
                    DEBUG_PRINT("Invalid mode selected.");
                    break;
            }
        } else {
            DEBUG_PRINT("ERROR: More than one mode selected or no mode selected.");
        }
    }

}
