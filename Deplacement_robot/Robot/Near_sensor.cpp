/*
 * IRSensor.cpp - Librairie de gestion d'un capteur IR
 * Créé par Hugo Rodrigues/Anthony Neyret - 14/02/2021
 */
#include "Arduino.h"
#include "Near_sensor.h"


Near_sensor::Near_sensor(){
    _isConfigured = false;
}
void Near_sensor::setPin(int pinNear){
    pinMode (pinNear, INPUT);
    _pinNear=pinNear;
    _isConfigured = true;
}

bool Near_sensor::isNear(){
   if ( analogRead(_pinNear) > 1023*1.3/5)      //d'apres l abbaque 1.3V correspond à 10 cm
       return true;

   else
       return false;
}
