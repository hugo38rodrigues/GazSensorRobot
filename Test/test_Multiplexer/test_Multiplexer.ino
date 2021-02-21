#include <SpeedBox.h>

SpeedBox speedBox = SpeedBox();

int latchPin = 12;          // Pin connected to ST_CP of 74HC595（Pin12）
int clockPin = 13;          // Pin connected to SH_CP of 74HC595（Pin11）
int dataPin = 11;           // Pin connected to DS of 74HC595（Pin14）

void setup() {
  // set pins to output
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  
  Serial.begin(9600);
  while (!Serial);
  speedBox.setPins(latchPin, clockPin, dataPin);
  speedBox.addMotor1(10);
  speedBox.addMotor2(3);
  speedBox.addMotor3(5);
}

void loop() {
  speedBox.avance();
  delay(5000);
  speedBox.recule();
  delay(5000);
  speedBox.tourneDroite();
  delay(5000);
  speedBox.tourneGauche();
  delay(5000);
}
