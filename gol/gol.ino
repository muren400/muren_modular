//#include <AH_MCP4922.h>
#include "AH_MCP4921.h"
#include "pitches.h"
#include "patterns.h"
#include "matrix.h"

#define LENGTHIN 1
#define BUTTONSIN 2
#define SCALEIN 3
#define SYNCIN 5
#define CVOUT 10
#define GATEOUT 11

//DAC
#define SDI 5
#define SCK 6
#define CS 7

#define REPEATVAL 0

byte tune = 0;

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

AH_MCP4921 AnalogOutput1(SDI,SCK,CS);

//boolean play/stop
byte play = 1;
byte buttonPressed = 0;

//bolean mode
byte gol = 0;

int e = 0;           // just a variable

//sync
byte clockSignal = 0;

//mode
byte borderMode = 1;

//repeat mode
byte counter = 0;

//cursorlocation
int gateX = 0;
int gateY = 0;
//selection
int scaleSelect = 0;
int repeatLength = 8;
int patternSelect = 6;

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

byte matrBuffer1[8][8];

byte matrBuffer2[8][8];

byte values[] = {0, 0, 0, 0, 0, 0, 0, 0};

// int powTwo(byte n){
// 	if(n==0){
// 		return 1;
// 	}

// 	int two = 2;
// 	for (int i = 1; i < n; ++i){
// 		two *= 2;
// 	}

// 	return two;
// 	}

// void convert(){

// 	for (int i = 0; i < 8; ++i){
// 		for (int j = 0; j < 8; ++j){
// 			matrBuffer2[j][i] = matrBuffer1[j][i];
// 		}
// 	}

// 	matrBuffer2[gateX][gateY] = 1;

// 	for (int i = 0; i < 8; ++i){
// 		values[i] = 0;
// 		for (int j = 0; j < 8; ++j){
// 			values[i] += matrBuffer2[j][i]*powTwo(j);
// 		}
// 	}
// }

// void putByte(byte data) {
// 	byte i = 8;
// 	byte mask;
// 	while(i > 0) {
// 		mask = 0x01 << (i - 1);      // get bitmask
// 		digitalWrite(CLOCK, LOW);   // tick
// 		if (data & mask){            // choose bit
// 			digitalWrite(DATAIN, HIGH);// send 1
// 		}else{
// 			digitalWrite(DATAIN, LOW); // send 0
// 		}
// 		digitalWrite(CLOCK, HIGH);   // tock
// 		--i;                         // move to lesser bit
// 	}
// }

// void maxSingle( byte reg, byte col) {    
// //maxSingle is the "easy"  function to use for a single max7219

// 	digitalWrite(LOAD, LOW);       // begin     
// 	putByte(reg);                  // specify register
// 	putByte(col);//((data & 0x01) * 256) + data >> 1); // put data   
// 	digitalWrite(LOAD, LOW);       // and load da stuff
// 	digitalWrite(LOAD,HIGH); 
// 	}

void initArray(){
	for (int i = 0; i < 8; ++i){
		values[i] = 0;
		for (int j = 0; j < 8; ++j){
			matrBuffer1[j][i] = patterns[patternSelect][j][i];
		}
	}  
}

void doStepGOL(){

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			matrBuffer2[i][j] = 0;
		}
	}

	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			int k=0;

			for(int l=i-1; l<i+2; l++){
				for(int m=j-1; m<j+2; m++){

					int x=l;
					int y=m;

					if(borderMode){
						if(x<0){
							x=7;
						}
						if(x>7){
							x=0;
						}
						if(y<0){
							y=7;
						}
						if(y>7){
							y=0;
						}
					} 

					if(matrBuffer1[x][y] && (x!=i || y!=j) && (x>=0 && x<8 && y>=0 && y<8)){
						k++;
					}
				}
			}

			if(matrBuffer1[i][j]==0 && k==3){
				matrBuffer2[i][j] = 1;
			}

			if(matrBuffer1[i][j] == 1){
				if(k==1){
					matrBuffer2[i][j] = 0;
				}
				else if(k==2 || k==3){
					matrBuffer2[i][j] = 1;
				}
				else{
					matrBuffer2[i][j] = 0;
				}
			}
		}
	}

	for (int i = 0; i < 8; ++i){
		for (int j = 0; j < 8; ++j){
			matrBuffer1[i][j] = matrBuffer2[i][j];
		}
	}
}

// void doStepRat(){

