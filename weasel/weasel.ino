int t = 500;
uint64_t t1 = 0;
int t2 = 0;
uint64_t t3= 0;
int t4 = 0;

uint64_t t5 = 0;
int t6 = 0;

byte trigger = 0;

byte p[] = {0,0,0,0};

byte dvdr = 1;
byte mult = 1;
byte counter = 0;

void blink(int pin);

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

void setup() {
  pinMode(2, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(4, OUTPUT);
  digitalWrite(2, LOW);
  digitalWrite(12, LOW);
}

void loop() {

  //Serial.println(dvdr);
  /*
  t2 = millis()-t1;

  if(t2 > t){
    t1 = millis();

    blink(5);

    if(dvdr == counter){
      blink(2);
      counter = 0;
    }

    counter++;

    for(int i=0; i<mult; i++){
      blink(12);
      delay(t/mult);
    }
  }

  if(digitalRead(5) == HIGH && trigger == 0){
    trigger = 1;
    
    
    
    blink(4);
    digitalWrite(4, HIGH);
    t6 = millis() - t5;
    t5 = millis();
    t3 = t5;
    t4 = (int)t6/mult;
  }

  if(digitalRead(5) == LOW && trigger ==1){
    trigger = 0;
  }*/

  mult =1 + analogRead(3)/250;
  dvdr =1 + analogRead(5)/250;

  if(analogRead(7) > 200 && !trigger){
    digitalWrite(12, HIGH);
    trigger = 1;
    t = millis()-t1;
    t1 = millis();
    t3 = t1;

    if(powTwo(dvdr) <= counter){
      blink(2);
      counter = 0;
    }

    counter++;

    //blink(12);

    /*for(int i=0; i<mult; i++){
      blink(12);
      delay(t/mult);
    }*/
  }

  if(millis()-t3 > t/powTwo(mult)){
    blink(12);
    t3 = millis();
  }

  if(analogRead(7) < 200 && trigger){
    trigger = 0;
  }

}

void blink(int pin){
  if(digitalRead(pin)==HIGH){
    digitalWrite(pin, LOW);
    p[pin-2] = 0;  
  }
  else{
    digitalWrite(pin, HIGH);
    p[pin-2] = 1;
  }
}
