/*
 *********************************************************************
 *this file is part of plastik.
 *
 *plastik is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *plastik is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *********************************************************************
*/
#include <MCP4728.h>
#include <Wire.h>

#include "sequencer.h"

Sequencer::Sequencer() {}

void Sequencer::initDAC(){
    Wire.begin();
    dac.attatch(Wire, 22);
    dac.readRegisters();
    dac.selectVref(MCP4728::VREF::INTERNAL_2_8V, MCP4728::VREF::INTERNAL_2_8V, MCP4728::VREF::INTERNAL_2_8V, MCP4728::VREF::INTERNAL_2_8V);
    dac.selectPowerDown(MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM, MCP4728::PWR_DOWN::GND_100KOHM);
    dac.selectGain(MCP4728::GAIN::X1, MCP4728::GAIN::X1, MCP4728::GAIN::X1, MCP4728::GAIN::X1);

    dac.analogWrite(MCP4728::DAC_CH::A, 1000);
    dac.enable(true);
}

/**
 * builds the arpeggio subpattern for the current Step
 */
void Sequencer::buildSubSteps() {
    subStepLength = 0;
    for (int i = 0; i < MAXNOTES; i++) {
        if (patterns[pattern].notes[stepPos] & 1 << i) {
            subSteps[subStepLength] = i;
            subStepLength++;
        }
    }
}

/**
 * Determines, wether a Step is happening or not
 * returns 1 for yes, 0 for no
 */
int Sequencer::isStep() {
    static uint8_t step = 0;
    if (digitalRead(CLOCK) == HIGH) {
        if (!step) {
            step = 1;
            return 1;
        }
    } else {
        step = 0;
    }

    return 0;

    // static int stepTimer = 0;
    // stepTimer--;

    // if (stepTimer < 0) {
    //     stepTimer = 10;
    //     return 1;
    // }

    // return 0;
}

int Sequencer::isReset() {
    static uint8_t step = 0;
    if (digitalRead(RESET) == HIGH || digitalRead(BUTTON_1) == LOW) {
        if (!step) {
            step = 1;
            return 1;
        }
    } else {
        step = 0;
    }

    return 0;
}

int Sequencer::getStep(){
    _divider--;

    if(_divider <= 0){
        _divider = divider;
        return 1;
    }

    return 0;
}

void Sequencer::loadPatterns() {
    for (int i = 0; i < MAXPATTERNS; i++) {
        patterns[i].readPattern(i);
    }
}

void Sequencer::writePattern() {
    patterns[pattern].writePattern(pattern);
}

/**
 * Executes one Step in the pattern MODE Arpeggio
 */
void Sequencer::executeStepArp() {
    subStepPos++;

    // reset substeps
    if (subStepPos >= patterns[pattern].hits) {
        subStepPos = 0;
        stepPos++;
        if (stepPos >= patterns[pattern].length) {
            stepPos = 0;
        }
        // build substeps for next step
        buildSubSteps();
    }

    gui->printCursor();

    int pitch = subSteps[subStepPos % subStepLength];

    pitch *= 300;

    dac.analogWrite(pitch, pitch, pitch, pitch);

    digitalWrite(GATE_1, HIGH);
    digitalWrite(GATE_2, HIGH);
    digitalWrite(GATE_3, HIGH);
    digitalWrite(GATE_4, HIGH);
    delay(1);
    digitalWrite(GATE_1, LOW);
    digitalWrite(GATE_2, LOW);
    digitalWrite(GATE_3, LOW);
    digitalWrite(GATE_4, LOW);
}

/**
 * Executes one Step in the pattern MODE Polyphonic
 */
void Sequencer::executeStepPoly() {
    stepPos++;
    if (stepPos >= patterns[pattern].length) {
        stepPos = 0;
    }

    gui->printCursor();

    int iOutput = 0;
    for (int i = 0; i < MAXNOTES; i++) {
        if (patterns[pattern].notes[stepPos] & 1 << i) {
            digitalWrite(gates[iOutput], HIGH);

            int pitch = i;
            cvs[iOutput] = i * 300;

            iOutput++;
            if (iOutput >= MAXOUTPUTS)
                break;
        }
    }

    dac.analogWrite(cvs[0], cvs[1], cvs[2], cvs[3]);

    delay(1);

    for (int i = 0; i < MAXOUTPUTS; i++) {
        digitalWrite(gates[i], LOW);
    }
}

