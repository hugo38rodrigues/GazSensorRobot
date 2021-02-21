/*
 * SpeedBox.cpp - Librairie de gestion de la boite de vitesses contrôlant le sens des moteurs
 *              La boite de vitesse s'appuie sur un multiplexeur de type 74HC595
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Moteur.h"
#include "SpeedBox.h"

SpeedBox::SpeedBox() {
    _isConfigured = false;
    _moteur1 = Moteur();
    _moteur2 = Moteur();
    _moteur3 = Moteur();
    _pinLatch = 0;
    _pinClock = 0;
    _pinData = 0;
}

void SpeedBox::setPins (int pinLatch, int pinClock, int pinData) {
    // Configuration des pins moteur
    // Utilisation de pin PWM pour contrôler la vitesse des moteurs
    pinMode (pinLatch, OUTPUT);
    pinMode (pinClock, OUTPUT);
    pinMode (pinData, OUTPUT);
    _pinLatch = pinLatch;
    _pinClock = pinClock;
    _pinData = pinData;

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
    _moteur2.stop();
    _moteur3.stop();

    // Set moteur1horaire + moteur2anti_horaire;
    UpdateMutex(_moteur1Horaire | _moteur2AntiHoraire | _moteur3Horaire);

    _moteur1.go();
    _moteur2.go();
}

void SpeedBox::recule() {
    _moteur1.stop();
    _moteur2.stop();
    _moteur3.stop();

    // Set moteur1antihoraire + moteur2horaire;
    UpdateMutex(_moteur1AntiHoraire | _moteur2Horaire | _moteur3Horaire);

    _moteur1.go();
    _moteur2.go();
}

void SpeedBox::tourneDroite() {
    _moteur1.stop();
    _moteur2.stop();
    _moteur3.stop();

   // Set moteur123antihoraire +
    UpdateMutex(_moteur1AntiHoraire | _moteur2AntiHoraire| _moteur3AntiHoraire);

    _moteur1.go();
    _moteur2.go();
    _moteur3.go();
}

void SpeedBox::tourneGauche() {
    _moteur1.stop();
    _moteur2.stop();
    _moteur3.stop();

   // Set moteur123horaire +
    UpdateMutex(_moteur1Horaire | _moteur2Horaire | _moteur3Horaire);

    _moteur1.go();
    _moteur2.go();
    _moteur3.go();
}

void SpeedBox::stop() {
    _moteur1.stop();
    _moteur2.stop();
    _moteur3.stop();
}

void SpeedBox::UpdateMutex(int data) {
    Serial.print("data for mutex: 0b");
    Serial.print(data, BIN);
    Serial.print(" (0x");
    Serial.print(data, HEX);
    Serial.println(")");

    // On désactive le 74HC595
    digitalWrite(_pinLatch, LOW);

    // Mise à jour du registre à décalage
    shiftOut(_pinData, _pinClock, MSBFIRST, data);

    // On active le 74HC595
    digitalWrite(_pinLatch, HIGH);
}