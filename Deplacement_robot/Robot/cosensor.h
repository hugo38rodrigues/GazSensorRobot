
/*
 * Co.h - Librairie de gestion d'un capteur CO
 * Créé par Hugo Rodrigues/Anthony Neyret - 03/03/2020
 */
#ifndef COSENSOR_H
#define COSENSOR_H
#include "Arduino.h"

class COSensor{

public:
    COSensor();
    void setPin(int pinSensor);
    bool detecteCo();
    void calibCo();
    int pinSensor;
private:
    bool _isConfigured;

};

#endif // COSENSOR_H
