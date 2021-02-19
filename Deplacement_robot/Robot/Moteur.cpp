/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Moteur.h"

Moteur::Moteur(){
    _isConfigured = false;
}

void Moteur::setPins(int pinActivation, int pinMoteur_H, int pinMoteur_A){
  // Configuration des pins moteur
  pinMode (pinActivation, OUTPUT);
  _pinActivation = pinActivation;

    pinMode (pinMoteur_H, OUTPUT);
  _pinMoteur_H = pinMoteur_H;

  pinMode (pinMoteur_A, OUTPUT);
  _pinMoteur_A = pinMoteur_A;

  _isConfigured = true;
}

void Moteur::go_horaire() {
    if (_isConfigured) {
        analogWrite(_pinActivation, LOW);
        digitalWrite(_pinMoteur_H, LOW);
        digitalWrite(_pinMoteur_A, HIGH);

        analogWrite(_pinActivation, HIGH);
    }
}

void Moteur::go_anti_horaire() {
    if (_isConfigured) {
        analogWrite(_pinActivation, LOW);
        digitalWrite(_pinMoteur_H, HIGH);
        digitalWrite(_pinMoteur_A, LOW);
        analogWrite(_pinActivation, HIGH);
    }
}

void Moteur::arret() {
    if (_isConfigured)
        analogWrite(_pinActivation, LOW);
}
