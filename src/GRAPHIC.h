#ifndef GRAPHIC_H
#define GRAPHIC_H

#include <BlynkGOv3.h>
#include "MEMORY.h"
#include "GPIO.h"
#include "MODESELECTOR.h"
#include "SENSORCON.h"

extern GWiFiSetting wifisetting;
extern GButton btn_setting_delay1;
extern GButton btn_setting_delay2;
extern GImage thank_you;
extern GImage payment;
extern GLabel lb_payment_price;
extern GRect rect_mqtt_config_notify;

extern GButton btn_setting_mode1;
extern GButton btn_setting_mode2;
extern GButton btn_setting_mode3;
extern GButton btn_setting_mode4;
extern GButton btn_setting_buzzer;

extern  GTextArea ta_mqtt_setting_server;
extern  GTextArea ta_mqtt_setting_topic;
extern  GTextArea ta_mqtt_setting_port;

extern  GTextArea ta_avd_encode;
extern  GTextArea ta_avd_ldr;

namespace GRAPHIC {
    void designWelcomePage();
    void designSettingPage();
    void designMqttSettingPage(); 
    void desingQrPaymentPage();       
    void desingPricePay();
    void desingPageThankYou();
    void designAVDPage();  
    void mqttConfigNotify();
} 
#endif