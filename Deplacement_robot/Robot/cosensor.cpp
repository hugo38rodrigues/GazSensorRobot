#include "cosensor.h"
#include "Arduino.h"

COSensor::COSensor()
{
    _isConfigured = false;
}
void COSensor::setPin(int pinSensor){
    pinMode (pinSensor, INPUT);
    _pinSensor=pinSensor;
    _isConfigured = true;
}

bool COSensor::detecteCo(){
   int val = analogRead (_pinSensor);
   Serial.println("valeur CO:" + String(val));

   if (_isConfigured && val > 200)
        return true;
    else

        return false;
}

void COSensor::calibCo() {

}
