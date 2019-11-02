/*morsecode sequencer*/

/*
 *********************************************************************
 *this file is part of mouse.
 *
 *Mouse is free software: you can redistribute it and/or modify
 *it under the terms of the GNU General Public License as published by
 *the Free Software Foundation, either version 3 of the License, or
 *(at your option) any later version.
 *
 *Mouse is distributed in the hope that it will be useful,
 *but WITHOUT ANY WARRANTY; without even the implied warranty of
 *MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *GNU General Public License for more details.
 *********************************************************************
*/

#include <stdlib.h>
#include "noteList.h"
#include <LiquidCrystal.h>
#include <EEPROM.h>
#include "mouse.h"

// initialize lcd library according to interface pins
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

//text to be translated
char text[17] = "tttttttttttttttt";
//translated text
char morseSign[255] = " ";
//  pitches
byte morseNotes[255];

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

//tempo
int time = 500;
int timeBuffer = 0;
unsigned long clockSignal = 0;

//steps made
byte stepI = 0;
byte stepJ = 0;

//length of sequence
byte bars = 16;
//range of notes being assigned
byte range = 8;
//wich scale
byte scaleSelector = 0;
//position of cursor
byte cursorPosition = 0;

//has a note according to the clock allready been played?
byte firstNotePlayed = 0;

//value of button pressed (left, right...)
int value = 10;

//setup function
void setup() {

  stepI = 0;
  stepJ = 0;
  //clockticks = 0;

  int ad = 0;
  while(EEPROM.read(ad) != 0){
    text[ad] = EEPROM.read(ad);
    ad++;
  }
  text[ad] = 0;

  morseSign[0] = 0;
  translatingText();

  //pinmode for gate/cv pin
  pinMode(GATE, OUTPUT);
  pinMode(CV, OUTPUT);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
}

//loop function
void loop() {

  if(millis()%100 == 0){
    printText();
  }

  //read buttons
  value = analogRead(SENSORPIN);
  //read transpose poti
  bars = powTwo((byte)(analogRead(LENGTH)/180));
  //bars = (byte)(pow(2, (byte)(analogRead(LENGTH)/180))+1)*2;
  //bars = (byte)pow(2,(byte)(analogRead(LENGTH)/180));
  //bars = (byte)(analogRead(LENGTH)/180);
  //read scale selector poti
  scaleSelector = (byte)(analogRead(SCALE)/180);
  //read cursor position poti
  cursorPosition = (byte)(analogRead(CURSOR)/63);

  if(value == SELECT){
    //read letter selector poti
    byte v = (byte)(97 + (analogRead(DIAL)/39));

    //letter or space?
    switch (v){
      case 123:
        text[cursorPosition] = ' ';
        break;

      default:
        text[cursorPosition] = v;
        break;
    }
  }

  //assign new pitches
  if(value == RIGHT){

    int ad = 0;
    while(text[ad] != 0){
      EEPROM.write(ad, text[ad]);
      ad++;
    }

    EEPROM.write(ad, 0);

    setup();

  }

  //start from beginning
  if(value == DOWN){
    stepI = 0;
    stepJ = 0;
  }

  //if there is a new pulse
  if(analogRead(SYNC) > 500 && !clockSignal){

    //set clocksignal to 1 so it doesent fire again before the pulse is over
    clockSignal = 1;
    //calculate speed
    time = (int) (millis() - timeBuffer)/2;
    timeBuffer =  millis();

    doStep();
    firstNotePlayed = 1;
  }

  if(millis()-timeBuffer > time && firstNotePlayed == 1){
    doStep();
    firstNotePlayed = 0;
  }

  //lcd.print(time);

  if(analogRead(SYNC) < 300){
    clockSignal = 0;
  }

}

