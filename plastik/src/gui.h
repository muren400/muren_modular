/*
 *********************************************************************
 *this file is part of plastik.
 *
 *plastik is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *plastik is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *********************************************************************
*/

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

    uint16_t notes[12][16];

    int16_t cursorH;
    int16_t cursorW;

    int16_t noteH;
    int16_t noteW;

    /**
     * Constructor
     */
    Gui(Sequencer* sequencer);

    /**
     * prints the current step position on the screen
     * visualized as an unfilled rectangle around the current notes
     */
    void printCursor();

    /**
     * 
     */
    void printNote(int x, int y, bool all);

    /**
     * prints the pattern stats at the bottom of the screen
     */
    void printInfo();

    /**
     * 
     */
    void printNotes(bool all);

    /**
     * 
     */
    void printRepeatBar();

    /**
     * 
     */
    void printNewPattern();

    /**
     * 
     */
    void printText(char* text, int size, int x, int y, int color);

    /**
     * 
     */
    void readTouchPanel();
};

#endif