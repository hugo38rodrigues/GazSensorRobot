/*
  Sketch 15.1.1
  74HC595

  modified 2016/5/13
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）
int buttonPin = 5;
byte portRange = 0b00000010;


void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
  
  Serial.begin(9600);
}

void loop() {
  // Define a one-byte variable to use the 8 bits to represent the state of 8 LEDs of LED bar graph.
  // This variable is assigned to 0x01, that is binary 00000001, which indicates only one LED light on.

  if (digitalRead (buttonPin) == LOW) {
    Serial.println("Button pushed");
    setLed(1);
  }
  else {
    Serial.println("Button unpushed");
    unsetLed(1);
  }
  
  delay(100);
}

void setLed (int port) {
  //bitWrite(portRange, port-1, 1);   // bitWrite start from O
  updatePort2(port, HIGH);
}

void unsetLed (int port) {
  //bitWrite(portRange, port-1, 0);   // bitWrite start from O
  updatePort2(port, LOW);
}

void updatePort2(int port, bool state) {
  // Coupe le 74HC595
  digitalWrite(latchPin, LOW);

  if (state)
    shiftOut(dataPin, clockPin, MSBFIRST, 0b00000010);
  else
    shiftOut(dataPin, clockPin, MSBFIRST, 0);
  
  // Allume le 74HC595
  digitalWrite(latchPin, HIGH);
}

void updatePort(int port, bool state) {
  // Coupe le 74HC595
  digitalWrite(latchPin, LOW);

  for (int j = 7 ; j >= 0; j--) {
    // Clock à l'état bas
    digitalWrite(clockPin, LOW);

    if (j == 7-port) {    // port Q1 
      digitalWrite(dataPin, state);
  }

    // Clock à l'état haut => front montant => change de registre
    digitalWrite(clockPin, HIGH);
  }
  
  // Allume le 74HC595
  digitalWrite(latchPin, HIGH);
}
