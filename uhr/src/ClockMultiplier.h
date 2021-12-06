#ifndef CLOCK_MULTIPLIER_H
#define CLOCK_MULTIPLIER_H

#include <Arduino.h>

#include "ClockPart.h"

class ClockMultiplier : ClockPart {
   private:
    int multiplier = 0;
    unsigned int ticksPerStep = 0;
    unsigned int clockSpeed = 0;
    unsigned int milliSecondsPassed = 0;

    void calculateSpeed();

   public:
    ClockMultiplier();
    ClockMultiplier(int multiplier, int outputPin);
    void executeStep();
    void executeTick();
};

#endif