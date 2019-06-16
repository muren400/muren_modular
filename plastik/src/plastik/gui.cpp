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

#include "gui.h"

Gui::Gui(Sequencer *sequencer) {
    this->sequencer = sequencer;

    tft.reset();
    ID = tft.readID();
    tft.begin(ID);
    tft.setRotation(Orientation);

    tft.fillScreen(BLACK);
    printNotes();
}

void Gui::printCursor() {
    for (int i = 0; i < MAXSTEPS; i++) {
        int color = BLACK;
        if (i == sequencer->stepPos) color = WHITE;

        tft.drawRect(0, cursorH * i, cursorW, cursorH, color);
        if (sequencer->subStepLength > 0) {
            tft.drawRect((noteW * sequencer->subSteps[sequencer->subStepPos % sequencer->subStepLength]) + 1, cursorH * sequencer->stepPos, noteW - 6, 1, RED);
        }
    }
}

void Gui::printNote(int x, int y) {
    int color = GREY;
    switch (x) {
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
            color = DARKGREY;
            break;

        default:
            break;
    }
    // if (notes[x][y]) color = WHITE;
    if (sequencer->patterns[sequencer->pattern].notes[y] & 1 << x) color = WHITE;

    tft.fillRect((noteW * x) + 1, (noteH * y) + 1, noteW - 6, noteH - 2, color);
}

void Gui::printInfo() {
    tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);

    tft.setCursor(0, tft.height() - 20);
    tft.setTextSize(2);
    tft.print("P: ");
    tft.print(String(sequencer->pattern + 1));
    tft.print(" L: ");
    tft.print(String(sequencer->patterns[sequencer->pattern].length));
    tft.print(" H: ");
    tft.print(String(sequencer->patterns[sequencer->pattern].hits));
    tft.print(" D: ");
    tft.print(String(sequencer->divider));

    tft.setCursor(tft.width() - 18, tft.height() - 20);
    tft.print("W");
}

void Gui::printNotes() {
    cursorH = (tft.height() - 25) / sequencer->patterns[sequencer->pattern].length;
    cursorW = tft.width();
    noteH = cursorH;

    if (sequencer->mode == MODE_DRUM) {
        noteW = (cursorW / MAXOUTPUTS) + 1;
    } else {
        noteW = (cursorW / MAXNOTES) + 1;
    }

    for (int i = 0; i < sequencer->patterns[sequencer->pattern].length; i++) {
        for (int j = 0; j < MAXNOTES; j++) {
            printNote(j, i);
        }
    }

    printInfo();
}

void Gui::readTouchPanel() {
    static uint8_t touch = 0;

    uint8_t cols = MAXNOTES;
    if (sequencer->mode == MODE_DRUM) {
        cols = MAXOUTPUTS;
    }

    uint16_t xpos, ypos;  //screen coordinates
    tp = ts.getPoint();   //tp.x, tp.y are ADC values

    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!

    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
        if (!touch) {
            touch = 1;

            xpos = map(tp.x, TS_RT, TS_LEFT, 0, tft.width());
            xpos -= 5;
            if (xpos < 0) xpos = 0;

            ypos = map(tp.y, TS_BOT, TS_TOP, 0, tft.height());
            // ypos -= 30;
            if (ypos < 40) ypos = 0;

            if (xpos > tft.width() - 100 && ypos > tft.height() - 30) {
                tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);
                tft.setCursor(0, tft.height() - 20);
                tft.setTextSize(2);
                tft.print("writing...");

                sequencer->writePattern();

                printInfo();
            } else {
                uint8_t xIndex = (uint8_t)((xpos - 10) * cols / (tft.width() - 5));
                uint8_t yIndex = (uint8_t)(ypos * sequencer->patterns[sequencer->pattern].length / (tft.height() - 30));

                if (xIndex >= cols) xIndex = cols - 1;
                if (yIndex >= sequencer->patterns[sequencer->pattern].length) yIndex = sequencer->patterns[sequencer->pattern].length - 1;

                // notes[xIndex][yIndex] = !notes[xIndex][yIndex];
                sequencer->patterns[sequencer->pattern].notes[yIndex] ^= 1 << xIndex;
                printNote(xIndex, yIndex);

                // // monophonic ==> delete other notes
                // if(notes[xIndex][yIndex]){
                //     for(int i=0; i<MAXNOTES; i++){
                //         if(i==xIndex) continue;
                //         if(notes[i][yIndex]){
                //             notes[i][yIndex] = 0;
                //             printNote(i, yIndex);
                //         }
                //     }
                // }
            }
        }
    } else {
        touch = 0;
    }
}