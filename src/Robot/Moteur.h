/*
 * Moteur.h - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef Moteur_h
#define Moteur_h

#include "Arduino.h"

class Moteur {
public :
    Moteur();
    void setPins (int pinActivation);
    void go(int vitesse);
    void stop();

private :
    bool _isConfigured;
    int _pinActivation;
};

#endif
