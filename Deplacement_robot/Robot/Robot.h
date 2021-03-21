/*
 * Robot.h - Librairie de gestion du robot
 * Créé par Hugo Rodrigues/Anthony Neyret - 26/12/2020
 */
#ifndef Robot_h
#define Robot_h

#include "Arduino.h"
#include "IRSensor.h"
#include "Near_sensor.h"
#include "jail.h"
#include "SpeedBox.h"
#include "cosensor.h"
#include "contactsensor.h"
class Robot {
  public :
    Robot ();
    bool detecteCo();
    bool detecteContact();
    void avance();
    void recule();
    void tourneDroite();
    void tourneGauche();
    void stop();
    void addSensorFront(int pinIr);
    void addSensorLeft(int pinIr);
    void addSensorRight(int pinIr);
    void addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4);
    bool isInJail();
    void addSpeedBox (int pinLatch, int pinClock, int pinData);
    void addCOSensor(int pinCOSensor);
    void addContact(int pinContact);

    IRSensor IRSensorFront;
    IRSensor IRSensorLeft;
    IRSensor IRSensorRight;
    SpeedBox speedBox;
    COSensor _COSensor;
    contactsensor _ContactSensor;
  private :
    Jail _jail;
};

#endif
