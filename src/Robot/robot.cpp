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
#include "contactsensor.h"

Robot::Robot() {
    IRSensorFront = IRSensor();
    IRSensorLeft = IRSensor();
    IRSensorRight = IRSensor();
    _jail = Jail();
    speedBox = SpeedBox();
    _COSensor = COSensor();
    _ContactSensor = contactsensor();
}
void Robot::addContact(int pinContact){
    _ContactSensor.setPin(pinContact);
}
void Robot::addCOSensor(int pinCOSensor){
    _COSensor.setPin(pinCOSensor);
}

void Robot::addSpeedBox (int pinLatch, int pinClock, int pinData) {
    speedBox.setPins(pinLatch, pinClock, pinData);
}

void Robot::addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4){
    _jail.setPins(pinNear1, pinNear2, pinNear3, pinNear4);
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

bool Robot::detecteContact(){
    return _ContactSensor.detectcontact();
}
bool Robot::detecteCo(){
    return _COSensor.detecteCo();
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

void Robot::ajusteDroite() {
    speedBox.ajusteDroite();
}

void Robot::ajusteGauche() {
    speedBox.ajusteGauche();
}

void Robot::stop() {
    speedBox.stop();
}
bool Robot::isInJail() {
    return _jail.isInJail();
}
