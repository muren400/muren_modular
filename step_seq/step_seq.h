#ifndef _STEPSEQH_
#define _STEPSEQH_

#define PIN_RS 12
#define PIN_EN 11
#define PIN_D4 5
#define PIN_D5 4
#define PIN_D6 3
#define PIN_D7 8

#define PIN_CV 6
#define PIN_GATE 7
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

byte ten[8] = {
  B10010,
  B10101,
  B10101,
  B10101,
  B10101,
  B10101,
  B10010,
};

byte eleven[8] = {
  B01001,
  B11011,
  B01001,
  B01001,
  B01001,
  B01001,
  B01001,
};

byte twelve[8] = {
  B10010,
  B10101,
  B10001,
  B10010,
  B10100,
  B10100,
  B10111,
};

#endif