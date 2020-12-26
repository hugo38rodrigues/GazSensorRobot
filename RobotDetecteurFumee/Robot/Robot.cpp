/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Robot.h"
#include "Moteur.h"

Robot::Robot (Moteur &moteur1, Moteur &moteur2, Moteur &moteur3) {
	_moteur1 = &moteur1;
	_moteur2 = &moteur2;
	_moteur3 = &moteur3;
	_chrono = 0;
}

// 1 cm = 20 ms
void Robot::avance(unsigned long distance) {
	if (_chrono == 0) {
		_chrono = millis();
		_moteur1->go_horaire();
		_moteur2->go_anti_horaire();
	}
	else if ((millis() - _chrono) > 20*distance) {
		this->arret();
	}
}

void Robot::recule(int distance) {
	_moteur1->go_anti_horaire();
	_moteur2->go_horaire();
}

void Robot::tourneDroite(int angle) {
	_moteur1->go_anti_horaire();
	_moteur2->go_anti_horaire();
	_moteur3->go_anti_horaire();
}

void Robot::tourneGauche(int angle) {
	_moteur1->go_horaire();
	_moteur2->go_horaire();
	_moteur3->go_horaire();
}

void Robot::arret() {
	_moteur1->arret();
	_moteur2->arret();
	_moteur3->arret();
	_chrono = 0;
}
