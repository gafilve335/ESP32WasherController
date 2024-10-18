#include "HTTP_CON.h"

namespace AsyncWEBSERVER {
  AsyncWebServer server(80);
  void setMQTTConfig(const String &server, const String &topic, String &port);
  void StartMutiCast();

  // ตัวแปรเก็บค่า MQTT Config
  String mqttServer;
  String mqttTopic;
  String mqttPort;

  void begin() {

    // Endpoint สำหรับรับข้อมูล JSON แบบ POST
    server.on("/post", HTTP_POST, [](AsyncWebServerRequest *request) {
      // Nothing to do in this handler
    }, NULL, [](AsyncWebServerRequest *request, uint8_t *data, size_t len, size_t index, size_t total) {
      StaticJsonDocument<256> doc;
      DeserializationError error = deserializeJson(doc, data);

      // ตรวจสอบว่าการ deserialize สำเร็จหรือไม่
      if (error) {
        Serial.print(F("deserializeJson() failed: "));
        Serial.println(error.f_str());
        request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Invalid JSON\"}");
        return;
      }

      // ตรวจสอบว่าฟิลด์ type และ value มีอยู่หรือไม่
      if (!doc.containsKey("type") || !doc.containsKey("value")) {
        request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Missing 'type' or 'value'\"}");
        return;
      }

      // ดึงข้อมูลจาก JSON
      String type = doc["type"].as<String>();
      String value = doc["value"].as<String>();

      // ตรวจสอบว่าฟิลด์ type และ value มีค่าเป็น 'ESP32CMD' และ 'SET_MQTT_CONFIG'
      if (type == "ESP32CMD" && value == "SET_MQTT_CONFIG") {

        // ตรวจสอบว่าฟิลด์ server, topic, และ port มีอยู่และไม่เป็นค่าว่าง
        if (!doc.containsKey("server") || !doc.containsKey("topic") || !doc.containsKey("port")) {
          request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Missing 'server', 'topic', or 'port'\"}");
          return;
        }

        mqttServer = doc["server"].as<String>();
        mqttTopic = doc["topic"].as<String>();
        mqttPort = doc["port"].as<String>();

        // ตรวจสอบว่าฟิลด์ server, topic, และ port มีค่าไม่เป็นค่าว่าง
        if (mqttServer.isEmpty() || mqttTopic.isEmpty() || mqttPort.isEmpty()) {
          request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Invalid 'server', 'topic', or 'port'\"}");
          return;
        }

        // แสดงข้อมูลที่ได้รับ
        Serial.println("MQTT Config Received:");
        Serial.print("Server: ");
        Serial.println(mqttServer);
        Serial.print("Topic: ");
        Serial.println(mqttTopic);
        Serial.print("Port: ");
        Serial.println(mqttPort);

        // ตั้งค่า MQTT Config
        setMQTTConfig(mqttServer, mqttTopic, mqttPort);

        // ส่งการตอบกลับไปยัง client
        request->send(200, "application/json", "{\"status\":\"success\",\"message\":\"MQTT Config set\"}");
      } else {
        request->send(400, "application/json", "{\"status\":\"error\",\"message\":\"Invalid command\"}");
      }
    });

    server.onNotFound([](AsyncWebServerRequest *request) {
      request->send(404, "text/plain", "Not found");
    });

    server.begin();
  }

  void end() {
    server.end();
  }

  void setMQTTConfig(const String &server, const String &topic, String &port) {
    Serial.println("Setting MQTT configuration...");
    Serial.print("MQTT Server: ");
    Serial.println(server);
    Serial.print("MQTT Topic: ");
    Serial.println(topic);
    Serial.print("MQTT Port: ");
    Serial.println(port);

    // บันทึกการตั้งค่า MQTT ลงหน่วยความจำ
    BlynkGO.flashMem(MQTT_SERVER_KEY, server);
    BlynkGO.flashMem(MQTT_TOPIC_KEY, topic);
    BlynkGO.flashMem(MQTT_PORT_KEY, port);

    MQTTBROKER::reMqttMemory();

    // อัพเดต UI
    ta_mqtt_setting_server.text(MEMORY::getFlashMemString(MQTT_SERVER_KEY));
    ta_mqtt_setting_topic.text(MEMORY::getFlashMemString(MQTT_TOPIC_KEY));
    ta_mqtt_setting_port.text(MEMORY::getFlashMemString(MQTT_PORT_KEY)); 

    // แสดงการแจ้งเตือนใน UI
    rect_mqtt_config_notify.hidden(false);
    xTaskCreate([](void *parameter) {
      vTaskDelay(3000 / portTICK_PERIOD_MS);
      rect_mqtt_config_notify.hidden(true);
      vTaskDelete(nullptr); 
    }, "MqttConfigTask", 1024, nullptr, 1, nullptr);
  }

  void StartMutiCast() {
    Serial.println("Attempting to start mDNS...");
    if (!MDNS.begin("esp32")) {
      Serial.println("Error: mDNS start failed. Check your network connection.");
    } else {
      Serial.println("mDNS started successfully.");
    }
  }
}
