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

class Robot {
  public :
    Robot ();
    void avance();
    void recule();
    void tourneDroite();
    void tourneGauche();
	void arret();
    void addSensorFront(int pinIr);
    void addSensorLeft(int pinIr);
    void addSensorRight(int pinIr);
    void addJail(int pinNear1, int pinNear2, int pinNear3, int pinNear4);
    bool isInJail();

    IRSensor IRSensorFront;
    IRSensor IRSensorLeft;
    IRSensor IRSensorRight;

  private :
    Jail _jail;
    SpeedBox _speedBox;
};

#endif
