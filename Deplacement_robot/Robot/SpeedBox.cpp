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
    _pinData  = 0;
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
    // Set moteur1horaire + moteur2anti_horaire;
    UpdateMutex(_moteur1Horaire | _moteur2AntiHoraire | _moteur3Horaire);

    Serial.println("moteur 1");
    _moteur1.go(80);
    Serial.println("moteur 2");
    _moteur2.go(80);
    Serial.println("moteur 3");
    _moteur3.stop();
}

void SpeedBox::recule() {
    // Set moteur1antihoraire + moteur2horaire;
    UpdateMutex(_moteur1AntiHoraire | _moteur2Horaire | _moteur3Horaire);

    _moteur1.go(50);
    _moteur2.go(50);
    _moteur3.stop();
}

void SpeedBox::tourneDroite(){
   // Set moteur123antihoraire +
    UpdateMutex(_moteur1AntiHoraire | _moteur2AntiHoraire| _moteur3AntiHoraire);
    Serial.println("moteur 1");
    _moteur1.go(50);
    Serial.println("moteur 2");
    _moteur2.go(50);
    Serial.println("moteur 3");
    _moteur3.go(50);
}

void SpeedBox::tourneGauche(){
   // Set moteur123horaire +
    UpdateMutex(_moteur1Horaire | _moteur2Horaire | _moteur3Horaire);
    Serial.println("moteur 1");
    _moteur1.go(50);
    Serial.println("moteur 2");
    _moteur2.go(50);
    Serial.println("moteur 3");
    _moteur3.go(50);
}

void SpeedBox::stop(){
    Serial.println("moteur 1");
    _moteur1.stop();
    Serial.println("moteur 2");
    _moteur2.stop();
    Serial.println("moteur 3");
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
