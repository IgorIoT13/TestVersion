#include <Arduino.h>
#include <Menulib.h>
#include <iostream>
#include <string>

#include "dependenci/pins.h"
#include "dependenci/btns.h"
#include "dependenci/dallas_sensor.h"
#include "dependenci/led.h"
#include "dependenci/menuControl/menu.h"
#include "dependenci/encoder.h"

int encderVal = 0x00;
String namer;
Line* currL;
String currS, currR;
int* currI;
String fan, ten, col;
int fani, teni, coli;
String fanR, tenR, colR;

void setup(void) {

    menu = initMenu();
    testScreen = menu->newScreen(menu, "Setting", "Test");

    fan = "FAN: ";
    ten = "TEN: ";
    col = "CO0L: ";



    Fan  =  menu->addLine(menu, "FAN 60%", "FAN");
    Ten  =  menu->addLine(menu, "TEN 42%", "TEN");
    Cool =  menu->addLine(menu, "COOL 100%", "COOL");

  // buttons_setup();
   encoder_setup();
  // relay_setup();'
  
}

void loop(void) {

  if(encderVal){
    switch (encderVal){
    case 0x01:
        menu->prevLine(menu);
    break;

    case 0x02:
        menu->nextLine(menu);
    break;

    case 0x03:
        namer = menu->getName(menu);
        if(namer == "FAN"){
            currL = Fan;
            currS = fan;
            currI = &fani;

        }else if(namer == "TEN"){
            currL = Ten;
            currS = ten;
            currI = &teni;
        }else{
            currL = Cool;
            currS = col;
            currI = &coli;
        }

        while (encderVal != 0x04){
            encderVal = read_encoder();
            switch (encderVal){
                case 0x01:
                    currI --;
                break;

                case 0x02:
                    currI ++;
                break;

                default:
                break;
            }
            currR = currS ;
            currR += String(*currI);
            currL->content = currR;
        }
        
        
    break;
    
    default:
      break;
    }
  }
}

