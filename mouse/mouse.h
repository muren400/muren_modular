/*morsecode generator*/
#include "pitches.h"

//define buttons
#define RIGHT 676
#define LEFT 479
#define UP 131
#define DOWN 762
#define SELECT 505

//define audio output pin
#define AUDIOOUT 6
#define GATE 7
#define CV 10
#define SENSORPIN A0
#define SCALE A1
#define TRANSPOSE A6
#define LENGTH A2
#define CURSOR A3
#define DIAL A4
#define SYNC A5

#define MIDI_CLOCK 0xf8;
#define MIDI_START 0xfa;
#define MIDI_STOP 0xfc;

//define headers
void translateToMorse(char sign);
void playSound();
void menuFunction();
void translatingText();
void waitForNTicks(int n);
void doStep();
void translateToMorse2(char sign);
byte powTwo(int e);
void printText();

/*struct Scale { 
  char name[20]; 
  unsigned char notes[12]; 
  unsigned char length;
};*/
