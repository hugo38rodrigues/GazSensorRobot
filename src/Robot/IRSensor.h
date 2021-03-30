/*
 * Moteur.h - Librairie de gestion d'un moteur DC
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef Sensor_h
#define Sensor_h

#include "Arduino.h"

class IRSensor {
  public :
    IRSensor();
    void setPin(int pinIr);
    bool isBlackLine();
  private :
    bool _isConfigured;
    int _pinIr;
};

#endif
