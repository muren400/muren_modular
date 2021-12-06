#include "Uhr.h"

Uhr::Uhr() {
}

void Uhr::initUhr() {
    pinMode(CLOCK_INPUT_PIN, INPUT);

    createMultiplier(0, 1, CLOCK_OUTPUT_PIN_1);
    createMultiplier(1, 3, CLOCK_OUTPUT_PIN_2);
    createMultiplier(2, 4, CLOCK_OUTPUT_PIN_3);
    createMultiplier(3, 8, CLOCK_OUTPUT_PIN_4);

    createDivider(0, 2, CLOCK_OUTPUT_PIN_5);
    createDivider(1, 3, CLOCK_OUTPUT_PIN_6);
    createDivider(2, 4, CLOCK_OUTPUT_PIN_7);
    createDivider(3, 8, CLOCK_OUTPUT_PIN_8);
}

void Uhr::createDivider(int index, int divident, int pin) {
    dividers[index] = ClockDivider(divident, pin);
}

void Uhr::createMultiplier (int index, int multiplier, int pin) {
    multipliers[index] = ClockMultiplier(multiplier, pin);
}

void Uhr::executeStep() {
    if(milliSecondsPassed < 50) {
        return;
    }

    milliSecondsPassed = 0;

    for (int i = 0; i < DIVIDERS_LENGTH; i++) {
        dividers[i].executeStep();
    }

    for (int i = 0; i < MULTIPLIERS_LENGTH; i++) {
        multipliers[i].executeStep();
    }

    ledOn = !ledOn;
    
    if (ledOn) {
        digitalWrite(13, HIGH);
    } else {
        digitalWrite(13, LOW);
    }
}

void Uhr::executeTick() {
    milliSecondsPassed += 1;

    for (int i = 0; i < MULTIPLIERS_LENGTH; i++) {
        multipliers[i].executeTick();
    }

    for (int i = 0; i < DIVIDERS_LENGTH; i++) {
        dividers[i].pulldown();
    }
}
