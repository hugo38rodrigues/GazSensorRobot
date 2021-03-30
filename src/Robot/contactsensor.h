#ifndef CONTACTSENSOR_H
#define CONTACTSENSOR_H
#include "Arduino.h"

class contactsensor
{
public:
    contactsensor();
    void setPin(int _pinContact);
    bool detectcontact();
private:
    bool _isConfigured;
    int _pinContact;
};

#endif // CONTACTSENSOR_H
