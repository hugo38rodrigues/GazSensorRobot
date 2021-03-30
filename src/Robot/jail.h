#ifndef JAIL_H
#define JAIL_H
#include "Near_sensor.h"

class Jail{

public:
    Jail();
    bool isInJail();
    void setPins(int pinNear1, int pinNear2, int pinNear3, int pinNear4);

private:
    Near_sensor _Near_sensor1;
    Near_sensor _Near_sensor2;
    Near_sensor _Near_sensor3;
    Near_sensor _Near_sensor4;

    bool _isConfigured;
};

#endif // JAIL_H
