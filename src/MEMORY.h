#include <BlynkGOv3.h>
#ifndef MEMORY_H
#define MEMORY_H

extern String DELAY_1KEY;
extern String DELAY_2KEY;
extern String DELAY_3KEY;
extern String DELAY_4KEY;
extern String BUZZER_KEY;
extern String PRICE_KEY;
extern String ENCODE_KEY;
extern String MODE_KEY;
extern String LDR_THRESHOLD_KEY;

extern String MQTT_SERVER_KEY;
extern String MQTT_TOPIC_KEY;
extern String MQTT_PORT_KEY;

extern String LDR_KEY;
extern String DEBUG_KEY;

namespace MEMORY {
    
    bool getFlashMemState(String key);
    void setFlashMemState(String key, bool state);

    String getFlashMemString(String key);
    void setFlashMemString(String key, String value);
}



#endif 