// the regular Adafruit "TouchScreen.h" library only works on AVRs

// different mcufriend shields have Touchscreen on different pins
// and rotation.
// Run the TouchScreen_Calibr_native sketch for calibration of your shield

#include <MCUFRIEND_kbv.h>
MCUFRIEND_kbv tft;  // hard-wired for UNO shields anyway.
#include <TimerOne.h>
#include <TouchScreen.h>
#include <math.h>

#include "TouchSequenser.h"

char *name = "Please Calibrate.";            //edit name of shield
const int XP = 7, XM = A1, YP = A2, YM = 6;  //ID=0x6814
const int TS_LEFT = 907, TS_RT = 136, TS_TOP = 942, TS_BOT = 139;

TouchScreen ts = TouchScreen(XP, YP, XM, YM, 300);
TSPoint tp;

int16_t CURSORH;
int16_t CURSORW;

int16_t NOTEH;
int16_t NOTEW;

uint16_t ID;
uint8_t Orientation = 2;  //PORTRAIT

uint8_t stepPos = 0;
uint8_t subStepPos = 0;
uint8_t subSteps[64];
uint8_t subStepLength = 0;

uint8_t notes[MAXNOTES][MAXSTEPS];

uint8_t touch = 0;

uint8_t step = 0;

uint8_t length = 16;
uint8_t steps = 1;

void buildSubSteps(){
    subStepLength = 0;
    for(int i=0; i<MAXNOTES; i++){
        if(notes[i][stepPos]){
            subSteps[subStepLength] = i;
            subStepLength++;
        }
    }
}

void printCursor() {
    for (int i = 0; i < MAXSTEPS; i++) {
        int color = BLACK;
        if (i == stepPos) color = WHITE;

        tft.drawRect(0, CURSORH * i, CURSORW, CURSORH, color);
        if(subStepLength > 0){
            tft.drawRect((NOTEW * subSteps[subStepPos%subStepLength]) + 1, CURSORH * stepPos, NOTEW - 6, 1, RED);
        }
    }
}

void printNote(int x, int y) {
    int color = GREY;
    switch (x) {
        case 1:
        case 3:
        case 6:
        case 8:
        case 10:
            color = DARKGREY;
            break;

        default:
            break;
    }
    if (notes[x][y]) color = WHITE;

    tft.fillRect((NOTEW * x) + 1, (NOTEH * y) + 1, NOTEW - 6, NOTEH - 2, color);
}

void printInfo(){
    tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);
    
    tft.setCursor(0, tft.height() - 20);
    tft.setTextSize(2);
    tft.print("P: 1 ");
    tft.print("L: ");
    tft.print(String(length));
    tft.print(" S: ");
    tft.print(String(steps));


    tft.setCursor(tft.width() - 18, tft.height() - 20);
    tft.print("W");
}

void printNotes() {
    CURSORH = (tft.height() - 25) / length;
    CURSORW = tft.width();
    NOTEH = CURSORH;
    NOTEW = (CURSORW / MAXNOTES) + 1;

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < MAXNOTES; j++) {
            printNote(j, i);
        }
    }

    printInfo();
}

void writeMemory() {
    tft.fillRect(0, tft.height() - 20, tft.width(), 30, BLACK);
    tft.setCursor(0, tft.height() - 20);
    tft.print("writing...");
    delay(3000);
    printInfo();
}

int isStep() {
    if (digitalRead(12) == HIGH) {
        if (!step) {
            step = 1;
            return 1;
        }
    } else {
        step = 0;
    }

    return 0;
}

void executeStep() {
    subStepPos++;

    int _steps = pow(2,steps) + 1;

    if(subStepPos >= _steps){
        subStepPos = 0;
        stepPos++;
        if (stepPos >= length){
            stepPos = 0;
        }
        buildSubSteps();
    }

    printCursor();

    int pitch = subSteps[subStepPos%subStepLength];

    pitch *= 8;
    analogWrite(CV, pitch);

    digitalWrite(GATE, HIGH);
    delay(1);
    digitalWrite(GATE, LOW);
}

void readDials() {
    int iLength = 1 + analogRead(LENGTH) / 32;

    if (iLength > MAXSTEPS) {
        iLength = MAXSTEPS;
    }

    if (iLength != length) {
        length = iLength;
        tft.fillScreen(BLACK);
        printNotes();
    }

    int iSteps = 1 + analogRead(STEPS) / 100;

    if(iSteps != steps){
        steps = iSteps;
        printInfo();
    }
}

void setup(void) {
    uint16_t tmp;

    tft.reset();
    ID = tft.readID();
    tft.begin(ID);
    tft.setRotation(Orientation);

    tft.fillScreen(BLACK);
    printNotes();

    pinMode(CLOCK, INPUT);
    pinMode(GATE, OUTPUT);
    pinMode(CV, OUTPUT);

    // tft.setCursor(0, CURSORH * MAXSTEPS + 10);
    // tft.setTextSize(2);
    // tft.print("pattern: 1");

    // tft.setCursor(tft.width() - 120, CURSORH * MAXSTEPS + 10);
    // tft.print("write");

    // Timer1.initialize(50000);
    // Timer1.attachInterrupt(executeStep);

    delay(1000);
}

void loop() {
    uint16_t xpos, ypos;  //screen coordinates
    tp = ts.getPoint();   //tp.x, tp.y are ADC values

    // if sharing pins, you'll need to fix the directions of the touchscreen pins
    pinMode(XM, OUTPUT);
    pinMode(YP, OUTPUT);
    // we have some minimum pressure we consider 'valid'
    // pressure of 0 means no pressing!

    if (tp.z > MINPRESSURE && tp.z < MAXPRESSURE) {
        if (!touch) {
            touch = 1;

            xpos = map(tp.x, TS_LEFT, TS_RT, 0, tft.width());
            ypos = map(tp.y, TS_TOP, TS_BOT, 0, tft.height());

            if (xpos > tft.width() - 100 && ypos > tft.height() - 30) {
                writeMemory();
            } else {
                uint8_t xIndex = (uint8_t)(xpos * MAXNOTES / (tft.width()-25));
                uint8_t yIndex = (uint8_t)(((ypos + 10) * length) / (tft.height() - 25));

                if (xIndex >= MAXNOTES) xIndex = MAXNOTES - 1;
                if (yIndex >= length) yIndex = length - 1;

                notes[xIndex][yIndex] = !notes[xIndex][yIndex];
                printNote(xIndex, yIndex);

                // // monophonic ==> delete other notes
                // if(notes[xIndex][yIndex]){
                //     for(int i=0; i<MAXNOTES; i++){
                //         if(i==xIndex) continue;
                //         if(notes[i][yIndex]){
                //             notes[i][yIndex] = 0;
                //             printNote(i, yIndex);
                //         }
                //     }
                // }
            }
        }
    } else {
        touch = 0;
    }

    if (isStep()) {
        executeStep();
    }

    readDials();

    delay(10);
}
