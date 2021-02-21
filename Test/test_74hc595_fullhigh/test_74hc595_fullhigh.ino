/*
  Sketch 15.1.1
  74HC595

  modified 2016/5/13
  by http://www.freenove.com
*/

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）


void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);
}

void loop() {
  // Define a one-byte variable to use the 8 bits to represent the state of 8 LEDs of LED bar graph.
  // This variable is assigned to 0x01, that is binary 00000001, which indicates only one LED light on.

// Coupe le 74HC595
  digitalWrite(latchPin, LOW);

  shiftOut(dataPin, clockPin, MSBFIRST, 0b00011110);
  
  // Allume le 74HC595
  digitalWrite(latchPin, HIGH);
  delay(100);
}
