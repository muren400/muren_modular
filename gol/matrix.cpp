#if defined(ARDUINO) && ARDUINO >= 100
#include "Arduino.h"
#else
#include "WProgram.h"
#endif

#include "matrix.h"

int powTwo(byte n){

	if(n==0){
    return 1;
  }

  int two = 2;
  for (int i = 1; i < n; ++i){
    two *= 2;
  }

  return two;
}

void convert(byte mBuff1[][8], byte mBuff2[][8], byte values[], int gateX, int gateY){
  for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
      mBuff2[j][i] = mBuff1[j][i];
    }
  }

  mBuff2[gateX][gateY] = 1;

  for (int i = 0; i < 8; ++i){
    values[i] = 0;
    for (int j = 0; j < 8; ++j){
      values[i] += mBuff2[j][i]*powTwo(j);
    }
  }
}

void putByte(byte data){
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite(CLOCK, LOW);   // tick
    if (data & mask){            // choose bit
      digitalWrite(DATAIN, HIGH);// send 1
    }else{
      digitalWrite(DATAIN, LOW); // send 0
    }
    digitalWrite(CLOCK, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}

void maxSingle( byte reg, byte col){
  digitalWrite(LOAD, LOW);       // begin     
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data   
  digitalWrite(LOAD, LOW);       // and load da stuff
  digitalWrite(LOAD,HIGH); 
}