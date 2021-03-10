/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Robot.h"
#include "Moteur.h"
#include "IRSensor.h"
#include "Near_sensor.h"
#include "jail.h"
#include "SpeedBox.h"
#include "cosensor.h"


Robot::Robot() {
    IRSensorFront = IRSensor();
    IRSensorLeft = IRSensor();
    IRSensorRight = IRSensor();
    _jail = Jail();
    speedBox = SpeedBox();
    _sensor = COSensor();
}

void Robot::addSensor(int pinSensor){
  _sensor.setPin(pinSensor);
}

void Robot::addSpeedBox (int pinLatch, int pinClock, int pinData) {
    speedBox.setPins(pinLatch, pinClock, pinData);
}

void Robot::addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4){
    _jail.setPins(pinNear1, pinNear2,pinNear3, pinNear4);
}

void Robot::addSensorFront(int pinIr){
    IRSensorFront.setPin(pinIr);
}
void Robot::addSensorLeft(int pinIr){
    IRSensorLeft.setPin(pinIr);
}

void Robot::addSensorRight(int pinIr){
    IRSensorRight.setPin(pinIr);
}


bool Robot::detecteCo(){
    return _sensor.detecteCo();
}


void Robot::avance() {
    speedBox.avance();
}

void Robot::recule() {
    speedBox.recule();
}

void Robot::tourneDroite() {
    speedBox.tourneDroite();
}

void Robot::tourneGauche() {
    speedBox.tourneGauche();
}

void Robot::stop() {
    speedBox.stop();
}
bool Robot::isInJail() {
    return _jail.isInJail();
}
