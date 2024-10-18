#include "GRAPHIC.h"
//นำเข้ารูปภาพ
IMG_DECLARE(bg);                             //ภาพพื้นหลัง
IMG_DECLARE(icon_logo);                      //โลโก้ร้าน
IMG_DECLARE(img_thai_qrpayment_w200);        //ภาพ QR Payment

// นำเข้าฟอนต์
FONT_DECLARE(fc_minimal_40);
FONT_DECLARE(fc_minimal_30);
FONT_DECLARE(fc_minimal_80);

// หน้าแรก       
GImage welcome_background(bg);                                                                                                                                                            
    GImageButton ImgBtn_welcomePage(icon_logo,welcome_background);              
    GButton btn_welcomePage_setting(SYMBOL_SETTINGS,welcome_background);

//-->หน้าตั้งค่า
GImage setting_background(bg);
      //--จัดการการเชื่อมต่อ WIFI
    GWiFiSetting wifisetting;
    GContainer controller_setting_btn_form(setting_background);
        //--ปุ่มกดแบบสวิตซ์ (กดติดกดดับ)
        GLabel  lb_setting_mode_form("PROGRAM",controller_setting_btn_form); //เมนู "DELAY"
        GButton btn_setting_mode1(BUTTON_SWITCH,"MODE1",controller_setting_btn_form); // ปุ่มกดตั้งค่าดีเลย์ 1
        GButton btn_setting_mode2(BUTTON_SWITCH,"MODE2",controller_setting_btn_form); // ปุ่มกดตั้งค่าดีเลย์ 2
        GButton btn_setting_mode3(BUTTON_SWITCH,"MODE3",controller_setting_btn_form); // ปุ่มกดตั้งค่าดีเลย์ 3
        GButton btn_setting_mode4(BUTTON_SWITCH,"MODE4",controller_setting_btn_form); // ปุ่มกดตั้งค่าดีเลย์ 4

        //--เมนูปุ่มกดตั้งค่าเซ็นเซอร์
    GContainer sensor_setting_form(setting_background);
        GLabel lb_setting_sensor_form("SENSOR",sensor_setting_form); //เมนู "SENSOR"
        GButton btn_setting_buzzer(BUTTON_SWITCH,"BUZZER",sensor_setting_form);// ปุ่มกดตั้งค่า Buzzer
        GButton btn_setting_ldr(BUTTON_SWITCH,"MDNS",sensor_setting_form);// ปุ่มกดตั้งค่า ldr

     //--เมนูตั้งค่าระบบ
    GContainer system_setting_form(setting_background);
         GLabel lb_setting_compile_form("COMPILE",system_setting_form); //เมนู "COMPILE"
         GButton btn_setting_debug(BUTTON_SWITCH,"SERIAL",system_setting_form);// ปุ่มกดตั้งค่า DEBUG


    //--เมนู general
    //GContainer general_setting_form(setting_background);
         //GLabel lb_setting_system_form("GENERAL",general_setting_form); //เมนู "GENERAL"
         GButton btn_setting_wifi(" WIFI",setting_background);// ปุ่มกดตั้งค่า WIFI
         GButton btn_setting_exit( "EXIT",setting_background); //ปุ่ม EXIT   
         GButton btn_setting_mqtt( "MQTT",setting_background); //ปุ่ม MQTT  
         GButton btn_setting_TEST( "SET",setting_background); //ปุ่ม TEST  
         GButton btn_setting_others( "AVD",setting_background); //ปุ่ม others

    
        //--Error Message General
        GRect error_message_general;
        GLabel lb_error_message_general(error_message_general);
    
//--หน้าตั้งค่าตั้งค่า MQTT 
GImage mqtt_setting_background(bg);
        GRect rect_mqtt_setting_success;
            GLabel lb_mqtt_setting_success(rect_mqtt_setting_success);
        GPage page_mqtt(mqtt_setting_background);

        // ฟอร์มกรอกเซิฟเวอร์
        GContainer cont_mqtt_setting_form(page_mqtt);
            GContainer cont_mqtt_setting_server_form(cont_mqtt_setting_form);
                GLabel lb_mqtt_settung_server(cont_mqtt_setting_server_form);
                GTextArea ta_mqtt_setting_server(cont_mqtt_setting_server_form);

            // ฟอร์มกรอกท็อปพิค
            GContainer cont_mqtt_setting_topic_form(cont_mqtt_setting_form);
                GLabel lb_mqtt_settung_topic(cont_mqtt_setting_topic_form);
                GTextArea ta_mqtt_setting_topic(cont_mqtt_setting_topic_form);

            // ฟอร์มกรอกพอท
            GContainer cont_mqtt_setting_port_form(cont_mqtt_setting_form);
                GLabel lb_mqtt_settung_port(cont_mqtt_setting_port_form);
                GTextArea ta_mqtt_setting_port(cont_mqtt_setting_port_form);

            // ฟอร์อม ปุ่ม Save และ Cancel
            GContainer cont_mqtt_setting_button_form(cont_mqtt_setting_form);
                GButton btn_mqtt_setting_save( "SAVE",cont_mqtt_setting_button_form);
                 GButton btn_mqtt_setting_exit( "BACK",cont_mqtt_setting_button_form);

