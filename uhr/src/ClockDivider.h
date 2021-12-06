#ifndef CLOCK_DIVIDER_H
#define CLOCK_DIVIDER_H

#include <Arduino.h>
#include "ClockPart.h"

class ClockDivider : public ClockPart {
   private:
    int divident = 1;
    int stepCount = 0;

    bool isFirstStep();
    void incrementStep();

   public:
    ClockDivider();
    ClockDivider(int divident, int outputPin);
    void executeStep();
};

#endif