// 		byte mem = 0;
// 		for (int i = 0; i < 8; ++i){
// 			mem = matrBuffer1[i][0];
// 			for (int j = 0; j <7; ++j){
// 				matrBuffer1[i][j] = matrBuffer1[i][j+1];
// 			}
// 			matrBuffer1[i][7] = mem;
// 		}

// 		ratI++;

// 		if(ratI > 7){
// 			ratI = 0;
// 		}
// 		}

void move(){
	byte mem = 0;
	for (int i = 0; i < 8; ++i){
		mem = matrBuffer1[i][0];
		for (int j = 0; j <7; ++j){
			matrBuffer1[i][j] = matrBuffer1[i][j+1];
		}    
		matrBuffer1[i][7] = mem;
	} 

	convert(matrBuffer1, matrBuffer2, values, gateX, gateY);
}

void intrpt(){
	int valueIn = (values[gateY]+1)%8;
	int note = (scaleArray[scaleSelect].notes[valueIn-1] - 72)*100;
	doStepGOL();
	AnalogOutput1.setValue(note);
	if((values[gateY]) < 150){
		digitalWrite(GATEOUT, HIGH);
	}
	else{
		digitalWrite(GATEOUT, LOW);
	}
	convert(matrBuffer1, matrBuffer2, values, gateX, gateY);

	counter++;    
	if(counter>=powTwo(repeatLength)){
		counter = 0;    
		initArray();
		convert(matrBuffer1, matrBuffer2, values, gateX, gateY);
	}
}

void setup () {
	patternSelect = analogRead(3)*8 / 1024;

	initArray();

	convert(matrBuffer1, matrBuffer2, values, gateX, gateY);

	pinMode(DATAIN, OUTPUT);
	pinMode(CLOCK,  OUTPUT);
	pinMode(LOAD,   OUTPUT);

	pinMode(SDI, OUTPUT);
	pinMode(CS, OUTPUT);
	pinMode(SCK, OUTPUT);

	pinMode(GATEOUT, OUTPUT);

	pinMode(A0, INPUT);
	digitalWrite(A0, HIGH);

	//initiation of the max 7219
	maxSingle(max7219_reg_scanLimit, 0x07);      
	maxSingle(max7219_reg_decodeMode, 0x00);  // using an led matrix (not digits)
	maxSingle(max7219_reg_shutdown, 0x01);    // not in shutdown mode
	maxSingle(max7219_reg_displayTest, 0x00); // no display test
	for (e=1; e<=8; e++) {    // empty registers, turn all LEDs off 
		maxSingle(e,0);
	}
	maxSingle(max7219_reg_intensity, 0x01 & 0x0f);    
}  

void loop () {

	maxSingle(1,values[0]);                       
	maxSingle(2,values[1]);                       
	maxSingle(3,values[2]);                       
	maxSingle(4,values[3]);                       
	maxSingle(5,values[4]);                      
	maxSingle(6,values[5]);                      
	maxSingle(7,values[6]);                 
	maxSingle(8,values[7]);

	int buttonValue = analogRead(0);

	//start stop
	if(buttonValue > 35 && buttonValue < 55 && !buttonPressed){
		if(play < 0){
			play = 0;
			attachInterrupt(0, intrpt, RISING);
		}
		else if(play == 0){
			play = 1;
			detachInterrupt(0);
		}


		buttonPressed = 1;
		initArray();
	}

	if(buttonValue > 500 && buttonPressed){
		buttonPressed = 0;
	}

	gateX = 0;
	gateY = 0;
	scaleSelect = 0;
	repeatLength = 0;

	for(int i=0; i<10; i++){
		gateX += analogRead(1);
		gateY += analogRead(2);
		scaleSelect += analogRead(4);
		repeatLength += analogRead(3);
	}

	gateX /= 10;
	gateY /= 10;
	scaleSelect /= 10;
	repeatLength /= 10;

	gateX /= 140;
	gateY /= 140;
	scaleSelect /= 150;
	repeatLength /= 140;

	if(play == 0){

		//change Pattern
		if(buttonValue > 65 && buttonValue < 80 && !buttonPressed){

			patternSelect++;
			if(patternSelect > 7) patternSelect = 0;

			buttonPressed = 1;
		}

		//draw
		if(buttonValue > 10 && buttonValue < 25 && !buttonPressed){

			patterns[patternSelect][gateX][gateY] = !patterns[patternSelect][gateX][gateY];

			buttonPressed = 1;
		}    

		if(buttonValue > 500 && buttonPressed){
			buttonPressed = 0;
		}

		initArray();
		convert(matrBuffer1, matrBuffer2, values, gateX, gateY);
	}
}
