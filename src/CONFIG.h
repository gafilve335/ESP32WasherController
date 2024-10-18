#ifndef CONFIG_H
#define CONFIG_H

// Define Event Group
#define BIT_ERROR_OCCURRED  (1 << 0)
#define BIT_PROCESS_IDLE    (1 << 1)
#define BIT_PROCESS_WASHER  (1 << 2)

// DEBUG
#define DEBUG
#ifdef DEBUG
  #define DEBUG_PRINT(x) Serial.println(x)
#else
  #define DEBUG_PRINT(x)
#endif

// FreeRTOS
#define DELAY_TIME_MS  500 


//#define LIGHT_LIMIT 500
  #define ENABLE_LDR_SENSOR  // ENABLE LDR                     
  #ifdef ENABLE_LDR_SENSOR
    #define ENABLE_LUX_CONTROLLER  // USE LUX CONTROLLER MACHINE  
    #ifdef  ENABLE_LUX_CONTROLLER                    
      #define ENABLE_MACHINE_STATUS_PUBLISH //  PUBLISH MACHINE STATUS
    #endif 
  #endif 


// GRAPHIC
#define ENABLE_WELCOME_PAGE
#define ENABLE_SETTING_PAGE
#define ENABLE_MQTT_PAGE
#define ENABLE_PAYMENT_PAGE
#define ENABLE_PRIPAY_PAGE
#define ENABLE_NOTIFY_PAGE
#define ENABLE_AVD_PAGE


// COMMUNICATION
#define ENABLE_WIFI_CONNECTION
#ifdef ENABLE_WIFI_CONNECTION
  #define ENABLE_MQTT_CONNECTION
#endif
#endif // CONFIG_H
