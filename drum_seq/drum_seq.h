#ifndef _STEPSEQH_
#define _STEPSEQH_

#define PIN_RS 12
#define PIN_EN 11
#define PIN_D4 5
#define PIN_D5 4
#define PIN_D6 3
#define PIN_D7 8

#define PIN_DRUM_1 10
#define PIN_DRUM_2 9
#define PIN_DRUM_3 7
#define PIN_DRUM_4 6
#define PIN_SYNC 2

#define PIN_POT_DIAL_SEQUENCE A0
#define PIN_POT_DIAL_LEN A1
#define PIN_POT_DIAL_X A2
#define PIN_POT_DIAL_Y A3

#define PIN_SW_GATE A7
#define PIN_SW_NOTE A6
#define PIN_SW_RESET A5
#define PIN_SW_SAVE A4

#define SEQUENCE_MAX_LEN 16

#define BUTTON_TRESH 20

#define DRUM_1 1<<0
#define DRUM_2 1<<1
#define DRUM_3 1<<2
#define DRUM_4 1<<3

#define MAX_DRUMS 4

#endif