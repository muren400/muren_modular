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

#include "plastik.h"
#include "sequencer.h"

Sequencer sequencer;

void setup(void) {
    sequencer.loadPatterns();
    
    sequencer.gui = new Gui(&sequencer);

    pinMode(CLOCK, INPUT);
    pinMode(RESET, INPUT);

    pinMode(GATE_1, OUTPUT);
    pinMode(GATE_2, OUTPUT);
    pinMode(GATE_3, OUTPUT);
    pinMode(GATE_4, OUTPUT);

    delay(1000);
}

void loop() {
    sequencer.doLoop();
}
