#ifndef PATTERN_H
#define PATTERN_H

#include <stdint.h>

#include "plastik.h"

class Pattern {
   public:
    uint8_t length;
    uint8_t hits;
    uint16_t notes[MAXSTEPS];

    Pattern();
    Pattern(uint8_t length, uint8_t hits);

    void readPattern(uint8_t index);
    void writePattern(uint8_t index);
};

#endif