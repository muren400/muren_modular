#ifndef UHR_H
#define UHR_H

#include <Arduino.h>

#include "ClockDivider.h"
#include "ClockMultiplier.h"

#define DIVIDERS_LENGTH 4
#define MULTIPLIERS_LENGTH 4

#define CLOCK_INPUT_PIN 2
#define CLOCK_OUTPUT_PIN_1 3
#define CLOCK_OUTPUT_PIN_2 4
#define CLOCK_OUTPUT_PIN_3 5
#define CLOCK_OUTPUT_PIN_4 6
#define CLOCK_OUTPUT_PIN_5 7
#define CLOCK_OUTPUT_PIN_6 8
#define CLOCK_OUTPUT_PIN_7 9
#define CLOCK_OUTPUT_PIN_8 10

class Uhr {
   private:
    unsigned int milliSecondsPassed = 0;

    ClockDivider dividers[DIVIDERS_LENGTH];
    ClockMultiplier multipliers[MULTIPLIERS_LENGTH];
    int ledOn = 0;

    void createDivider(int index, int divident, int pin);
    void createMultiplier(int index, int divident, int pin);

   public:
    Uhr();
    void initUhr();
    void executeStep();
    void executeTick();
};

#endif