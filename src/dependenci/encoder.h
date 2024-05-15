#include <Arduino.h>
#include <EncButton.h>
#include <PIDController.h>


EncButton en(CLK, DT, SW);
PIDController pid;

int set_temperature = 1;
int clockPin; 
int clockPinState;
float debounce = 0;
int encoder_btn_count = 0;
float temperature_value_c = 0.0;


void encoder_setup(){
  pinMode(mosfet_pin, OUTPUT); 
  pid.begin();          
  pid.setpoint(150);  
  pid.tune(__Kp, __Ki,__Kd);  
  pid.limit(0, 255);    
  en.setEncType(EB_STEP4_LOW);
  en.setBtnLevel(HIGH);
}


int read_encoder(){

    if(en.leftH() && en.press()){
      return 0x01;
    }
    if(en.rightH() && en.press()){
      return 0x02;
    }

    if (en.leftH()) {
        return 0x03; 
    }
    if(en.rightH()){
        return 0x04;
    }
    if (en.press())  
    {
        return 0x05;
    }

    return 0x00;
}
