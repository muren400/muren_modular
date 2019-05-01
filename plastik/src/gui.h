#ifndef GUI_H
#define GUI_H

#include <MCUFRIEND_kbv.h>
#include <TouchScreen.h>
#include <stdint.h>

#include "plastik.h"
#include "sequencer.h"

class Sequencer;
class Gui {
   public:
    Sequencer* sequencer;

    // init Touchscreen and TFT
    char* name = "Please Calibrate.";            //edit name of shield
    const int XP = 7, XM = A1, YP = A2, YM = 6;  //ID=0x6814
    const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

    MCUFRIEND_kbv tft;
    TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
    TSPoint tp;

    uint16_t ID;
    uint8_t Orientation = 0;

    int16_t cursorH;
    int16_t cursorW;

    int16_t noteH;
    int16_t noteW;

    Gui(Sequencer *sequencer);

    void printCursor();
    void printNote(int x, int y);
    void printInfo();
    void printNotes();

    void readTouchPanel();
};

#endif