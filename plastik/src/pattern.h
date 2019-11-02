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

#ifndef PATTERN_H
#define PATTERN_H

#include <stdint.h>

#include "plastik.h"

class Pattern {
   public:
    uint8_t length;
    uint8_t hits;
    uint32_t notes[MAXSTEPS];

    Pattern();
    Pattern(uint8_t length, uint8_t hits);

    void readPattern(uint8_t index);
    void writePattern(uint8_t index);
};

#endif