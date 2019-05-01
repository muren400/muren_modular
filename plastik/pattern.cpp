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
    int offset = (2 + (MAXSTEPS * 2)) * index;

    for (int i = 0; i < MAXSTEPS; i++) {
        notes[i] = EEPROM.read(offset + 1 + i * 2);
        notes[i] = notes[i] << 8;
        notes[i] += EEPROM.read(offset + i * 2);
    }

    length = EEPROM.read(offset + MAXSTEPS);

    // no pattern
    if (length > MAXSTEPS) {
        length = MAXSTEPS;

        // reset pattern
        for (int i = 0; i < MAXSTEPS; i++) {
            notes[i] = 0;
        }
    }

    hits = EEPROM.read(offset + 1 + MAXSTEPS);
    if (hits > MAXSTEPS) hits = MAXSTEPS;
}

void Pattern::writePattern(uint8_t index) {
    int offset = (2 + (MAXSTEPS * 2)) * index;  // 2 bytes for length and hits, 2 bytes per step

    for (int i = 0; i < MAXSTEPS; i++) {
        EEPROM.write(offset + i * 2, notes[i] & 0xf);
        EEPROM.write(offset + 1 + i * 2, notes[i] >> 8);
    }

    EEPROM.write(offset + MAXSTEPS, length);
    EEPROM.write(offset + 1 + MAXSTEPS, hits);
}