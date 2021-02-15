/*
 * IRSensor.cpp - Librairie de gestion d'un capteur IR
 * Créé par Hugo Rodrigues/Anthony Neyret - 14/02/2021
 */
#include "Arduino.h"
#include "IRSensor.h"


IRSensor::IRSensor(){
    _isConfigured = false;
}

void IRSensor::setPin(int pinIr){
    pinMode (pinIr, INPUT);
    _pinIr=pinIr;
    _isConfigured = true;
}

bool IRSensor::isBlackLine(){
    if (_isConfigured && digitalRead(_pinIr)==HIGH)
        return true;
    else
        return false;
}
