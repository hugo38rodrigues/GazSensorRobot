#include "contactsensor.h"
#include "Arduino.h"

contactsensor::contactsensor()
{
    _isConfigured = false;
}
void contactsensor::setPin(int pinContact){
    pinMode (pinContact, INPUT_PULLUP);
   _pinContact=pinContact;
    _isConfigured = true;
}
bool contactsensor::detectcontact(){
   if (_isConfigured && !digitalRead(_pinContact))
        return true;
    else

        return false;
}
