

void updataTemp();

void flagCheker();
void lcdSenter();

void btnWork();
void encWork();


void init_main(){
        Serial.begin(9600);
        encoder_setup();
        menu = *(initMenu());
        init_Screen(&menu);
        dallas_setup(); 
        buttons_setup();
        setup_Menu(&menu);
        timer_setup();

        mainS = menu.curr;  
}

void main_loop(){
    read_encoder();
    loop_btn();
    flagCheker();

    updataTemp();
    timer_loop();

    btnWork();
    encWork();
}



//______________________________________________________________________________________


void updataTemp(){

    if(REG_FLAG & RELOAD_LCD){
        TempCurH->val->setfloat(TempCurH->val, most_recent_temperature_measurement);
        TempCurC->val->setfloat(TempCurC->val, most_recent_temperature_measurement);
        TempCurF->val->setfloat(TempCurF->val, most_recent_temperature_measurement);

        menu.printScreen(&menu);
        REG_FLAG &= ~(1 << 0);
    }
}


void flagCheker(){

    
}


/*!
    @brief If btn is press check her and clear press to corectabele work
*/
void btnWork(){

    if(pressbtn){
        switch (pressbtn)
        {
        case 0x01:

        break;


        case 0x02:

        break;

        }



        pressbtn = 0;
    }
    
}

void encWork(){

    if(press){
        Screen* curr;

        switch (press){

        case 1:    
            menu.prevLine(&menu);
        break;


        case 2:
            menu.nextLine(&menu);
        break;


        case 5:            
            menu.nextLine(&menu);
        }
        press = 0;
    }


}