#include "Arduino.h"

//MATRIX
#define DATAIN 8
#define LOAD 3
#define CLOCK 4
#define MAXINUSE 1

int powTwo(byte n);
void convert(byte mBuff1[][8], byte mBuff2[][8], byte values[], int gateX, int gateY);
void putByte(byte data);
void maxSingle( byte reg, byte col);