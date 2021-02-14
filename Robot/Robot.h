/*
 * Robot.h - Librairie de gestion du robot
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef Robot_h
#define Robot_h

#include "Arduino.h"
#include "Moteur.h"

class Robot {
  public :
    Robot ();
    void addMotor1(int pinActivation, int pinMoteur_H, int pinMoteur_A);
    void addMotor2(int pinActivation, int pinMoteur_H, int pinMoteur_A);
    void addMotor3(int pinActivation, int pinMoteur_H, int pinMoteur_A);
    void avance();
    void recule();
    void tourneDroite();
    void tourneGauche();
	void arret();


  private :
	Moteur *_moteur1;
	Moteur *_moteur2;
	Moteur *_moteur3;
};

#endif