//--> หน้าสแกน QR Code
GImage payment(bg);

  // แสดง QR Code
  GRect   rect_qr_payment;
    GImage   image_promptpay(img_thai_qrpayment_w200 , rect_qr_payment);
    GQRCode  qrcode(rect_qr_payment);

 GContainer con_payment_Form;
    GLabel lb_payment_subtitle("PRICE",con_payment_Form);
    GLabel lb_payment_price(con_payment_Form);
    GLabel lb_payment_title("BAHT",con_payment_Form);
    GButton btn_payment_back(BUTTON_PUSH,"CANCEL",con_payment_Form);

//--> หน้าขอบคุณ
GImage thank_you(bg);

  //--ฟอร์มขอบคุณ
  GContainer thank_you_Form(thank_you);
    GLabel lb_thank_you_SubTitle("ขอบคุณที่ใช้บริการ",thank_you_Form);
    GLabel lb_thank_you("THANK YOU",thank_you_Form);
  
//--> หน้าตั้งค่า AVD 
GImage avd_background(bg);
    GContainer cont_avd_price_form(avd_background);

        GContainer cont_avd_price(cont_avd_price_form);
            GLabel lb_avd_price(cont_avd_price);
                GTextArea ta_avd_price(cont_avd_price);
        
        GContainer cont_avd_encode(cont_avd_price_form);
            GLabel lb_avd_encode(cont_avd_encode);
                GTextArea ta_avd_encode(cont_avd_encode);
        
        GContainer cont_avd_ldr(cont_avd_price_form);
            GLabel lb_avd_ldr(cont_avd_ldr);
                GTextArea ta_avd_ldr(cont_avd_ldr);
                
        GButton btn_avd_back("Back",cont_avd_price_form);

GRect rect_mqtt_config_notify;
GLabel lb_mqtt_config_notify(rect_mqtt_config_notify);

namespace GRAPHIC{

     //-->ออกแบบหน้าต้อนรับ
    void designWelcomePage(){
        
        // ออกแบบปุ่มโลโก้เครื่องซักผ้า 
        welcome_background.hidden(false);                       // ซ่อนวิตเจ็ต
        ImgBtn_welcomePage.onClicked([](GWidget *widget){       // Event 
         EventBits_t uxBits = xEventGroupGetBits(xEventGroup);
         bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY); // ดึงค่าจาก MEMORY
         if (BuzzerState){buzzer.beep(1);} 
         
         if ((uxBits & BIT_PROCESS_IDLE) != 0) {
            lb_payment_price.text(MEMORY::getFlashMemString(PRICE_KEY));
            qrcode.encode(MEMORY::getFlashMemString(ENCODE_KEY));
            payment.hidden(false);
        }
             
        });
        
