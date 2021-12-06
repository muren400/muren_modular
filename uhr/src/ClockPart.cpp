#include "ClockPart.h"

ClockPart::ClockPart() {
}

ClockPart::ClockPart(int outputPin) {
    this->outputPin = outputPin;
    pinMode(outputPin, OUTPUT);
}

void ClockPart::executeStep() {
}

void ClockPart::pulldown() {
    if(pulseDurationCounter == -1) {
        return;
    }
    
    if(pulseDurationCounter == pulseDurationMs) {
        setLow();
        return;
    }

    pulseDurationCounter += 1;
}

void ClockPart::setHigh () {
    digitalWrite(outputPin, HIGH);
    pulseDurationCounter = 0;
}

void ClockPart::setLow () {
    digitalWrite(outputPin, LOW);
    pulseDurationCounter = -1;
}

bool ClockPart::isInitialized() {
    return outputPin > 0;
}