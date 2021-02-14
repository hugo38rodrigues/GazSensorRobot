/*
 * Moteur.h - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef Moteur_h
#define Moteur_h

#include "Arduino.h"

class Moteur {
  public :
    Moteur (int pinActivation, int pinMoteur_H, int pinMoteur_A);
    void go_horaire();
    void go_anti_horaire();
    void arret();

  private :
    int _pinActivation;
    int _pinMoteur_H;
    int _pinMoteur_A;
};

#endif