        // ออกแบบปุ่ม Setting
        btn_welcomePage_setting.round_design();                  //ให้ปุ่มมีขอบโค้ง      
        btn_welcomePage_setting.align(ALIGN_TOP_RIGHT, -5, 5);   //จัดตำแหน่ง บน ขวา
        btn_welcomePage_setting.onClicked([](GWidget *widget){   // Event
        
        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY); // ดึงค่าจาก MEMORY
         if (BuzzerState){buzzer.beep(1);} 

            setting_background.hidden(false);

        });
    }


    void designSettingPage(){

        setting_background.hidden(true);
        setting_background.color(TFT_WHITE);

//----------------------------------------------------------------------------------------------------------------
//------กราฟฟิกส่วนคอนโทรลเลอร์
        //จัดกลุ่มวิตเจ็ตปุ่มกดใน Container
        controller_setting_btn_form.layout(LAYOUT_COL_M);            // จัดรูปแบบการแสดงผล 
        controller_setting_btn_form.padding(10,10,10,10,10);         // [บน,ล่าง,ซ้าย,ขวา,ทั้งหมด]
        controller_setting_btn_form.align(ALIGN_TOP_LEFT,45,20);     // จัดตำแหน่งบนซ้าย
        controller_setting_btn_form.color(TFT_WHITE);                // เพิ่มสีปุ่มกด
        controller_setting_btn_form.corner_radius(5);                // ขอบโค้ง
        controller_setting_btn_form.border(2,TFT_BLACK);             // ขอบปุ่มกด
        //controller_setting_btn_form.opa(0);                        // โปร่งใส
        lb_setting_mode_form.font(fc_minimal_30,TFT_BLACK);


            //ดึงสถานะจาก FlashMem มากำหนดให้ว่าเราเลือกโหมดนี้หรือไม้ แล้วเปลี่ยนธีมตามที่เลือก
        if (BlynkGO.flashMem_exists(DELAY_1KEY)) { // เช็คว่ามี KEY อยู่บน FlashMem หรือไม่
                bool state = (bool) BlynkGO.flashMem_Int(DELAY_1KEY); // ถ้ามีให้ state เท่ากับค่า key ที่อ่านได้
                if (state) { 
                    btn_setting_mode1.ON();
                    btn_setting_mode1.color(TFT_GREEN);
                    btn_setting_mode1.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode1.OFF();
                    btn_setting_mode1.color(TFT_GRAY);
                    btn_setting_mode1.border(3, TFT_LIGHTGRAY);

                }
            } else { // กรณีไม่มีข้อมูลใน KEY สถานะปุ่มกดจะถูกตั้งเป็น OFF
                btn_setting_mode1.OFF();
                btn_setting_mode1 = "OFF";
                btn_setting_mode1.color(TFT_GRAY);
                btn_setting_mode1.border(3, TFT_LIGHTGRAY);
                
            }


        //ออกแบบกราฟฟิกปุ่มกดเลือก Mode หมายเลข 1
        btn_setting_mode1.size(100, 50);
        btn_setting_mode1.shadow(10);
        btn_setting_mode1.font(fc_minimal_30, TFT_WHITE);
        btn_setting_mode1.onClicked([](GWidget* widget) { // เมื่อมีการคลิกเกิดขึ้น [Button Event]

                bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
                if (BuzzerState) {buzzer.beep(1);}

                bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
                if (debugPrint) {
                    Serial.printf("ปุ่มตั้งค่าดีเลย์ 1 : Toggle %s\n", (btn_setting_mode1.isON()) ? "ON" : "OFF");
                }

                bool state = btn_setting_mode1.isON(); // เช็คว่าสถานะเป็น ON หรือไม่ แล้วคืนค่าออกมาเป็น Bool
                BlynkGO.flashMem(DELAY_1KEY, state); // บันทึกค่าที่ได้ลง FlashMem
                // อัพเดท UI ให้กับปุ่มกด
                if (state) { 
                    btn_setting_mode1.color(TFT_GREEN);
                    btn_setting_mode1.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode1.color(TFT_GRAY);
                    btn_setting_mode1.border(3, TFT_LIGHTGRAY);
                }
            });

        

           //ดึงสถานะจาก FlashMem มากำหนดให้ Mode 2 
        if (BlynkGO.flashMem_exists(DELAY_2KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(DELAY_2KEY); 
                if (state) { 
                    btn_setting_mode2.ON();
                    btn_setting_mode2.color(TFT_GREEN);
                    btn_setting_mode2.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode2.OFF();
                    btn_setting_mode2.color(TFT_GRAY);
                    btn_setting_mode2.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_mode2.OFF();
                btn_setting_mode2.color(TFT_GRAY);
                btn_setting_mode2.border(3, TFT_LIGHTGRAY);
                
            }        
        //ออกแบบกราฟฟิกปุ่มกดเลือก Mode หมายเลข 2
        btn_setting_mode2.size(100, 50);
        btn_setting_mode2.shadow(10);
        btn_setting_mode2.font(fc_minimal_30, TFT_WHITE);
        btn_setting_mode2.onClicked([](GWidget* widget) { 

                bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
                if (BuzzerState) {buzzer.beep(1);}

                bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
                if (debugPrint) {
                    Serial.printf("ปุ่มตั้งค่าดีเลย์ 2 : Toggle %s\n", (btn_setting_mode2.isON()) ? "ON" : "OFF");
                }

                bool state = btn_setting_mode2.isON();
                BlynkGO.flashMem(DELAY_2KEY, state); 
                
                if (state) { 
                    btn_setting_mode2.color(TFT_GREEN);
                    btn_setting_mode2.border(3, TFT_GREENBLYNK);
                           
                } else {
                    btn_setting_mode2.color(TFT_GRAY);
                    btn_setting_mode2.border(3, TFT_LIGHTGRAY);
                }
            });



           //ดึงสถานะจาก FlashMem มากำหนดให้ Mode 3
        if (BlynkGO.flashMem_exists(DELAY_3KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(DELAY_3KEY); 
                if (state) { 
                    btn_setting_mode3.ON();
                    btn_setting_mode3.color(TFT_GREEN);
                    btn_setting_mode3.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode3.OFF();
                    btn_setting_mode3.color(TFT_GRAY);
                    btn_setting_mode3.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_mode3.OFF();
                btn_setting_mode3.color(TFT_GRAY);
                btn_setting_mode3.border(3, TFT_LIGHTGRAY);
                
            }    


        //ออกแบบกราฟฟิกปุ่มกดเลือก Mode หมายเลข 3
        btn_setting_mode3.size(100, 50);
        btn_setting_mode3.shadow(10);
        btn_setting_mode3.font(fc_minimal_30, TFT_WHITE);
        btn_setting_mode3.onClicked([](GWidget* widget) { 

                bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
                if (BuzzerState) {buzzer.beep(1);}

                bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
                if (debugPrint) {
                    Serial.printf("ปุ่มตั้งค่าดีเลย์ 3 : Toggle %s\n", (btn_setting_mode3.isON()) ? "ON" : "OFF");
                }

                bool state = btn_setting_mode3.isON();
                BlynkGO.flashMem(DELAY_3KEY, state); 
                
                if (state) { 

                    btn_setting_mode3.color(TFT_GREEN);
                    btn_setting_mode3.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode3.color(TFT_GRAY);
                    btn_setting_mode3.border(3, TFT_LIGHTGRAY);
                }
            });

                //ดึงสถานะจาก FlashMem มากำหนดให้ Mode 4
                if (BlynkGO.flashMem_exists(DELAY_4KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(DELAY_4KEY); 
                if (state) { 
                    btn_setting_mode4.ON();
                    btn_setting_mode4.color(TFT_GREEN);
                    btn_setting_mode4.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_mode4.OFF();
                    btn_setting_mode4.color(TFT_GRAY);
                    btn_setting_mode4.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_mode4.OFF();
                btn_setting_mode4.color(TFT_GRAY);
                btn_setting_mode4.border(3, TFT_LIGHTGRAY);
            }       
            
        //--ออกแบบปุ่มกดตั้ง Mode หมายเลข 4
        btn_setting_mode4.size(100, 50);
        btn_setting_mode4.shadow(10);
        btn_setting_mode4.font(fc_minimal_30, TFT_WHITE);
        btn_setting_mode4.onClicked([](GWidget* widget) {

                bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
                if (BuzzerState) {buzzer.beep(1);}

                bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
                if (debugPrint) {
                    Serial.printf("ปุ่มตั้งค่าดีเลย์ 4 : Toggle %s\n", (btn_setting_mode4.isON()) ? "ON" : "OFF");
                }

                bool state = btn_setting_mode4.isON(); 
                BlynkGO.flashMem(DELAY_4KEY, state); 
                
                if (state) { 
                    btn_setting_mode4.color(TFT_GREEN);
                    btn_setting_mode4.border(3, TFT_GREENBLYNK);
                
                } else {
                    btn_setting_mode4.color(TFT_GRAY);
                    btn_setting_mode4.border(3, TFT_LIGHTGRAY);
                }
            });

//---------------------------------------------------------------------------------------------


        //จัดกลุ่มวิตเจ็ตปุ่มกดเซ็นเซอร์ใน Container
        sensor_setting_form.layout(LAYOUT_COL_M); 
        sensor_setting_form.padding(10,10,10,10,10);  // [บน,ล่าง,ซ้าย,ขวา,ทั้งหมด]
        sensor_setting_form.align(ALIGN_TOP_LEFT,180,20);
        sensor_setting_form.color(TFT_WHITE);
        sensor_setting_form.corner_radius(5);
        sensor_setting_form.border(2,TFT_BLACK);
        //จัดฟอนต์และสีอักษร
        lb_setting_sensor_form.font(fc_minimal_30,TFT_BLACK);


        if (BlynkGO.flashMem_exists(BUZZER_KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(BUZZER_KEY); 
                if (state) { 
                    btn_setting_buzzer.ON();
                    //btn_setting_buzzer = "ON";
                    btn_setting_buzzer.color(TFT_GREEN);
                    btn_setting_buzzer.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_buzzer.OFF();
                    //btn_setting_buzzer = "OFF";
                    btn_setting_buzzer.color(TFT_GRAY);
                    btn_setting_buzzer.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_buzzer.OFF();
                //btn_setting_buzzer = "OFF";
                btn_setting_buzzer.color(TFT_GRAY);
                btn_setting_buzzer.border(3, TFT_LIGHTGRAY);
                
            }  
        //--ออกแบบปุ่มกดตั้งค่าบัสเซอร์
        btn_setting_buzzer.size(100,50);
        btn_setting_buzzer.shadow(10);
        btn_setting_buzzer.font(fc_minimal_30,TFT_WHITE);
        btn_setting_buzzer.onClicked([](GWidget* widget){     

        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
        if (BuzzerState) {buzzer.beep(1);} 

        bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
        if(debugPrint){Serial.printf("ปุ่มตั้งบัสเซอร์  : Toggle %s\n", (btn_setting_buzzer.isON())? "ON" : "OFF"); }
        

        bool state = btn_setting_buzzer.isON(); 
        BlynkGO.flashMem(BUZZER_KEY, state); 
                
         if( btn_setting_buzzer.isON()){
            btn_setting_buzzer.color(TFT_GREEN);
            btn_setting_buzzer.border(3,TFT_GREENBLYNK);

         }else{
             btn_setting_buzzer.color(TFT_GRAY);
             btn_setting_buzzer.border(3,TFT_LIGHTGRAY);
         }
         
        });



         if (BlynkGO.flashMem_exists(LDR_KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(LDR_KEY); 
                if (state) { 
                    btn_setting_ldr.ON();
                    btn_setting_ldr.color(TFT_GREEN);
                    btn_setting_ldr.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_ldr.OFF();
                    btn_setting_ldr.color(TFT_GRAY);
                    btn_setting_ldr.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_ldr.OFF();
                btn_setting_ldr.color(TFT_GRAY);
                btn_setting_ldr.border(3, TFT_LIGHTGRAY);   
            }  
        //--ออกแบบปุ่มกดตั้งค่าเซ็นเซอร์วัดแสง
        btn_setting_ldr.size(100,50);
        btn_setting_ldr.shadow(10);
        btn_setting_ldr.font(fc_minimal_30,TFT_WHITE);
        btn_setting_ldr.onClicked([](GWidget* widget){     
            
        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
        if (BuzzerState) {buzzer.beep(1);} 

        bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
        if(debugPrint){Serial.printf("ปุ่มตั้งเซ็นเซอร์แสง  : Toggle %s\n", (btn_setting_buzzer.isON())? "ON" : "OFF"); }
        
        bool state = btn_setting_ldr.isON(); 
        BlynkGO.flashMem(LDR_KEY, state); 
                
         if( btn_setting_ldr.isON()){
            btn_setting_ldr.color(TFT_GREEN);
            btn_setting_ldr.border(3,TFT_GREENBLYNK);

         }else{
             btn_setting_ldr.color(TFT_GRAY);
             btn_setting_ldr.border(3,TFT_LIGHTGRAY);
         }
         
         
    });

         //จัดกลุ่มวิตเจ็ตปุ่มกดระบบใน Container
        system_setting_form.layout(LAYOUT_COL_M); 
        system_setting_form.padding(10,10,10,10,10);  // [บน,ล่าง,ซ้าย,ขวา,ทั้งหมด]
        system_setting_form.align(ALIGN_TOP_LEFT,310,20);
        system_setting_form.color(TFT_WHITE);
        system_setting_form.corner_radius(5);
        system_setting_form.border(2,TFT_BLACK);

        //จัดฟอนต์และสีอักษร
        lb_setting_compile_form.font(fc_minimal_30,TFT_BLACK);

         if (BlynkGO.flashMem_exists(DEBUG_KEY)) { 
                bool state = (bool) BlynkGO.flashMem_Int(DEBUG_KEY); 
                if (state) { 
                    btn_setting_debug.ON();
                    btn_setting_debug.color(TFT_GREEN);
                    btn_setting_debug.border(3, TFT_GREENBLYNK);

                } else {
                    btn_setting_debug.OFF();
                    btn_setting_debug.color(TFT_GRAY);
                    btn_setting_debug.border(3, TFT_LIGHTGRAY);

                }
            } else {
                btn_setting_debug.OFF();
                btn_setting_debug.color(TFT_GRAY);
                btn_setting_debug.border(3, TFT_LIGHTGRAY);
                
            }  
        //--ออกแบบปุ่มกดตั้งค่าดีบัค
        btn_setting_debug.size(100,50);
        btn_setting_debug.shadow(10);
        btn_setting_debug.font(fc_minimal_30,TFT_WHITE);
        btn_setting_debug.onClicked([](GWidget* widget){     
        
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);} 

            bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
            if(debugPrint){Serial.printf("ปุ่มตั้งดีบัค  : Toggle %s\n", (btn_setting_debug.isON())? "ON" : "OFF"); }
            

            bool state = btn_setting_debug.isON(); 
            BlynkGO.flashMem(DEBUG_KEY, state); 
                    
            if( btn_setting_debug.isON()){
                btn_setting_debug.color(TFT_GREEN);
                btn_setting_debug.border(3,TFT_GREENBLYNK);

            }else{
                btn_setting_debug.color(TFT_GRAY);
                btn_setting_debug.border(3,TFT_LIGHTGRAY);
            }

        });     

        //--ออกแบบปุ่ม WIFI Manager
        btn_setting_wifi.size(120, 50);
        btn_setting_wifi.align(ALIGN_BOTTOM_LEFT,180,-70);
        btn_setting_wifi.font(fc_minimal_30);
        btn_setting_wifi.color(TFT_BLUE);
        btn_setting_wifi.onClicked([](GWidget *widget){
               
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);}


            wifisetting.onBack([](GWidget*){
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);}

            wifisetting.hidden(true);
        }); 
           wifisetting.hidden(false);
         });

        //--ออกแบบปุ่ม EXIT
        btn_setting_exit.size(120, 50);
        btn_setting_exit.align(ALIGN_BOTTOM_LEFT,180,-10);
        btn_setting_exit.font(fc_minimal_30);
        btn_setting_exit.color(TFT_RED);
        btn_setting_exit.onClicked([](GWidget *widget){

            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);}

           setting_background.hidden(true);
         });

          //--ออกแบบปุ่ม MQTT
        btn_setting_mqtt.size(120, 50);
        btn_setting_mqtt.align(ALIGN_BOTTOM_LEFT,310,-70);
        btn_setting_mqtt.font(fc_minimal_30);
        btn_setting_mqtt.color(TFT_COLOR_HEX(0xD10363));
        btn_setting_mqtt.onClicked([](GWidget *widget){

            bool BuzzerState =MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);}

            mqtt_setting_background.hidden(false);

            //--ดึงข้อมูลเซิฟเวอร์ก่อนจะ route to mqtt setting page
            ta_mqtt_setting_server.text(MEMORY::getFlashMemString(MQTT_SERVER_KEY));
            ta_mqtt_setting_topic.text(MEMORY::getFlashMemString(MQTT_TOPIC_KEY));
            ta_mqtt_setting_port.text(MEMORY::getFlashMemString(MQTT_PORT_KEY));

         });

        //--ออกแบบปุ่ม TEST
        btn_setting_TEST.size(120, 50);
        btn_setting_TEST.align(ALIGN_BOTTOM_LEFT,310,-10);
        btn_setting_TEST.font(fc_minimal_30);
        btn_setting_TEST.color(TFT_COLOR_HEX(0x9BEC00));
        btn_setting_TEST.onClicked([](GWidget *widget){
           
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) {buzzer.beep(1);}

            if(digitalRead(GPIO_NUM_5)== LOW){

             SELECTOR::createTaskForMode();   

            }else{
             
                error_message_general.hidden(false);
                error_message_general.size(300, 100);
                error_message_general.color(TFT_WHITE);
                error_message_general.border(2, TFT_RED);
                error_message_general.corner_radius(5);
                lb_error_message_general = "The system is running.";
                lb_error_message_general.font(prasanmit_30, TFT_BLACK);

                static SoftTimer timer;
                timer.setInterval(2000, []() {
                error_message_general.hidden(true);
             });
            }
         });

        //--ออกแบบปุ่ม others
        btn_setting_others.size(120, 50);
        btn_setting_others.align(ALIGN_BOTTOM_LEFT,310,-130);
        btn_setting_others.font(fc_minimal_30);
        btn_setting_others.color(TFT_COLOR_HEX(0xEF4040));
        btn_setting_others.onClicked([](GWidget *widget){
            
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            bool debugPrint = MEMORY::getFlashMemState(DEBUG_KEY);
            if (BuzzerState) {buzzer.beep(1);}

            ta_avd_price.text(MEMORY::getFlashMemString(PRICE_KEY));
            ta_avd_encode.text(MEMORY::getFlashMemString(ENCODE_KEY));
            ta_avd_ldr.text(MEMORY::getFlashMemString(LDR_THRESHOLD_KEY));
            if(debugPrint){Serial.println("get Price value successfully");}   
            avd_background.hidden(false);

         });        
    }

  //--หน้าตั้งค่า MQTT
  void designMqttSettingPage() {
        mqtt_setting_background.hidden(true);

        page_mqtt.size(430,300);
        page_mqtt.corner_radius(5);
        page_mqtt.opa(0);
        page_mqtt.align(ALIGN_BOTTOM,0,-10);
        page_mqtt.border(2,TFT_SILVER);
        page_mqtt.layout(LAYOUT_COL_L,10,10,10,10,0);
        page_mqtt.color(TFT_WHITE);

        cont_mqtt_setting_form.layout(LAYOUT_COL_M);
        cont_mqtt_setting_form.padding(10, 10, 10, 10, 10);
        cont_mqtt_setting_form.opa(0);

        //ฟิลด์กรอกข้อมูล Server
        cont_mqtt_setting_server_form.layout(LAYOUT_ROW_M);
        cont_mqtt_setting_server_form.corner_radius(5);
        cont_mqtt_setting_server_form.border(2,TFT_COLOR_HEX(0x686D76));
        cont_mqtt_setting_server_form.color(TFT_COLOR_HEX(0xEEEEEE));
            lb_mqtt_settung_server = "SERVER : ";
            lb_mqtt_settung_server.font(fc_minimal_30, TFT_BLACK);
            ta_mqtt_setting_server.cursor_type(CURSOR_NONE);
            ta_mqtt_setting_server.width(240);
            ta_mqtt_setting_server.border(2, TFT_BLACK);
            ta_mqtt_setting_server.font(fc_minimal_30,TFT_BLACK);

        //ฟิลด์กรอกข้อมูล Topic
        cont_mqtt_setting_topic_form.layout(LAYOUT_ROW_M);
        cont_mqtt_setting_topic_form.corner_radius(5);
        cont_mqtt_setting_topic_form.border(2,TFT_COLOR_HEX(0x686D76));
        cont_mqtt_setting_topic_form.color(TFT_COLOR_HEX(0xEEEEEE));
            lb_mqtt_settung_topic = "TOPIC : ";
            lb_mqtt_settung_topic.font(fc_minimal_30, TFT_BLACK);
            ta_mqtt_setting_topic.cursor_type(CURSOR_NONE);
            ta_mqtt_setting_topic.width(260);
            ta_mqtt_setting_topic.border(2, TFT_BLACK);
            ta_mqtt_setting_topic.font(fc_minimal_30,TFT_BLACK);

        //  ฟิลด์กรอกข้อมูลพอต
        cont_mqtt_setting_port_form.layout(LAYOUT_ROW_M);
        cont_mqtt_setting_port_form.corner_radius(5);
        cont_mqtt_setting_port_form.border(2,TFT_COLOR_HEX(0x686D76));
        cont_mqtt_setting_port_form.color(TFT_COLOR_HEX(0xEEEEEE));
            lb_mqtt_settung_port = "PORT : ";
            lb_mqtt_settung_port.font(fc_minimal_30, TFT_BLACK);
            ta_mqtt_setting_port.cursor_type(CURSOR_NONE);
            ta_mqtt_setting_port.width(265);
            ta_mqtt_setting_port.border(2, TFT_BLACK);
            ta_mqtt_setting_port.font(fc_minimal_30,TFT_BLACK);

        cont_mqtt_setting_button_form.layout(LAYOUT_ROW_M);
        cont_mqtt_setting_button_form.opa(0);
        btn_mqtt_setting_save.size(170, 60);
        btn_mqtt_setting_save.color(TFT_GREEN);
        btn_mqtt_setting_save.font(fc_minimal_30, TFT_WHITE);
        btn_mqtt_setting_save.onClicked([](GWidget* widget) {

            MEMORY::setFlashMemString(MQTT_SERVER_KEY, ta_mqtt_setting_server.text());
            MEMORY::setFlashMemString(MQTT_TOPIC_KEY, ta_mqtt_setting_topic.text());
            MEMORY::setFlashMemString(MQTT_PORT_KEY, ta_mqtt_setting_port.text());    
            MQTTBROKER::reMqttMemory();
            MQTT.auto_reconnect();
           

            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) { buzzer.beep(1); }

            rect_mqtt_setting_success.hidden(false);
            rect_mqtt_setting_success.size(300,100);
            rect_mqtt_setting_success.color(TFT_WHITE);
            rect_mqtt_setting_success.border(2,TFT_GREEN);
            rect_mqtt_setting_success.corner_radius(5);
                lb_mqtt_setting_success = "Record successfully.";
                lb_mqtt_setting_success.font(prasanmit_30,TFT_BLACK);

             static SoftTimer timer;
                timer.setInterval(2000, [](){
                rect_mqtt_setting_success.hidden(true);
             });
        });

        btn_mqtt_setting_exit.size(170, 60);
        btn_mqtt_setting_exit.color(TFT_RED);
        btn_mqtt_setting_exit.font(fc_minimal_30, TFT_WHITE);
        btn_mqtt_setting_exit.onClicked([](GWidget* widget) {
            bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
            if (BuzzerState) { buzzer.beep(1); }
            mqtt_setting_background.hidden(true);
        });
    }

    
    void desingQrPaymentPage(){
        payment.hidden(true);
        rect_qr_payment.parent(payment);
        rect_qr_payment.size(210,320);
        rect_qr_payment.opa(0);
        rect_qr_payment.align(ALIGN_LEFT,25);
            image_promptpay.align(ALIGN_TOP,0,20);
            qrcode.size(200,200);
            
            qrcode.align(image_promptpay,ALIGN_BOTTOM,0,5); 
        
        }
        

    void desingPricePay(){

        lb_payment_subtitle.font(fc_minimal_40,TFT_BLACK);
        //lb_payment_price = "200";
        lb_payment_price.font(fc_minimal_40,TFT_BLACK);
        lb_payment_price.font(fc_minimal_40,TFT_BLACK);
        lb_payment_title.font(fc_minimal_40,TFT_BLACK);  

        con_payment_Form.parent(payment);
        con_payment_Form.layout(LAYOUT_COL_M);
        con_payment_Form.padding(10,10,10,10,10);
        con_payment_Form.align(ALIGN_TOP_RIGHT,-20,20);
        con_payment_Form.color(TFT_WHITE);
        con_payment_Form.border(2,TFT_BLACK);
        //con_payment_Form.shadow(10);
        //con_payment_Form.corner_radius(5);
        
        btn_payment_back.rounded();
        btn_payment_back.font(fc_minimal_40);
        btn_payment_back.color(TFT_RED);
        btn_payment_back.width(200);
        btn_payment_back.onClicked([](GWidget* widget){  
        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
        if (BuzzerState){buzzer.beep(1);}
            payment.hidden(true);     
        });
    }


    void desingPageThankYou(){
    thank_you.hidden(true);

    thank_you_Form.layout(LAYOUT_COL_M);
    thank_you_Form.opa(0);

    //lb_thank_you_SubTitle.font(fc_minimal_40,TFT_BLACK);
    lb_thank_you.font(fc_minimal_80,TFT_BLACK);
  }

  void designAVDPage(){
    avd_background.hidden(true);
    cont_avd_price_form.layout(LAYOUT_COL_M);
    cont_avd_price_form.padding(10, 10, 10, 10, 10);
    cont_avd_price_form.opa(0);

    cont_avd_price.layout(LAYOUT_ROW_M);
    cont_avd_price.corner_radius(5);
    cont_avd_price.border(2,TFT_COLOR_HEX(0x686D76));
    cont_avd_price.color(TFT_COLOR_HEX(0xEEEEEE));
        lb_avd_price = "PRICE : ";
        lb_avd_price.font(fc_minimal_30, TFT_BLACK);
        ta_avd_price.cursor_type(CURSOR_NONE);
        ta_avd_price.width(260);
        ta_avd_price.border(2, TFT_BLACK);
        ta_avd_price.font(fc_minimal_30,TFT_BLACK);
        ta_avd_price.onValueChanged([](GWidget *widget){
            MEMORY::setFlashMemString(PRICE_KEY, ta_avd_price.text());
        });

    cont_avd_encode.layout(LAYOUT_ROW_M);
    cont_avd_encode.corner_radius(5);
    cont_avd_encode.border(2,TFT_COLOR_HEX(0x686D76));
    cont_avd_encode.color(TFT_COLOR_HEX(0xEEEEEE));
        lb_avd_encode = "ENCODE : ";
        lb_avd_encode.font(fc_minimal_30, TFT_BLACK);
        ta_avd_encode.cursor_type(CURSOR_NONE);
        ta_avd_encode.width(230);
        ta_avd_encode.border(2, TFT_BLACK);
        ta_avd_encode.font(fc_minimal_30,TFT_BLACK);
        ta_avd_encode.onValueChanged([](GWidget *widget){
           MEMORY::setFlashMemString(ENCODE_KEY, ta_avd_encode.text());
        });
    
    cont_avd_ldr.layout(LAYOUT_ROW_M);
    cont_avd_ldr.corner_radius(5);
    cont_avd_ldr.border(2,TFT_COLOR_HEX(0x686D76));
    cont_avd_ldr.color(TFT_COLOR_HEX(0xEEEEEE));
        lb_avd_ldr = "LDR THRESHOLD : ";
        lb_avd_ldr.font(fc_minimal_30, TFT_BLACK);
        ta_avd_ldr.cursor_type(CURSOR_NONE);
        ta_avd_ldr.width(140);
        ta_avd_ldr.border(2, TFT_BLACK);
        ta_avd_ldr.font(fc_minimal_30,TFT_BLACK);
        ta_avd_ldr.onValueChanged([](GWidget *widget){
           MEMORY::setFlashMemString(LDR_THRESHOLD_KEY, ta_avd_ldr.text());
        });

        btn_avd_back.rounded();
        btn_avd_back.font(fc_minimal_40);
        btn_avd_back.color(TFT_RED);
        btn_avd_back.size(350,60);
        btn_avd_back.onClicked([](GWidget* widget){  
        bool BuzzerState = MEMORY::getFlashMemState(BUZZER_KEY);
        if (BuzzerState){buzzer.beep(1);}
            avd_background.hidden(true);     
        });

  }

  void mqttConfigNotify(){
    rect_mqtt_config_notify.hidden(true);
    rect_mqtt_config_notify.size(300,100);
    rect_mqtt_config_notify.color(TFT_WHITE);
    rect_mqtt_config_notify.border(2,TFT_GREEN);
    rect_mqtt_config_notify.corner_radius(5);
    lb_mqtt_config_notify = "MQTT Configurations";
    lb_mqtt_config_notify.font(prasanmit_30, TFT_BLACK);
  }

}