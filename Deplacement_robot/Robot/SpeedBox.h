/*
 * SpeedBox.h - Librairie de gestion de la boite de vitesses contrôlant le sens des moteurs
 *              La boite de vitesse s'appuie sur un multiplexeur de type 74HC595
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef SpeedBox_h
#define SpeedBox_h

#include "Arduino.h"
#include "Moteur.h"

class SpeedBox {
public :
    SpeedBox();
    void setPins (int pinLatch, int clockPin, int dataPin);
    void addMotor1(int pinActivation)
    void addMotor2(int pinActivation);
    void addMotor3(int pinActivation)
    void avance();
    void recule();
    void tourneDroite();
    void tourneGauche();
    void stop();

private :
    bool _isConfigured;
    int _pinLatch;
    int _clockPin,
    int _dataPin;
    Moteur _moteur1;
    Moteur _moteur2;
    Moteur _moteur3;
};

#endif
