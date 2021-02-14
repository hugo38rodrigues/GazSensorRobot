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
    Robot (Moteur &moteur1, Moteur &moteur2, Moteur &moteur3);
    void avance(unsigned long distance);
    void recule(int distance);
    void tourneDroite(int angle);
    void tourneGauche(int angle);
	void arret();

  private :
	unsigned long _chrono;
	Moteur *_moteur1;
	Moteur *_moteur2;
	Moteur *_moteur3;
};

#endif
