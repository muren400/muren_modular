#include "ClockMultiplier.h"

ClockMultiplier::ClockMultiplier() {
}

ClockMultiplier::ClockMultiplier(int multiplier, int outputPin) : ClockPart(outputPin) {
    this->multiplier = multiplier;
}

void ClockMultiplier::executeStep() {
    if (isInitialized() == false) {
        return;
    }

    setHigh();
    milliSecondsPassed = 0;

    calculateSpeed();
}

void ClockMultiplier::calculateSpeed() {
    clockSpeed = ticksPerStep / multiplier;
    ticksPerStep = 0;
}

void ClockMultiplier::executeTick() {
    pulldown();

    ticksPerStep += 1;

    if (multiplier == 1) {
        return;
    }

    if(milliSecondsPassed >= clockSpeed) {
        setHigh();
        milliSecondsPassed = 0;
    }

    milliSecondsPassed += 1;
}