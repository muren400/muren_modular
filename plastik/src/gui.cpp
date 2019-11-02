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
    printNotes(true);

    Serial.begin(9600);
}

void Gui::printCursor() {
    static int lastPosition = 0;

    // remove the old cursor
    tft.drawRect(0, cursorH * lastPosition, cursorW, cursorH, BLACK);

    // print the new cursor
    tft.drawRect(0, cursorH * sequencer->stepPos, cursorW, cursorH, WHITE);

    // draw individual note cursors for arpeggios
    if (sequencer->subStepLength > 0) {
        tft.drawRect((noteW * sequencer->subSteps[sequencer->subStepPos % sequencer->subStepLength]) + 1, cursorH * sequencer->stepPos, noteW - 6, 1, RED);
    }

    // remember current position for next function call
    lastPosition = sequencer->stepPos;

    // for (int i = 0; i < MAXSTEPS; i++) {
    //     int color = BLACK;
    //     if (i == sequencer->stepPos) color = WHITE;

    //     tft.drawRect(0, cursorH * i, cursorW, cursorH, color);
    //     if (sequencer->subStepLength > 0) {
    //         tft.drawRect((noteW * sequencer->subSteps[sequencer->subStepPos % sequencer->subStepLength]) + 1, cursorH * sequencer->stepPos, noteW - 6, 1, RED);
    //     }
    // }
}

void Gui::printInfo() {
    static uint8_t pattern = 0;
    static uint8_t length = 0;
    static uint8_t hits = 0;
    static uint8_t divider = 0;

    // tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);

    tft.setTextSize(2);

    int xPos = 0;
    int yPos = tft.height() - 20;

    // tft.setCursor(xPos, tft.height() - 20);
    // tft.print("P: ");

    printText("P: ", 2, xPos, yPos, WHITE);

    xPos += 30;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(BLACK);
    // tft.print(String(pattern));
    printText(String(pattern), -1, xPos, yPos, BLACK);
    pattern = sequencer->pattern + 1;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(WHITE);
    // tft.print(String(pattern));
    printText(String(pattern), -1, xPos, yPos, WHITE);

    xPos += 40;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.print("L: ");
    printText("L: ", -1, xPos, yPos, WHITE);

    xPos += 30;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(BLACK);
    // tft.print(String(length));
    printText(String(length), -1, xPos, yPos, BLACK);
    length = sequencer->patterns[sequencer->pattern].length;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(WHITE);
    // tft.print(String(length));
    printText(String(length), -1, xPos, yPos, WHITE);

    xPos += 40;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.print("H: ");
    printText("H: ", -1, xPos, yPos, WHITE);

    xPos += 30;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(BLACK);
    // tft.print(String(hits));
    printText(String(hits), -1, xPos, yPos, BLACK);
    hits = sequencer->patterns[sequencer->pattern].hits;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(WHITE);
    // tft.print(String(hits));
    printText(String(hits), -1, xPos, yPos, WHITE);

    xPos += 40;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.print("D: ");
    printText("D: ", -1, xPos, yPos, WHITE);

    xPos += 30;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(BLACK);
    // tft.print(String(divider));
    printText(String(divider), -1, xPos, yPos, BLACK);
    divider = sequencer->divider;
    // tft.setCursor(xPos, tft.height() - 20);
    // tft.setTextColor(WHITE);
    // tft.print(String(divider));
    printText(String(divider), -1, xPos, yPos, WHITE);

    // tft.setCursor(tft.width() - 18, tft.height() - 20);
    // tft.print("W");
    printText("W: ", -1, tft.width() - 18, yPos, WHITE);
}

void Gui::printNote(int x, int y, bool all) {
    uint8_t lastValue = notes[x][y];

    uint32_t bitMask = 3;
    bitMask = bitMask << (x * 2);
    uint32_t currentStep = sequencer->patterns[sequencer->pattern].notes[y];
    uint8_t currentNote = (currentStep & bitMask) >> (x * 2);

    notes[x][y] = currentNote;
    uint16_t newValue = notes[x][y];

    if (lastValue == newValue && all == false)
        return;

    int color = DARKERGREY;
    switch (x) {
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
            color = ALMOSTBLACK;
            break;

        default:
            break;
    }

    // if (newValue == 1) color = WHITE;

    switch (newValue) {
        case 1:
            color = PINK;
            break;

        case 2:
            color = WHITE;
            break;

        case 3:
            color = MINT;

        default:
            break;
    }

    tft.fillRect((noteW * x) + 1, (noteH * y) + 1, noteW - 6, noteH - 2, color);
}

void Gui::printNotes(bool all) {
    cursorH = (tft.height() - 25) / MAXSTEPS;
    cursorW = tft.width();
    noteH = cursorH;

    if (sequencer->mode == MODE_DRUM) {
        noteW = (cursorW / MAXOUTPUTS) + 1;
    } else {
        noteW = (cursorW / MAXNOTES) + 1;
    }

    for (int i = 0; i < MAXSTEPS; i++) {
        for (int j = 0; j < MAXNOTES; j++) {
            printNote(j, i, all);
        }
    }

    printRepeatBar();
    printInfo();
}

void Gui::printRepeatBar() {
    static uint8_t lastPosition = MAXSTEPS;
    tft.drawFastHLine(0, (noteH * lastPosition) - 1, tft.width(), BLACK);
    tft.drawFastHLine(0, (noteH * lastPosition), tft.width(), BLACK);

    uint8_t positon = sequencer->patterns[sequencer->pattern].length;
    tft.drawFastHLine(0, (noteH * positon) - 1, tft.width(), CYAN);
    tft.drawFastHLine(0, (noteH * positon), tft.width(), CYAN);

    lastPosition = positon;
}

void Gui::printText(char *text, int size, int x, int y, int color) {
    if(size > 0){
        tft.setTextSize(size);
    }

    if(color >= 0){
        tft.setTextColor(color);
    }
    
    tft.setCursor(x, y);
    tft.print(text);
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

                tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);
                printInfo();
            } else {
                uint32_t xIndex = (uint32_t)((xpos - 10) * cols / (tft.width() - 5));
                uint32_t yIndex = (uint32_t)(ypos * MAXSTEPS / (tft.height() - 30));

                Serial.print(xIndex);
                Serial.print(" ");

                if (xIndex >= cols) xIndex = cols - 1;
                if (yIndex >= MAXSTEPS) yIndex = MAXSTEPS - 1;

                uint32_t bitMask = 3;
                bitMask = bitMask << (xIndex * 2);

                Serial.print(bitMask);
                Serial.print(" ");

                uint32_t currentStep = sequencer->patterns[sequencer->pattern].notes[yIndex];
                uint32_t currentNote = (currentStep & bitMask) >> (xIndex * 2);

                Serial.print(currentNote);
                Serial.print(" => ");

                currentNote++;

                if (currentNote > 3)
                    currentNote = 0;

                Serial.print(currentNote);
                Serial.print(" ");

                currentStep &= ~bitMask;

                Serial.print(currentNote << (xIndex * 2));
                Serial.print(" ");

                currentStep += currentNote << (xIndex * 2);

                Serial.print(currentStep);
                Serial.print(" ");

                sequencer->patterns[sequencer->pattern].notes[yIndex] = currentStep;

                // sequencer->patterns[sequencer->pattern].notes[yIndex] ^= 1 << xIndex;
                printNote(xIndex, yIndex, false);

                Serial.print("\n");
            }
        }
    } else {
        touch = 0;
    }
}