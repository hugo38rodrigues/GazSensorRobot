#include <IRSensor.h>

IRSensor irSensorFront = IRSensor();
IRSensor irSensorLeft = IRSensor();
IRSensor irSensorRight = IRSensor();

// Configuration des PIN_IR
const int pin_IrFront = 7;          // Orange
//const int pin_IrLeft = 9;           // Vert
//const int pin_IrRight = 8;          // Marron

void setup() {
  pinMode(13, OUTPUT);
  // Creation de la boite de vitesse
  irSensorFront.setPin(pin_IrFront);
  //irSensorLeft.setPin(pin_IrLeft);
  //irSensorRight.setPin(pin_IrRight);
}

void loop() {
  if (irSensorFront.isBlackLine()) {
    blinkLed13();
  }/*
  if (irSensorLeft.isBlackLine()) {
    blinkLed13();
  }
  if (irSensorRight.isBlackLine()) {
    blinkLed13();
  }
     */ 
  delay(20);    
}

void blinkLed13() {
  for (int i=0; i<10; i++) {
    digitalWrite (13, HIGH);
    delay(50);
    digitalWrite (13, LOW);
    delay(50);
  }
}
