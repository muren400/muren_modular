#include "ClockDivider.h"

ClockDivider::ClockDivider() {
}

ClockDivider::ClockDivider(int divident, int outputPin) : ClockPart(outputPin) {
    this->divident = divident;
}

void ClockDivider::executeStep() {
    if(isInitialized() == false) {
        return;
    }

    if (isFirstStep()) {
        setHigh();
    } else {
        setLow();
    }

    incrementStep();
}

bool ClockDivider::isFirstStep() {
    return stepCount == 0;
}

void ClockDivider::incrementStep() {
    stepCount++;

    if (stepCount >= divident) {
        stepCount = 0;
    }
}