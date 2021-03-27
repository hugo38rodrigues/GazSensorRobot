/*
 * Jail.cpp - Librairie de gestion de la prison
 * Créé par Hugo Rodrigues/Anthony Neyret - 14/02/2021
 */
#include "jail.h"
#include "Arduino.h"

Jail::Jail(){
    _isConfigured = false;
    _Near_sensor1 = Near_sensor();

}
void Jail::setPins(int pinNear1, int pinNear2, int pinNear3, int pinNear4){
    _Near_sensor1.setPin(pinNear1);
    _Near_sensor2.setPin(pinNear2);
    _Near_sensor3.setPin(pinNear3);
    _Near_sensor4.setPin(pinNear4);

     _isConfigured = true;
}

bool Jail::isInJail(){
    int compteur=0;

    if (_Near_sensor1.isNear())
        compteur++;
    if (_Near_sensor2.isNear())
        compteur++;
    if (_Near_sensor3.isNear())
        compteur++;
    if (_Near_sensor4.isNear())
        compteur++;

    if(_isConfigured && compteur>=3) {
        Serial.println("3 capteurs sur4 détectent la prison");
        return true;
    }
    else
        return false;

}