/**
 * Executes one Step in the pattern MODE Drum
 */
void Sequencer::executeStepDrum() {
    stepPos++;
    if (stepPos >= patterns[pattern].length) {
        stepPos = 0;
    }

    for (int i = 0; i < MAXOUTPUTS; i++) {
        if (patterns[pattern].notes[stepPos] & 1 << i) {
            digitalWrite(gates[i], HIGH);
        }
    }

    delay(1);

    for (int i = 0; i < MAXOUTPUTS; i++) {
        digitalWrite(gates[i], LOW);
    }

    gui->printCursor();
}

/**
 * Executes one Step in the pattern
 */
void Sequencer::executeStep() {
    if(getStep() == 0) return; 

    switch (mode) {
        case MODE_ARP:
            executeStepArp();
            break;
        case MODE_POLY:
            executeStepPoly();
            break;
        case MODE_DRUM:
            executeStepDrum();
            break;
    }
}

/**
 * Reads the Pins A and B and determines, if on tick has been made
 * return: 0 no tick
 *         1 tick forward
 *        -1 tick backward
 */
int8_t Sequencer::readEncoder(Encoder *encoder) {
    uint8_t ret = 0;
    uint8_t iACurrent = digitalRead(encoder->pinA);
    uint8_t iBCurrent = digitalRead(encoder->pinB);
    if (encoder->isRead == 0) {
        if ((encoder->pinALast == HIGH) && iACurrent == LOW && iBCurrent == LOW) {
            ret = 1;
            encoder->isRead = 1;
        } else if ((encoder->pinBLast == HIGH) && iBCurrent == LOW && iACurrent == LOW) {
            ret = -1;
            encoder->isRead = 1;
        }
    }
    encoder->pinALast = iACurrent;
    encoder->pinBLast = iBCurrent;

    if (encoder->pinALast == HIGH && encoder->pinBLast == HIGH) {
        encoder->isRead = 0;
    }

    return ret;
}

/**
 * Reads all encoders and updates the model accordingly
 */
void Sequencer::readEncoders() {
    int8_t enc1Value = readEncoder(&encoder1);
    if (enc1Value != 0) {
        patterns[pattern].length += enc1Value;
        printNotesTimer = 50;
        if (patterns[pattern].length > MAXSTEPS) {
            patterns[pattern].length = MAXSTEPS;
            printNotesTimer = 0;
        } else if (patterns[pattern].length < 1) {
            patterns[pattern].length = 1;
            printNotesTimer = 0;
        }

        gui->printInfo();
    }

    int8_t enc2Value = readEncoder(&encoder2);
    if (enc2Value != 0) {
        patterns[pattern].hits += enc2Value;
        if (patterns[pattern].hits > MAXSTEPS) {
            patterns[pattern].hits = MAXSTEPS;
        } else if (patterns[pattern].hits < 1) {
            patterns[pattern].hits = 1;
        }

        gui->printInfo();
    }

    int8_t enc3Value = readEncoder(&encoder3);
    if (enc3Value != 0) {
        if (enc3Value > 0 || pattern > 0) {
            pattern += enc3Value;
            printNotesTimer = 50;
            if (pattern >= MAXPATTERNS) {
                pattern = MAXPATTERNS - 1;
                printNotesTimer = 0;
            }

            gui->printInfo();
        }
    }

    int8_t enc4Value = readEncoder(&encoder4);
    if (enc4Value != 0) {
        divider += enc4Value;
        if (divider >= MAXDIVIDER) {
            divider = MAXDIVIDER;
        } else if (divider < 1) {
            divider = 1;
        }

        gui->printInfo();
    }
}

/**
 * decreases the printNotesTimer value
 * if 0 is reached, the pattern will be reprinted
 */
void Sequencer::triggerPrintNotes() {
    if (printNotesTimer > 0) {
        printNotesTimer--;

        if (printNotesTimer == 0) {
            gui->tft.fillScreen(BLACK);
            gui->printNotes();
        }
    }
}

/**
 * executes on loop iteration
 */
void Sequencer::doLoop() {
    gui->readTouchPanel();

    if (isReset()) {
        stepPos = patterns[pattern].length;
        _divider = 1;
    }

    if (isStep()) {
        executeStep();
    }

    readEncoders();

    triggerPrintNotes();

    delay(10);
}