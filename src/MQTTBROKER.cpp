#include "MQTTBROKER.h"

namespace MQTTBROKER {

    // Function Declarations
    void MqttConnected();
    void handleTurnOnMachine(); 
    void handleTurnOffMachine(); 
    void handleSetPrice(const char* value);                                          
    void ProcessMessage(String topic, String message);     
    void resetConnection();
    void publishStatus(const String& type, const String& value);
    void reMqttMemory();
    void setupMqttConnection();
    void setMqttConfig(const String& server, const String& topic, const String& port);
    void hardwareConFig(const String& mode, const String& buzzer, const String& light,const String& encode);

    String MQTT_SERVER;
    String MQTT_TOPIC;
    String MQTT_PORT;

    String MODE;
    String BUZZER;
    String LIGHT;
    String ENCODE;

    void reMqttMemory() {
        // Read MQTT configuration from memory
        MQTT_SERVER = MEMORY::getFlashMemString(MQTT_SERVER_KEY);
        MQTT_TOPIC  = MEMORY::getFlashMemString(MQTT_TOPIC_KEY);
        MQTT_PORT   = MEMORY::getFlashMemString(MQTT_PORT_KEY); 

        setupMqttConnection();
    }

    void setupMqttConnection() {
        // Set up MQTT server configuration and callbacks
        MQTT.setServer(MQTT_SERVER.c_str(), atoi(MQTT_PORT.c_str()));
        MQTT.subscribe(MQTT_TOPIC.c_str());
        MQTT.onMessage(ProcessMessage);
    }

    void MqttConnected() {
        reMqttMemory();

        if (MQTT_SERVER.isEmpty() || MQTT_TOPIC.isEmpty() || MQTT_PORT.isEmpty()) {
            if (MEMORY::getFlashMemState(DEBUG_KEY)) {
                DEBUG_PRINT("MQTT settings are not properly configured.");
            }
            return;
        }

        setupMqttConnection();

        if (MEMORY::getFlashMemState(DEBUG_KEY)) {
            DEBUG_PRINT("MQTT connected and subscribed to topic.");
        }
    }

    void publishStatus(const String& type, const String& value) {
        // Create and publish a status message in JSON format
        StatusDataModel statusData;
        statusData.setType(type);
        statusData.setValue(value);

        String jsonString = statusData.toJson();
        MQTT.publish(MQTT_TOPIC.c_str(), jsonString.c_str());

        // if (MEMORY::getFlashMemState(DEBUG_KEY)) {
        //     DEBUG_PRINT("Published MQTT message: ");
        //     DEBUG_PRINT(jsonString);
        // }
    }

    void ProcessMessage(String topic, String message) {
    DynamicJsonDocument doc(1024);
    DeserializationError error = deserializeJson(doc, message);

    if (error) {
        DEBUG_PRINT(F("deserializeJson() failed: "));
        DEBUG_PRINT(error.f_str());
        return;
    }

    // ตรวจสอบว่ามีคีย์ "type" และ "value" อยู่ใน JSON หรือไม่
    if (!doc.containsKey("type") || !doc.containsKey("value")) {
        DEBUG_PRINT(F("Invalid JSON format: Missing 'type' or 'value'"));
        return;
    }

    const char* type = doc["type"];
    const char* value = doc["value"];

    // ตรวจสอบค่าของ "type" และ "value" 
        if (strcmp(type, "ESP32CMD") == 0) {
            if (strcmp(value, "TURN_ON_MACHINE") == 0) {
                handleTurnOnMachine();
            } else if (strcmp(value, "TURN_OFF_MACHINE") == 0) {
                handleTurnOffMachine();
            } else if (strcmp(value, "ESP32_RESTART") == 0) {
                ESP.restart();
            } else if (strstr(value, "SET_PRICE_") == value) {
                handleSetPrice(value);
            } else if (strcmp(value, "SET_MQTT_CONFIG") == 0) {
                // ตรวจสอบว่า "server", "topic", และ "port" มีอยู่ใน JSON หรือไม่
                if (!doc.containsKey("server") || !doc.containsKey("topic") || !doc.containsKey("port")) {
                    DEBUG_PRINT(F("Invalid JSON format: Missing 'server', 'topic', or 'port'"));
                    return;
                }
                const char* server = doc["server"];
                const char* topic = doc["topic"];
                const char* port = doc["port"];
                setMqttConfig(server, topic, port);
            } else if (strcmp(value, "HARDWARE_CONFIG") == 0) {
                // ตรวจสอบว่า "mode", "buzzer", "light", และ "encode" มีอยู่ใน JSON หรือไม่
                if (!doc.containsKey("mode") || !doc.containsKey("buzzer") || !doc.containsKey("light") || !doc.containsKey("encode")) {
                    DEBUG_PRINT(F("Invalid JSON format: Missing 'mode', 'buzzer', 'light', or 'encode'"));
                    return;
                }
                const char* mode = doc["mode"];
                const char* buzzer = doc["buzzer"];
                const char* light = doc["light"];
                const char* encode = doc["encode"];
                hardwareConFig(mode, buzzer, light, encode);
            } else {
                DEBUG_PRINT(F("ESP32 CMD failed: The instruction set is incorrect."));
            }
        } else {
            //DEBUG_PRINT(F("Unknown 'type' in JSON"));
        }
    }


