/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Moteur.h"

Moteur::Moteur(){
    _isConfigured = false;
}

void Moteur::setPins(int pinActivation){
    // Configuration des pins moteur
    // Utilisation de pin PWM pour contrôler la vitesse des moteurs
    pinMode (pinActivation, OUTPUT);
    _pinActivation = pinActivation;

    _isConfigured = true;
}

void Moteur::go() {
    if (_isConfigured) {
        Serial.println ("Go motor, speed 80%");
        // Vitesse de 50%
        analogWrite(_pinActivation, map (80, 0, 100, 0, 255));
    }
}

void Moteur::stop() {
    if (_isConfigured) {
        Serial.println("Stop motor");
        // Stop moteur
        analogWrite(_pinActivation, 0);
    }
}
