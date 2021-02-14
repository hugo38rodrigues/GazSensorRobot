/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Robot.h"
#include "Moteur.h"

Robot::Robot () {
}

void Robot::addMotor1(int pinActivation, int pinMoteur_H, int pinMoteur_A){
   Moteur moteur(pinActivation,pinMoteur_H, pinMoteur_A);
   this->_moteur1=&moteur;
}

void Robot::addMotor2(int pinActivation, int pinMoteur_H, int pinMoteur_A){
   Moteur moteur(pinActivation,pinMoteur_H, pinMoteur_A);
   this->_moteur2=&moteur;
}

void Robot::addMotor3(int pinActivation, int pinMoteur_H, int pinMoteur_A){
   Moteur moteur(pinActivation,pinMoteur_H, pinMoteur_A);
   this->_moteur3=&moteur;
}

void Robot::avance() {
    _moteur1->go_horaire();
    _moteur2->go_anti_horaire();
}

void Robot::recule() {
	_moteur1->go_anti_horaire();
	_moteur2->go_horaire();
}

void Robot::tourneDroite() {
	_moteur1->go_anti_horaire();
	_moteur2->go_anti_horaire();
	_moteur3->go_anti_horaire();
}

void Robot::tourneGauche() {
	_moteur1->go_horaire();
	_moteur2->go_horaire();
	_moteur3->go_horaire();
}

void Robot::arret() {
	_moteur1->arret();
	_moteur2->arret();
	_moteur3->arret();
}
