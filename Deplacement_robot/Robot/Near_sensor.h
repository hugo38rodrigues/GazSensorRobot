#ifndef NEAR_SENSOR_H
#define NEAR_SENSOR_H

#include "Arduino.h"

class  Near_sensor{
public :
    Near_sensor();
    void setPin(int pinNear);
    bool isNear();

private :
    bool _isConfigured;
    int _pinNear;
};
#endif // NEAR_SENSOR_H
