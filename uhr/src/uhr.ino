#include "Uhr.h"

#define AUTOMATIC 0

Uhr uhr;

int autoStepDuration = 1000;
int autoStepMilliseconds = 0;

void setup() {
    uhr.initUhr();
    pinMode(13, OUTPUT);
    attachInterrupt(digitalPinToInterrupt(CLOCK_INPUT_PIN), onPinInterrupt, RISING);
    initTimerIntertupt();
}

void initTimerIntertupt() {
    cli();

    TCCR0A = 0;  // set entire TCCR0A register to 0
    TCCR0B = 0;  // same for TCCR0B
    TCNT0 = 0;   // initialize counter value to 0
    // set compare match register for 1khz increments
    OCR0A = 249;  // = (16*10^6) / (1000*64) - 1 (must be <256)
    // turn on CTC mode
    TCCR0A |= (1 << WGM01);
    // Set CS01 and CS00 bits for 64 prescaler
    TCCR0B |= (1 << CS01) | (1 << CS00);
    // enable timer compare interrupt
    TIMSK0 |= (1 << OCIE0A);

    sei();
}

ISR(TIMER0_COMPA_vect) {  // timer0 interrupt 1kHz
    uhr.executeTick();

    if (AUTOMATIC == 0) {
        return;
    }

    autoStepMilliseconds++;

    if (autoStepMilliseconds < autoStepDuration) {
        return;
    }

    autoStepMilliseconds = 0;
    uhr.executeStep();
}

void onPinInterrupt() {
    uhr.executeStep();
}

void loop() {
}