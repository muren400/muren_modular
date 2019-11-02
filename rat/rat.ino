#include "pitches.h"

byte counter = 0;

byte dataIn = 2;
byte load = 3;
byte clock = 4;

byte verticalValue = 0;
byte gatePosition1 = 3;
byte gatePosition2 = 6;

byte cv = 0;

int maxInUse = 4;    //change this variable to set how many MAX7219's you'll use

int e = 0;           // just a variable

// define max7219 registers
byte max7219_reg_noop        = 0x00;
byte max7219_reg_digit0      = 0x01;
byte max7219_reg_digit1      = 0x02;
byte max7219_reg_digit2      = 0x03;
byte max7219_reg_digit3      = 0x04;
byte max7219_reg_digit4      = 0x05;
byte max7219_reg_digit5      = 0x06;
byte max7219_reg_digit6      = 0x07;
byte max7219_reg_digit7      = 0x08;
byte max7219_reg_decodeMode  = 0x09;
byte max7219_reg_intensity   = 0x0a;
byte max7219_reg_scanLimit   = 0x0b;
byte max7219_reg_shutdown    = 0x0c;
byte max7219_reg_displayTest = 0x0f;

//scales
struct Scale { 
  char name[20]; 
  byte notes[12]; 
  byte length;
};

struct Scale scaleArray[] = {
  {"Mixolydian", {NUMBER_C7, NUMBER_D7, NUMBER_E7, NUMBER_F7, NUMBER_G7, NUMBER_A7, NUMBER_AS7, NUMBER_C8}, 8},
  {"MajorSus4", {NUMBER_C7, NUMBER_F7, NUMBER_C7, NUMBER_F7, NUMBER_G7, NUMBER_C7, NUMBER_F7, NUMBER_C8}, 8},
  {"MajorSus7", {NUMBER_C7, NUMBER_F7, NUMBER_G7, NUMBER_AS7, NUMBER_C7, NUMBER_F7, NUMBER_G7, NUMBER_C8}, 8},
  {"Major7", {NUMBER_C7, NUMBER_D7, NUMBER_G7, NUMBER_AS7, NUMBER_C7, NUMBER_D7, NUMBER_G7, NUMBER_C8}, 8},
  {"Minor", {NUMBER_C7, NUMBER_D7, NUMBER_DS7, NUMBER_F7, NUMBER_G7, NUMBER_GS7, NUMBER_B7, NUMBER_C8}, 8},
  {"Major", {NUMBER_C7, NUMBER_D7, NUMBER_E7, NUMBER_F7, NUMBER_G7, NUMBER_A7, NUMBER_B7, NUMBER_C8}, 8},
};

byte patterns[8][8][8] = {
  {
    {0,0,0,0,0,0,0,0,},
    {0,0,1,0,0,1,0,0,},
    {0,1,0,1,1,0,1,0,},
    {1,0,0,0,0,0,0,1,},
    {1,0,0,0,0,0,0,1,},
    {0,1,0,0,0,0,1,0,},
    {0,0,1,0,0,1,0,0,},
    {0,0,0,1,1,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {1,0,0,0,0,0,0,0,},
    {0,1,0,0,0,0,1,0,},
    {0,1,1,1,1,1,1,0,},
    {1,1,0,1,1,0,1,1,},
    {1,1,1,1,1,1,1,1,},
    {1,0,1,1,1,1,0,1,},
    {1,0,0,0,0,0,0,1,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },

  {
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
    {0,0,0,0,0,0,0,0,},
  },
};

byte matrBuffer1[8][8];

byte matrBuffer2[8][8];

byte values[] = {0, 0, 0, 0, 0, 0, 0, 0};

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

void convert(){

  for (int i = 0; i < 8; ++i){
    for (int j = 0; j < 8; ++j){
      matrBuffer2[j][i] = matrBuffer1[j][i];
    }
  }

  matrBuffer2[gatePosition1][gatePosition2] = 1;

  for (int i = 0; i < 8; ++i){
    values[i] = 0;
    for (int j = 0; j < 8; ++j){
      values[i] += matrBuffer2[j][i]*powTwo(j);
    }
  }
}

void move(){
  byte mem = 0;
  for (int i = 0; i < 8; ++i){
    mem = matrBuffer1[i][0];
    for (int j = 0; j <7; ++j){
      matrBuffer1[i][j] = matrBuffer1[i][j+1];
    }
    matrBuffer1[i][7] = mem;
  } 

  convert(); 
}


void putByte(byte data) {
  byte i = 8;
  byte mask;
  while(i > 0) {
    mask = 0x01 << (i - 1);      // get bitmask
    digitalWrite( clock, LOW);   // tick
    if (data & mask){            // choose bit
      digitalWrite(dataIn, HIGH);// send 1
    }else{
      digitalWrite(dataIn, LOW); // send 0
    }
    digitalWrite(clock, HIGH);   // tock
    --i;                         // move to lesser bit
  }
}

void maxSingle( byte reg, byte col) {    
//maxSingle is the "easy"  function to use for a single max7219

  digitalWrite(load, LOW);       // begin     
  putByte(reg);                  // specify register
  putByte(col);//((data & 0x01) * 256) + data >> 1); // put data   
  digitalWrite(load, LOW);       // and load da stuff
  digitalWrite(load,HIGH); 
}

void setup () {
  Serial.begin(9600);

  for (int i = 0; i < 8; ++i){
    values[i] = 0;
    for (int j = 0; j < 8; ++j){
      matrBuffer1[j][i] = patterns[0][j][i];
    }
  }

  convert();

  pinMode(dataIn, OUTPUT);
  pinMode(clock,  OUTPUT);
  pinMode(load,   OUTPUT);
  pinMode(11, OUTPUT);

  digitalWrite(13, HIGH);  

//initiation of the max 7219
  maxSingle(max7219_reg_scanLimit, 0x07);      
  maxSingle(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
  maxSingle(max7219_reg_shutdown, 0x01);    // not in shutdown mode
  maxSingle(max7219_reg_displayTest, 0x00); // no display test
   for (e=1; e<=8; e++) {    // empty registers, turn all LEDs off 
    maxSingle(e,0);
  }
  maxSingle(max7219_reg_intensity, 0x01 & 0x0f);    // the first 0x0f is the value you can set
                                                  // range: 0x00 to 0x0f
}  

void loop () {

  //cv = ((scaleArray[scaleSelector].notes[(verticalValue+1)/32]-72)*4);

  for(int i=0;i<8;i++){
    verticalValue += matrBuffer1[i][0] * powTwo(i);
  }

  analogWrite(6, verticalValue);
  analogWrite(9, cv);

  analogWrite(11, matrBuffer1[gatePosition1][gatePosition2]);

  Serial.println(verticalValue);
  Serial.println((verticalValue+1)/32);
  Serial.println(matrBuffer1[gatePosition1][gatePosition2]);

  maxSingle(1,values[0]);                       
  maxSingle(2,values[1]);                       
  maxSingle(3,values[2]);                       
  maxSingle(4,values[3]);                       
  maxSingle(5,values[4]);                      
  maxSingle(6,values[5]);                      
  maxSingle(7,values[6]);                 
  maxSingle(8,values[7]);



  /*maxSingle(1,sec%60);                       
  maxSingle(2,(sec/60)%60);                       
  maxSingle(3,(sec/(60*60))%24);                       
  maxSingle(4,0);                       
  maxSingle(5,0);                      
  maxSingle(6,0);                      
  maxSingle(7,0);                 
  maxSingle(8,0);*/
  


  move();

  delay(200);
}
