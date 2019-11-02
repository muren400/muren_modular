#include <LiquidCrystal.h>
#include <EEPROM.h>

#include "drum_seq.h"

// initialize the lcd library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
LiquidCrystal lcd(PIN_RS, PIN_EN, PIN_D4, PIN_D5, PIN_D6, PIN_D7);

byte sequenceGates[32][SEQUENCE_MAX_LEN];
char sequenceString[SEQUENCE_MAX_LEN];

byte sequenceLen = SEQUENCE_MAX_LEN;

byte stepPos = 0;

byte dialXPos = 0;

byte newStep = 1;

byte currentSequence = 0;
byte currentDrum = 0;
byte sequenceBuffer = 0;

byte switchGatePressed = 0;
byte switchesPressed[255];

void readDials(){
  sequenceLen = (analogRead(PIN_POT_DIAL_LEN) + 1) / 64;
  if(sequenceLen > 15) sequenceLen = 15;

  dialXPos = (analogRead(PIN_POT_DIAL_X) + 1) / 64;
  if(dialXPos > 15) dialXPos = 15;

  currentDrum = (analogRead(PIN_POT_DIAL_Y)) / 256;
  if(currentDrum >= MAX_DRUMS) currentDrum = MAX_DRUMS - 1;

  char cursorString[SEQUENCE_MAX_LEN];

  cursorString[12] = currentDrum + '1';

  cursorString[14] = sequenceBuffer / 10 + 48;
  cursorString[15] = sequenceBuffer % 10 + 48;

  for(int i=0; i<SEQUENCE_MAX_LEN; i++){
    if(i==dialXPos) cursorString[i] = '^';
    else if(i < 12 || i==13) cursorString[i] = ' ';
  }

  lcd.setCursor(0, 1);
  lcd.print(cursorString);

  // lcd.setCursor(0, 1);
  // lcd.print(analogRead(PIN_SW_GATE));

  // if(isButtonPress(PIN_SW_NOTE)){
  //   byte dialYPos = (analogRead(PIN_POT_DIAL_Y) + 1) / 64;
  //   if(dialYPos > 12) dialYPos = 12;
  //   sequenceNotes[currentSequence][dialXPos] = dialYPos;
  // }

  sequenceBuffer = (analogRead(PIN_POT_DIAL_SEQUENCE) + 1) / 32;
}

byte isNewButtonPress(int pin) {
  if (!switchesPressed[pin]) {
      if (analogRead(pin) < BUTTON_TRESH) {
          switchesPressed[pin] = 1;

          return 1;
      }
  } else {
      if (analogRead(pin) > BUTTON_TRESH) {
          switchesPressed[pin] = 0;
      }
  }

  return 0;
}

byte isButtonPress(int pin) {
  if (analogRead(pin) < BUTTON_TRESH) {
    return 1;
  }

  return 0;
}

void writeSequences(){
  lcd.setCursor(0, 0);
  lcd.print("writing memory");

  for (int i = 0; i < 32; i++){
    for(int j=0; j<SEQUENCE_MAX_LEN; j++){
      EEPROM.write(i*SEQUENCE_MAX_LEN*2 + j, sequenceGates[i][j]);
      // EEPROM.write(i*SEQUENCE_MAX_LEN*2 + SEQUENCE_MAX_LEN+j, sequenceNotes[i][j]);
    }
  }
}

void readSequences(){
  for (int i = 0; i < 32; i++){
    for(int j=0; j<SEQUENCE_MAX_LEN; j++){
      byte value = EEPROM.read(i*SEQUENCE_MAX_LEN*2 + j);
      if(value > 15) value = 0;
      sequenceGates[i][j] = value;
      
      // value = EEPROM.read(i*SEQUENCE_MAX_LEN*2 + SEQUENCE_MAX_LEN+j);
      // if(value > 12) value = 0;
      // sequenceNotes[i][j] = value;
    }
  }
}

void readButtons(){
  if(isNewButtonPress(PIN_SW_GATE)){
    byte currentStep = sequenceGates[currentSequence][dialXPos];
    if(currentStep & 1<<currentDrum){
      currentStep -= 1<<currentDrum;
    } else {
      currentStep = currentStep | 1<<currentDrum;
    }

    sequenceGates[currentSequence][dialXPos] = currentStep;
  }

  if(isNewButtonPress(PIN_SW_RESET)){
    stepPos = 0;
  }

  if(isNewButtonPress(PIN_SW_SAVE)){
    writeSequences();
  }
}

void printSequence(){

  for(int i=0; i<SEQUENCE_MAX_LEN; i++){

    if(i>sequenceLen){
      sequenceString[i] = ' ';
    } else{;
      if(i ==  stepPos) sequenceString[i] = '*';
      else if(sequenceGates[currentSequence][i] & 1<<currentDrum){
        sequenceString[i] = '|';
      } else {
        sequenceString[i] = '-';
      }
    }
  }

  // lcd.noCursor();
  lcd.setCursor(0, 0);
  lcd.print(sequenceString);
}

byte isNewStep(){
  if(newStep){
    if(digitalRead(PIN_SYNC) != LOW){
      newStep = 0;
      return 1;
    }
  } else{
    if(digitalRead(PIN_SYNC) == LOW){
      newStep = 1;
    }
  }
  
  return 0;
}

void executeStep(){
  stepPos++;

  if(stepPos > sequenceLen){
    stepPos = 0;
    currentSequence = sequenceBuffer;
  }

  if(sequenceGates[currentSequence][stepPos] & DRUM_1){
    digitalWrite(PIN_DRUM_1, HIGH);
  }

  if(sequenceGates[currentSequence][stepPos] & DRUM_2){
    digitalWrite(PIN_DRUM_2, HIGH);
  }

  if(sequenceGates[currentSequence][stepPos] & DRUM_3){
    digitalWrite(PIN_DRUM_3, HIGH);
  }

  if(sequenceGates[currentSequence][stepPos] & DRUM_4){
    digitalWrite(PIN_DRUM_4, HIGH);
  }

  delay(1);

  digitalWrite(PIN_DRUM_1, LOW);
  digitalWrite(PIN_DRUM_2, LOW);
  digitalWrite(PIN_DRUM_3, LOW);
  digitalWrite(PIN_DRUM_4, LOW);
}

void setup() {

  pinMode(PIN_SYNC, INPUT);
  pinMode(PIN_DRUM_1, OUTPUT);
  pinMode(PIN_DRUM_2, OUTPUT);
  pinMode(PIN_DRUM_3, OUTPUT);
  pinMode(PIN_DRUM_4, OUTPUT);

  pinMode(PIN_SW_GATE, INPUT_PULLUP);
  pinMode(PIN_SW_NOTE, INPUT_PULLUP);
  pinMode(PIN_SW_RESET, INPUT_PULLUP);
  pinMode(PIN_SW_SAVE, INPUT_PULLUP);
  // digitalWrite(PIN_SW_GATE, HIGH);

  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LsCD.
  lcd.print("reading memory");

  readSequences();
}

void loop() {
  printSequence();
  readDials();
  readButtons();

  if(isNewStep()){
    executeStep();
  }

  delay(10);

  // lcd.setCursor(1, 1);
  // lcd.print("reading memory");
}
