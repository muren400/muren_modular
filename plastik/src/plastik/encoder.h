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

#ifndef ENCODER_H
#define ENCODER_H

#include <stdint.h>

class Encoder {
   public:
    uint8_t pinA;
    uint8_t pinB;
    
    uint8_t pinALast = 1;
    uint8_t pinBLast = 1;

    uint8_t isRead = 0;

    Encoder();
    Encoder(uint8_t pinA, uint8_t pinB);
};

#endif