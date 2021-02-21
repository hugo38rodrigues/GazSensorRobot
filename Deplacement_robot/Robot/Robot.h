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

class Robot {
  public :
    Robot ();
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
    SpeedBox getSpeedBox();
    SpeedBox _speedBox;

    IRSensor IRSensorFront;
    IRSensor IRSensorLeft;
    IRSensor IRSensorRight;

  private :
    Jail _jail;
};

#endif
