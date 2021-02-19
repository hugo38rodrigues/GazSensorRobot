/*
 * SpeedBox.cpp - Librairie de gestion de la boite de vitesses contrôlant le sens des moteurs
 *              La boite de vitesse s'appuie sur un multiplexeur de type 74HC595
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Moteur.h"

SpeedBox::SpeedBox(){
    _isConfigured = false;
    _moteur1 = Moteur();
    _moteur2 = Moteur();
    _moteur3 = Moteur();
}

void SpeedBox::setPins (int pinLatch, int clockPin, int dataPin) {
    // Configuration des pins moteur
    // Utilisation de pin PWM pour contrôler la vitesse des moteurs
    pinMode (pinLatch, OUTPUT);
    pinMode (clockPin, OUTPUT);
    pinMode (dataPin, OUTPUT);
    _pinLatch = pinLatch;
    _clockPin = clockPin;
    _dataPin = dataPin;

    _isConfigured = true;
}

void SpeedBox::addMotor1(int pinActivation) {
    _moteur1.setPins (pinActivation);
}
void SpeedBox::addMotor2(int pinActivation) {
    _moteur2.setPins (pinActivation);
}
void SpeedBox::addMotor3(int pinActivation) {
    _moteur3.setPins (pinActivation);
}

void SpeedBox::avance() {
    _moteur1.stop();
    _moteur2.stop()
    _moteur3.stop();

    // Set moteur1horaire + moteur2anti_horaire;

    _moteur1.go();
    _moteur2.go();
}

void SpeedBox::recule() {
    _moteur1.stop();
    _moteur2.stop()
    _moteur3.stop();

    // Set moteur1antihoraire + moteur2horaire;

    _moteur1.go();
    _moteur2.go();
}

void SpeedBox::tourneDroite() {
    _moteur1.stop();
    _moteur2.stop()
    _moteur3.stop();

   // Set moteur123antihoraire +

    _moteur1.go();
    _moteur2.go();
    _moteur3.go();
}

void SpeedBox::tourneGauche() {
    _moteur1.stop();
    _moteur2.stop()
    _moteur3.stop();

   // Set moteur123horaire +

    _moteur1.go();
    _moteur2.go();
    _moteur3.go();
}

void SpeedBox::stop() {
    _moteur1.stop();
    _moteur2.stop();
    _moteur3.stop();
}