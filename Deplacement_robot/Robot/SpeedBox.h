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
    void addMotor1(int pinActivation);
    void addMotor2(int pinActivation);
    void addMotor3(int pinActivation);
    void avance();
    void recule();
    void tourneDroite();
    void tourneGauche();
    void stop();


private :
    bool _isConfigured;
    int _pinLatch;
    int _pinClock;
    int _pinData;
    Moteur _moteur1;
    Moteur _moteur2;
    Moteur _moteur3;

    // Bits 5 et 6 gère le sens de rotation du moteur 1
    // 5 LOW, 6 HIGH : Sens rotation horaire
    // 5 HIGH, 6 LOW : Sens rotation anti-horaire
    int _moteur1Horaire        = 0b01000000;        // Q6 sur le 74HC595
    int _moteur1AntiHoraire    = 0b00100000;        // Q5 sur le 74HC595

    // Bits 3 et 4 gère le sens de rotation du moteur 2
    // 4 LOW, 3 HIGH : Sens rotation horaire
    // 4 HIGH, 3 LOW : Sens rotation anti-horaire
    int _moteur2Horaire        = 0b00001000;        // Q4 sur le 74HC595
    int _moteur2AntiHoraire    = 0b00010000;        // Q3 sur le 74HC595

    // Bits 1 et 2 gère le sens de rotation du moteur 3
    // 2 LOW, 1 HIGH : Sens rotation horaire
    // 2 HIGH, 1 LOW : Sens rotation anti-horaire
    int _moteur3Horaire        = 0b00000010;        // Q2 sur le 74HC595
    int _moteur3AntiHoraire    = 0b00000100;        // Q1 sur le 74HC595

    void UpdateMutex(int data);
};

#endif
