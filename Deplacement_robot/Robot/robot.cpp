/*
 * Moteur.cpp - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#include "Arduino.h"
#include "Robot.h"
#include "Moteur.h"
#include "IRSensor.h"
#include "Near_sensor.h"
#include "jail.h"

Robot::Robot() {
    _moteur1 = Moteur();
    _moteur2 = Moteur();
    _moteur3 = Moteur();
    IRSensorFront = IRSensor();
    IRSensorLeft = IRSensor();
    IRSensorRight = IRSensor();
    jail = Jail();
}
void Robot::addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4){
    jail.setPins(pinNear1, pinNear2,pinNear3, pinNear4);
}

void Robot::addMotor1(int pinActivation, int pinMoteur_H, int pinMoteur_A){
    _moteur1.setPins(pinActivation,pinMoteur_H, pinMoteur_A);
}

void Robot::addMotor2(int pinActivation, int pinMoteur_H, int pinMoteur_A){
    _moteur2.setPins(pinActivation,pinMoteur_H, pinMoteur_A);
}

void Robot::addMotor3(int pinActivation, int pinMoteur_H, int pinMoteur_A){
    _moteur3.setPins(pinActivation,pinMoteur_H, pinMoteur_A);
}

void Robot::addSensorFront(int pinIr){
    IRSensorFront.setPin(pinIr);
}
void Robot::addSensorLeft(int pinIr){
    IRSensorLeft.setPin(pinIr);
}

void Robot::addSensorRight(int pinIr){
    IRSensorRight.setPin(pinIr);
}

void Robot::avance() {
    _moteur1.go_horaire();
    _moteur2.go_anti_horaire();
    _moteur3.arret();
}

void Robot::recule() {
    _moteur1.go_anti_horaire();
    _moteur2.go_horaire();
}

void Robot::tourneDroite() {
    _moteur1.go_anti_horaire();
    _moteur2.go_anti_horaire();
    _moteur3.go_anti_horaire();
}

void Robot::tourneGauche() {
    _moteur1.go_horaire();
    _moteur2.go_horaire();
    _moteur3.go_horaire();
}

void Robot::arret() {
    _moteur1.arret();
    _moteur2.arret();
    _moteur3.arret();
}

