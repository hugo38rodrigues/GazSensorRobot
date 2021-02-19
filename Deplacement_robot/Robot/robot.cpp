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

Robot::Robot() {
    IRSensorFront = IRSensor();
    IRSensorLeft = IRSensor();
    IRSensorRight = IRSensor();
    _jail = Jail();
    _speedBox = SpeedBox()
}

void Robot::addSpeedBox (int pinLatch, int clockPin, int dataPin) {
    _speedBox.setPins(pinLatch, clockPin, dataPin);
}

void Robot::addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4){
    _jail.setPins(pinNear1, pinNear2,pinNear3, pinNear4);
}

bool Robot::isInJail() {
    return _jail.isInJail();
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

void Robot::avance() {
    _speedBox.avance();
}

void Robot::recule() {
    _speedBox.recule()
}

void Robot::tourneDroite() {
    _speedBox.tourneDroite();
}

void Robot::tourneGauche() {
    _speedBox.tourneGauche();
}

void Robot::stop() {
    _speedBox.stop();
}