    void setMqttConfig(const String& server, const String& topic, const String& port) {
        
        if (server.isEmpty() || topic.isEmpty() || port.isEmpty() || atoi(port.c_str()) <= 0) {
            DEBUG_PRINT("Invalid MQTT configuration received.");
            return;
        }

        MQTT_SERVER = server;
        MQTT_TOPIC = topic;
        MQTT_PORT = port;

        // บันทึกการตั้งค่าใหม่ลงในหน่วยความจำ
        MEMORY::setFlashMemString(MQTT_SERVER_KEY, MQTT_SERVER);
        MEMORY::setFlashMemString(MQTT_TOPIC_KEY, MQTT_TOPIC);
        MEMORY::setFlashMemString(MQTT_PORT_KEY, MQTT_PORT);

        // ดึงค่าจากเมมโมรี่อีกครั้ง 
        reMqttMemory();

        ta_mqtt_setting_server.text(MEMORY::getFlashMemString(MQTT_SERVER_KEY));
        ta_mqtt_setting_topic.text(MEMORY::getFlashMemString(MQTT_TOPIC_KEY));
        ta_mqtt_setting_port.text(MEMORY::getFlashMemString(MQTT_PORT_KEY)); 

        // ตั้งค่า MQTT server ใหม่
        setupMqttConnection();

        if (MEMORY::getFlashMemState(DEBUG_KEY)) {
            DEBUG_PRINT("MQTT configuration updated:");
            DEBUG_PRINT("Server: " + MQTT_SERVER);
            DEBUG_PRINT("Topic: " + MQTT_TOPIC);
            DEBUG_PRINT("Port: " + MQTT_PORT);
        }

        rect_mqtt_config_notify.hidden(false);
        xTaskCreate([](void *parameter) {
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            rect_mqtt_config_notify.hidden(true);
            vTaskDelete(nullptr); 
        }, "MqttConfigTask", 1024, nullptr, 1, nullptr);
    }

    void handleTurnOnMachine() {
        reMqttMemory();

        VerifyDataModel varify;
        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
        
        if (BuzzerState) { 
        // buzzer.beep(2); 
        }
        SELECTOR::createTaskForMode();
        
        varify.setType("VERIFY");
        varify.setValue("SUCCESS");    
        
        String jsonString = varify.toJson();                  
        MQTT.publish(MQTT_TOPIC.c_str(), jsonString.c_str(), 2);
        DEBUG_PRINT(jsonString);

        thank_you.hidden(false);
        xTaskCreate([](void *parameter) {
            vTaskDelay(3000 / portTICK_PERIOD_MS);
            thank_you.hidden(true);
            payment.hidden(true);
            vTaskDelete(nullptr); 
        }, "ThankYouTask", 1024, nullptr, 1, nullptr);
        MELODY::playMelody();
    }

    void handleTurnOffMachine() {
        if (MEMORY::getFlashMemState(DEBUG_KEY)) {
            DEBUG_PRINT("Machine turned off.");
        }
    }

    void handleSetPrice(const char* value) {
        String priceStr = String(value).substring(10);
        MEMORY::setFlashMemString(PRICE_KEY, priceStr);
        lb_payment_price = priceStr;

        if (MEMORY::getFlashMemState(DEBUG_KEY)) {
            DEBUG_PRINT("Price set to: ");
            DEBUG_PRINT(priceStr);
        }
    }

