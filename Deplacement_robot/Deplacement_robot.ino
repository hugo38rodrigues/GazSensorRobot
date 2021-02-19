#include <Robot.h>

// Configuration des PIN Driver 1
const int Driver1_ENA = 11;   // Marron
const int Driver1_M1 = 12;   // Rouge
const int Driver1_M2 = 13;   // Orange

const int Driver1_ENB = 0;    // N/A
const int Driver1_M3 = 0;    // N/A
const int Driver1_M4 = 0;    // N/A

// Configuration des PIN Driver 2
const int Driver2_ENA = 7;    // Noir
const int Driver2_M1 = 6;    // Blanc
const int Driver2_M2 = 5;    // Gris

const int Driver2_ENB = 2;    // Vert
const int Driver2_M3 = 4;    // Violet
const int Driver2_M4 = 3;    // Bleu

// Configuration des PIN_IR
const int IrFront = 10;
const int IrLeft = 9;
const int IrRight = 8; 

// Configuration des PIN_NEAR
const int NearRightFront=A1 ; 
const int NearRightBack =A2;
const int NearLeftFront = A3;
const int NearLeftBack = A4;

Robot robot = Robot();

bool turnRight= false;
bool turnLeft=false;
void setup() {
  robot.addMotor1(Driver1_ENA, Driver1_M1, Driver1_M2); //Moteur_G
  robot.addMotor2(Driver2_ENB, Driver2_M3, Driver2_M4); //Moteur_D
  robot.addMotor3(Driver2_ENA, Driver2_M1, Driver2_M2); //Moteur_A
  robot.addSensorFront(IrFront);
  robot.addSensorLeft(IrLeft);
  robot.addSensorRight(IrRight);
  robot.addJail(NearRightFront,NearRightBack, NearLeftFront,NearLeftBack);  
  robot.arret();
  delay(2000);
}

void loop() {
  if (robot.isInJail())
      robot.arret();
  else{
      
  if(robot.IRSensorRight.isBlackLine()){
      turnRight=true;
      turnLeft=false;
  }

  if(robot.IRSensorLeft.isBlackLine()){
      turnRight=false;
      turnLeft=true;
  }
      
  if(robot.IRSensorFront.isBlackLine())
    robot.avance();
  else {
    robot.arret();
    if (turnLeft)
      robot.tourneGauche();
    else if (turnRight)
      robot.tourneDroite();
   }
  delay(20);
}

void avance100(){
   unsigned long distance=100;   // 100 cm
   unsigned long chrono=0;
  if (chrono == 0) {
    chrono = millis();
    robot.avance();
  }
  // 1 cm = 20 ms
  else if ((millis() - chrono) > 20*distance) {
    robot.arret();
  }
}
