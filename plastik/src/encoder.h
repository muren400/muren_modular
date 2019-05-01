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