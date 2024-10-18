#include "MEMORY.h"

//---KEY FlashMemory
String DELAY_1KEY = "DELAY1_STATE"; //คีย์สเตจดีเลย์ หมายเลข 1
String DELAY_2KEY = "DELAY2_STATE"; //คีย์สเตจดีเลย์ หมายเลข 2
String DELAY_3KEY = "DELAY3_STATE"; //คีย์สเตจดีเลย์ หมายเลข 3
String DELAY_4KEY = "DELAY4_STATE"; //คีย์สเตจดีเลย์ หมายเลข 4

String BUZZER_KEY = "BUZZER_STATE"; //คีย์สเตจบัสเซอร์
String LDR_KEY = "LDR_STATE"; //คีย์สเตจเซ็นเซอร์รับค่าแสง
String DEBUG_KEY = "DEBUG_STATE"; //คีย์สเตจดีบัค
String PRICE_KEY = "PRODUCT_PRICE";//คีย์เก็บราคาสินค้า 
String ENCODE_KEY = "ENCODE";
String MODE_KEY = "MODE_STATE";
String LDR_THRESHOLD_KEY = "LDR_THRESHOLD";

String MQTT_SERVER_KEY = "MQTT_SERVER"; //คีย์เซิฟเวอร์
String MQTT_TOPIC_KEY = "MQTT_TOPIC"; //คีย์ทอปพิค
String MQTT_PORT_KEY = "MQTT_PORT"; //คีย์พอท

String TIMER_DATA_KEY = "TIMER_DATA"; //คีย์ระยะเวลาการดึงข้อมูล :: ทุกๆ กี่วินาที



namespace MEMORY {
        
    // ฟังชันดึงข้อมูลจาก FlashMem โดยคืนค่าออกมาเป็นบลูลีน
    bool getFlashMemState(String key) {
        if (BlynkGO.flashMem_exists(key)) {
            return (bool) BlynkGO.flashMem_Int(key);
        }
        DEBUG_PRINT("Error: Key " + key + " does not exist in FlashMem.");
        return false;
    }

    // ฟังชันบันทึกข้อมูลลง Flashmem รับค่าเป็นบลูลีน
    void setFlashMemState(String key, bool state) {
        BlynkGO.flashMem(key, state);
    }

    //--------------------------------------------------------------------------------------------------------------


    // ฟังก์ชันดึงข้อมูลจาก FlashMem โดยคืนค่าเป็นสตริง
    String getFlashMemString(String key) {
        if (BlynkGO.flashMem_exists(key)) {
            return String(BlynkGO.flashMem_String(key));
        }
        DEBUG_PRINT("Error: Key " + key + " does not exist in FlashMem.");
        return "";
    }

    // ฟังชันบันทึกข้อมูลลง FlashMem รับค่าเป็นสตริง
    void setFlashMemString(String key, String value) {
        BlynkGO.flashMem(key, value);
    }

}