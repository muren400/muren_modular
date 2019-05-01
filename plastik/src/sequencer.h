#ifndef SEQUENCER_H
#define SEQUENCER_H

#include <stdint.h>

#include "gui.h"
#include "pattern.h"
#include "encoder.h"

#define MODE_ARP  0
#define MODE_POLY 1
#define MODE_DRUM 2

class Gui;
class Sequencer {
   public:
    Gui* gui;

    uint8_t mode = MODE_DRUM;

    uint8_t gates[MAXOUTPUTS] = {GATE_1, GATE_2, GATE_3, GATE_4};

    // init Encoders
    Encoder encoder1 = Encoder(ENC_1_A, ENC_1_B);
    Encoder encoder2 = Encoder(ENC_2_A, ENC_2_B);
    Encoder encoder3 = Encoder(ENC_3_A, ENC_3_B);
    Encoder encoder4 = Encoder(ENC_4_A, ENC_4_B);

    // Steps
    uint8_t stepPos = 0;
    uint8_t subStepPos = 0;
    uint8_t subSteps[64];
    uint8_t subStepLength = 0;

    // Patterns
    Pattern patterns[MAXPATTERNS];
    uint8_t pattern = 0;

    int printNotesTimer = 0;

    uint8_t divider = 1;
    int8_t _divider = 1;

    Sequencer();

    /**
     * Determines, wether a Step is happening or not
     * returns 1 for yes, 0 for no
     */
    int isStep();

    int getStep();

    int isReset();

    void loadPatterns();

    void writePattern();

    /**
     * Executes one Step in the pattern MODE Arpeggio
     */
    void executeStepArp();

    /**
     * Executes one Step in the pattern MODE Polyphonic
     */
    void executeStepPoly();

    /**
     * Executes one Step in the pattern MODE Drum
     */
    void executeStepDrum();

    /**
     * Executes one Step in the pattern
     */
    void executeStep();

    /**
     * builds the arpeggio subpattern for the current Step
     */
    void buildSubSteps();

    /**
     * Reads the Pins A and B and determines, if on tick has been made
     * return: 0 no tick
     *         1 tick forward
     *        -1 tick backward
     */
    int8_t readEncoder(Encoder *encoder);

    /**
     * Reads all encoders and updates the model accordingly
     */
    void readEncoders();

    /**
     * decreases the printNotesTimer value
     * if 0 is reached, the pattern will be reprinted
     */
    void triggerPrintNotes();

    /**
     * executes on loop iteration
     */
    void doLoop();
};

#endif