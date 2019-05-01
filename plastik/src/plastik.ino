#include "plastik.h"
#include "sequencer.h"

Sequencer sequencer;

void setup(void) {
    sequencer.loadPatterns();
    
    sequencer.gui = new Gui(&sequencer);

    pinMode(CLOCK, INPUT);
    pinMode(RESET, INPUT);

    pinMode(GATE_1, OUTPUT);
    pinMode(GATE_2, OUTPUT);
    pinMode(GATE_3, OUTPUT);
    pinMode(GATE_4, OUTPUT);

    delay(1000);
}

void loop() {
    sequencer.doLoop();
}