void doStep(){

  printText();

  byte cv = ((scaleArray[scaleSelector].notes[morseNotes[stepI]]-72)*4);

  //lcd.print(cv);

  if(morseSign[stepI] && stepJ < bars){

    analogWrite(CV, cv);

    switch (morseSign[stepI]){
        case '.':
        digitalWrite(GATE, HIGH);
        digitalWrite(13, HIGH);
        break;

        case' ':
        digitalWrite(GATE, LOW);
        digitalWrite(13, LOW);
        break;

        default:
        digitalWrite(GATE, LOW);
        digitalWrite(13, LOW);
        break;
      }
  }

  stepI++;
  if(stepI >= bars){
    stepI = 0;
    digitalWrite(GATE, LOW);
    digitalWrite(13, LOW);
  }

}

void translatingText(){
  int i = 0;
  while(text[i]){
    translateToMorse(text[i]);
    i++;
  }

  randomSeed(analogRead(7));
  int j = 0;
  int r = random(range);
  while(morseSign[j]){

    //muss noch mal gucken, ob gate und noten änderung passen...
    if(j>0 && morseSign[j-1] == ' ' && morseSign[j] != ' '){
      r = random(range);
    }

    morseNotes[j] = r;

    j++;

    if(j>255){
      break;
    }

  }
}

void translateToMorse(char sign){

  switch (sign){
  case 'a': case 'A': strcat(morseSign, ". ..  ");     //.-
    break;
  case 'b': case 'B': strcat(morseSign, ".. . . .  ");     //-...
    break;
  case 'c': case 'C': strcat(morseSign, ".. . .. .  "); //-.-.
    break;
  case 'd': case 'D': strcat(morseSign, ".. . .  ");  //-..
    break;
  case 'e': case 'E': strcat(morseSign, ".  ");//.
    break;
  case 'f': case 'F': strcat(morseSign, ". . .. .  ");//..-
    break;
  case 'g': case 'G': strcat(morseSign, ".. .. .  ");//--.
    break;
  case 'h': case 'H': strcat(morseSign, ". . . .  ");//....
    break;
  case 'i': case 'I': strcat(morseSign, ". .  ");//..
    break;
  case 'j': case 'J': strcat(morseSign,  ". .. .. ..  ");//.---
    break;
  case 'k': case 'K': strcat(morseSign, ".. . ..  ");//-.-
    break;
  case 'l': case 'L': strcat(morseSign, ". .. . .  ");//.-..
    break;
  case 'm': case 'M': strcat(morseSign, ".. ..  ");//
    break;
  case 'n': case 'N': strcat(morseSign, ".. .  ");//-.
    break;
  case 'o': case 'O': strcat(morseSign, ".. .. ..  ");//---
    break;
  case 'p': case 'P': strcat(morseSign, ". .. .. .  ");//.--.
    break;
  case 'q': case 'Q': strcat(morseSign, ".. .. . ..  ");//--.-
    break;
  case 'r': case 'R': strcat(morseSign, ". .. .  ");//.-.
      break;
  case 's': case 'S': strcat(morseSign, ". . .  ");//...
    break;
  case 't': case 'T': strcat(morseSign, "..  ");//-
    break;
  case 'u': case 'U': strcat(morseSign, ". . ..  ");//..-
    break;
  case 'v': case 'V': strcat(morseSign, ". . . ..  ");//...-
      break;
  case 'w': case 'W': strcat(morseSign, ". .. ..  ");//.--
      break;
  case 'x': case 'X': strcat(morseSign, ".. . . ..  ");//-..-
    break;
  case 'y': case 'Y': strcat(morseSign, ".. . ..  ");//-.-
    break;
  case 'z': case 'Z': strcat(morseSign, ".. .. . .  ");//--..
      break;
  case ' ': strcat(morseSign, "   ");
    break;

  default:
    break;
  }
}

byte powTwo(int e){
  int r = 2;

  for(int i=0; i<e; i++){
    r *= 2;
  }

  return r;
}

void printText(){
  //clear screen
  lcd.clear();
  //print text
  lcd.print(text);

  lcd.setCursor(0, 1);

  lcd.print(scaleArray[scaleSelector].name);
  lcd.setCursor(14, 1);
  lcd.print(bars);

  //set cursor position
  lcd.setCursor(cursorPosition, 0);
  //show cursor
  lcd.cursor();
}
