#include <Robot.h>

// Configuration des PIN Driver 1
const int pin_shie1d1_ENA = 10;     // PWM Orange
const int pin_shie1d1_ENB = 0;      // N/A

// Configuration des PIN Driver 2
const int pin_shie1d2_ENA = 3;      // PWM Gris
const int pin_shie1d2_ENB = 5;      // PWM Vert

// Configuration des PIN_IR
const int pin_IrFront = 7;          // Orange
const int pin_IrLeft = 9;           // Vert
const int pin_IrRight = 8;          // Marron

// Configuration des PIN_NEAR
const int pin_NearRightFront = A1;  //  
const int pin_NearRightBack = A2;   //
const int pin_NearLeftFront = A3;   //
const int pin_NearLeftBack = A4;    //

// Configuration des Pins du multiplexeur
const int pinLatch = 12;          // Pin connected to ST_CP of 74HC595（Pin12）Orange
const int pinClock = 13;          // Pin connected to SH_CP of 74HC595（Pin11）Blanc
const int pinData = 11;           // Pin connected to DS of 74HC595（Pin14）Blanc

// Configuration des Pins du capteur Co et fumée
const int pinSensor = A0;

//Configuration de la Pin du wifi
const int pinWifi = 2;

Robot robot = Robot();

//bool turnRight=false;
//bool turnLeft=false;

void setup() 
{
  Serial.begin(9600);
  while (!Serial);
  
  Serial.println("Setup configuration");
  // Creation du capteur 
  robot.addSensor(pinSensor);
  
  Serial.println("Creation du module wifi");
  
  // Creation de la boite de vitesse
  Serial.println("Creation de la boite de vitesse");
  robot.addSpeedBox(pinLatch, pinClock, pinData);
  robot.speedBox.addMotor1(pin_shie1d1_ENA);    // Moteur gauche
  robot.speedBox.addMotor2(pin_shie1d2_ENA);    // Moteur droit
  robot.speedBox.addMotor3(pin_shie1d2_ENB);    // Moteur arrière

  Serial.println("Ajout des capteurs IR");
  robot.addSensorFront(pin_IrFront);
  robot.addSensorLeft(pin_IrLeft);
  robot.addSensorRight(pin_IrRight);

  Serial.println("Ajout des capteurs de la prison");
  robot.addJail(pin_NearRightFront, pin_NearRightBack, pin_NearLeftFront, pin_NearLeftBack);  


  Serial.println("Robot prêt... Attente 2\"");
  robot.stop();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
 if(robot.IRSensorFront.isBlackLine()) //Si le capteur du centre détecte du noir
  {
    if ((robot.IRSensorLeft.isBlackLine()) && (!robot.IRSensorRight.isBlackLine())) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Serial.println("Tourner à gauche");
    }
    else if ((!robot.IRSensorLeft.isBlackLine()) && (robot.IRSensorRight.isBlackLine())) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Serial.println("Tourner à droite");
    }
    else //Si les conditions plus haut ne s'appliquent pas, continuer tout droit
    {
      Serial.println("Continuer tout droit");
    }
  }
  else //Si le capteur du centre détecte du blanc
  {
    if ((robot.IRSensorLeft.isBlackLine()) && (!robot.IRSensorRight.isBlackLine())) //S'il y a du noir à gauche et du blanc à droite, tourner à gauche
    {
      Serial.println("Tourner à gauche");
    }
    else if ((!robot.IRSensorLeft.isBlackLine()) && (robot.IRSensorRight.isBlackLine())) //S'il y a du blanc à gauche et du noir à droite, tourner à droite
    {
      Serial.println("Tourner à droite");
    }
    else //Si les conditions plus hautdne s'appliquent pas, reculer
    {
      Serial.println("Reculer");
    }
  }
  delay(2000);
}
