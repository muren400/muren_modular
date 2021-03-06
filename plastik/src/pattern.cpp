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

#include <EEPROM.h>

#include "pattern.h"

Pattern::Pattern() {
    this->length = 8;
    this->hits = 1;
}

Pattern::Pattern(uint8_t length, uint8_t hits) {
    this->length = length;
    this->hits = hits;
}

void Pattern::readPattern(uint8_t index) {
    uint32_t offset = (2 + (MAXSTEPS * 2)) * index;

    for (uint32_t i = 0; i < MAXSTEPS; i++) {
        notes[i] = EEPROM.read(offset + 2 + i * 3);
        notes[i] = notes[i] << 8;
        notes[i] += EEPROM.read(offset + 1 + i * 3);
        notes[i] = notes[i] << 8;
        notes[i] += EEPROM.read(offset + i * 3);
    }

    length = EEPROM.read(offset + MAXSTEPS * 3);

    // no pattern
    if (length > MAXSTEPS) {
        length = MAXSTEPS;

        // reset pattern
        for (int i = 0; i < MAXSTEPS; i++) {
            notes[i] = 0;
        }
    }

    hits = EEPROM.read(offset + 1 + MAXSTEPS * 3);
    if (hits > MAXSTEPS) hits = MAXSTEPS;
}

void Pattern::writePattern(uint8_t index) {
    uint32_t offset = (2 + (MAXSTEPS * 3)) * index;  // 2 bytes for length and hits, 3 bytes per step

    for (uint32_t i = 0; i < MAXSTEPS; i++) {
        EEPROM.write(offset + i * 3, notes[i]);
        EEPROM.write(offset + 1 + i * 3, notes[i] >> 8);
        EEPROM.write(offset + 2 + i * 3, notes[i] >> 16);
    }

    EEPROM.write(offset + MAXSTEPS * 3, length);
    EEPROM.write(offset + 1 + MAXSTEPS * 3, hits);
}