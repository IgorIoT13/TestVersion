#ifndef MENU_H
#define MENU_H

#include <Menulib.h>

Menu* menu ;
Screen* testScreen;

Line* Fan;
Line* Ten;
Line* Cool;

typedef struct MData{

    String name;
    String text;
    int valuer;

//    Line* line;
//    Menu* line;

//    mdata* next;
//    mdata* prev;

//    String (*getString) (mdata* data);
//    void (*NewLine) (mdata* data, String name, String text, int val);

} Mdata, mdata, MDATA, MData;

String getString(mdata* data);

void createNewLineData(mdata* data, String name, String text, int val);

MData* initMData(Menu* menu, String name, String text, int val){
    Mdata* obj = new Mdata;

//    if(obj){
//        obj->getString = getString;
//        obj->NewLine = createNewLineData;
//    }

}

#endif