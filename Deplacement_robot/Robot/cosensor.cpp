#include "cosensor.h"

COSensor::COSensor()
{
    _isConfigured = false;
}
void COSensor::setPin(int pinCo){
    pinMode (pinCo, INPUT);
    _pinCo=pinCo;
    _isConfigured = true;
}

bool COSensor::DetecteCo(){
   analogRead (_pinCo, map ( ))
   if
        return true;
    else
        return false;
}
