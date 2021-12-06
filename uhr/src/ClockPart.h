#ifndef CLOCK_PART_H
#define CLOCK_PART_H

#include <Arduino.h>

class ClockPart {
   private:
    int outputPin = 0;
    int pulseDurationMs = 20;
    int pulseDurationCounter = 0;

   protected:
    bool isInitialized();

   public:
    ClockPart();
    ClockPart(int outputPin);
    void executeStep();
    void pulldown();
    void setHigh();
    void setLow();
};

#endif