    void hardwareConFig(const String& mode, const String& buzzer, const String& light,const String& encode) {
        
        MODE = mode;
        BUZZER = buzzer;
        LIGHT = light;
        ENCODE = encode;

        // SET QR CODE
        MEMORY::setFlashMemString(ENCODE_KEY, ENCODE);
        ta_avd_encode.text(MEMORY::getFlashMemString(ENCODE_KEY));

        // SET LDR SENSOR
        BlynkGO.flashMem(LDR_THRESHOLD_KEY, LIGHT);
        String lightStr = MEMORY::getFlashMemString(LDR_THRESHOLD_KEY);
        LDR_THRESHOLD = lightStr.toInt();
        ta_avd_ldr.text(MEMORY::getFlashMemString(LDR_THRESHOLD_KEY));
      
        // Set only one mode to "1" and others to "0"
        if(BUZZER == "true"){
          MEMORY::setFlashMemState(BUZZER_KEY,true);  
            btn_setting_buzzer.ON();
            btn_setting_buzzer.color(TFT_GREEN);
            btn_setting_buzzer.border(3, TFT_GREENBLYNK);

        }else if(BUZZER == "false"){
          MEMORY::setFlashMemState(BUZZER_KEY,false);  
            btn_setting_buzzer.OFF();
            btn_setting_buzzer.color(TFT_GRAY);
            btn_setting_buzzer.border(3, TFT_LIGHTGRAY);
        }

        if (MODE == "WasherMode.mode1") {
            MEMORY::setFlashMemState(DELAY_1KEY,true);
            MEMORY::setFlashMemState(DELAY_2KEY, false);
            MEMORY::setFlashMemState(DELAY_3KEY, false);
            MEMORY::setFlashMemState(DELAY_4KEY, false);

            btn_setting_mode1.ON();
            btn_setting_mode1.color(TFT_GREEN);
            btn_setting_mode1.border(3, TFT_GREENBLYNK);

            btn_setting_mode2.OFF();
            btn_setting_mode2.color(TFT_GRAY);
            btn_setting_mode2.border(3, TFT_LIGHTGRAY);

            btn_setting_mode3.OFF();
            btn_setting_mode3.color(TFT_GRAY);
            btn_setting_mode3.border(3, TFT_LIGHTGRAY);

            btn_setting_mode4.OFF();
            btn_setting_mode4.color(TFT_GRAY);
            btn_setting_mode4.border(3, TFT_LIGHTGRAY);

        } else if (MODE == "WasherMode.mode2") {
            MEMORY::setFlashMemState(DELAY_1KEY, false);
            MEMORY::setFlashMemState(DELAY_2KEY, true);
            MEMORY::setFlashMemState(DELAY_3KEY, false);
            MEMORY::setFlashMemState(DELAY_4KEY, false);

            
            btn_setting_mode1.OFF();
            btn_setting_mode1.color(TFT_GRAY);
            btn_setting_mode1.border(3, TFT_LIGHTGRAY);

            btn_setting_mode2.ON();
            btn_setting_mode2.color(TFT_GREEN);
            btn_setting_mode2.border(3, TFT_GREENBLYNK);

            btn_setting_mode3.OFF();
            btn_setting_mode3.color(TFT_GRAY);
            btn_setting_mode3.border(3, TFT_LIGHTGRAY);

            btn_setting_mode4.OFF();
            btn_setting_mode4.color(TFT_GRAY);
            btn_setting_mode4.border(3, TFT_LIGHTGRAY);

        } else if (MODE == "WasherMode.mode3") {
            MEMORY::setFlashMemState(DELAY_1KEY, false);
            MEMORY::setFlashMemState(DELAY_2KEY, false);
            MEMORY::setFlashMemState(DELAY_3KEY, true);
            MEMORY::setFlashMemState(DELAY_4KEY, false);

            btn_setting_mode1.OFF();
            btn_setting_mode1.color(TFT_GRAY);
            btn_setting_mode1.border(3, TFT_LIGHTGRAY);

            btn_setting_mode2.OFF();
            btn_setting_mode2.color(TFT_GRAY);
            btn_setting_mode2.border(3, TFT_LIGHTGRAY);

            btn_setting_mode3.ON();
            btn_setting_mode3.color(TFT_GREEN);
            btn_setting_mode3.border(3, TFT_GREENBLYNK);

            btn_setting_mode4.OFF();
            btn_setting_mode4.color(TFT_GRAY);
            btn_setting_mode4.border(3, TFT_LIGHTGRAY);

        } else if (MODE == "WasherMode.mode4") {
            MEMORY::setFlashMemState(DELAY_1KEY, false);
            MEMORY::setFlashMemState(DELAY_2KEY, false);
            MEMORY::setFlashMemState(DELAY_3KEY, false);
            MEMORY::setFlashMemState(DELAY_4KEY, true);

            btn_setting_mode1.OFF();
            btn_setting_mode1.color(TFT_GRAY);
            btn_setting_mode1.border(3, TFT_LIGHTGRAY);

            btn_setting_mode2.OFF();
            btn_setting_mode2.color(TFT_GRAY);
            btn_setting_mode2.border(3, TFT_LIGHTGRAY);

            btn_setting_mode3.OFF();
            btn_setting_mode3.color(TFT_GRAY);
            btn_setting_mode3.border(3, TFT_LIGHTGRAY);
 
            btn_setting_mode4.ON();
            btn_setting_mode4.color(TFT_GREEN);
            btn_setting_mode4.border(3, TFT_GREENBLYNK);

        } else {
            DEBUG_PRINT("Invalid mode configuration received.");
        }
        if (MEMORY::getFlashMemState(DEBUG_KEY)) {
            DEBUG_PRINT("Hardware configuration updated:");
            DEBUG_PRINT("MODE: " + MODE);
            DEBUG_PRINT("BUZZER: " + BUZZER);
            DEBUG_PRINT("ENCODE after reading from memory: " + String(ENCODE));
            DEBUG_PRINT("LDR_THRESHOLD after reading from memory: " + String(LDR_THRESHOLD));
        }
    }
}
