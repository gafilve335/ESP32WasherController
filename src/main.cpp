#include <BlynkGOv3.h>
#include "GPIO.h"
#include "GRAPHIC.h"
#include "SENSORCON.h"
#include "MQTTBROKER.h"
#include "HTTP_CON.h"


void setup(){

 Serial.begin(115200);Serial.println();   
 BlynkGO.begin();                        

//Communication
  wifisetting.autoconnection();
  AsyncWEBSERVER::StartMutiCast();
  AsyncWEBSERVER::begin();
  MQTTBROKER::MqttConnected();            

//GPIO
  PINMODE::SET_GPIO();                    

//GRAPHIC
  #ifdef ENABLE_WELCOME_PAGE
  GRAPHIC::designWelcomePage();           
  #endif

  #ifdef ENABLE_SETTING_PAGE
  GRAPHIC::designSettingPage();  
  #endif

  #ifdef ENABLE_MQTT_PAGE   
  GRAPHIC::designMqttSettingPage();
  #endif

  #ifdef ENABLE_PAYMENT_PAGE
  GRAPHIC::desingQrPaymentPage();
  #endif         

  #ifdef ENABLE_PRIPAY_PAGE
  GRAPHIC::desingPricePay();    
  #endif

  #ifdef ENABLE_NOTIFY_PAGE 
  GRAPHIC::desingPageThankYou();
  GRAPHIC::mqttConfigNotify();       
  #endif
  
  #ifdef ENABLE_AVD_PAGE   
  GRAPHIC::designAVDPage();
  #endif
  
  SENSORCONTROLLER::createSensorQueueAndEvents();  
  xTaskCreate(SENSORCONTROLLER::LDRTask, "LDRTask", 4096, nullptr, 2, nullptr);                                                              
  xTaskCreate(SENSORCONTROLLER::LUXCONTROLLER, "LUXCONTROLLER", 4096 , nullptr, 1, nullptr); 

}

void loop(){
BlynkGO.update(); 
}

