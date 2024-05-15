#include <Arduino.h>
#include <Menulib.h>


#include "dependenci/pins.h"
#include "dependenci/btns.h"
// #include "dependenci/dallas_sensor.h"
#include "dependenci/led.h"
#include "dependenci/menu.h"
#include "dependenci/encoder.h"

int encderVal = 0x00;
Menu* menu ;

Storage* storage ;
void setup() {
    Serial.begin(9600);
    menu = initMenu();

    menu->newScreen(menu, "Settings", "Settings");
    
    menu->addLine(menu, "Fan :", "FAN");
    menu->addLine(menu, "Ten :", "TEN");
    menu->addLine(menu, "Cool :", "COOL");

    storage = initStore();



    storage->inStore(menu->currentScreen, storage);


    // buttons_setup();
    // encoder_setup();
    // relay_setup();
  
}

void loop() {

    
    delay(1000);

    menu->nextLine(menu);
    // delay(1000);
    String var = menu->getName(menu);
    Liner* lin = storage->finder(storage, menu->getName(menu));

    // delay(1000);
    lin->val ++;

    storage->allUp(storage);
    // delay(1000);


//   if(encderVal){
//     switch (encderVal){
//     case 0x01:
//     break;

//     case 0x02:
//     break;

//     case 0x03:
        
//     break;
    
//     default:
//       break;
//     }
//   }

}

