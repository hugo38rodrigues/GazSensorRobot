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

unsigned long chrono=0;
 
Robot robot = Robot();

void setup() {
/*  moteur1.arret();
  moteur2.arret();
  moteur3.arret();
*/
  robot.addMotor2(Driver2_ENB, Driver2_M3, Driver2_M4); //Moteur_D

  robot.addMotor1(Driver1_ENA, Driver1_M1, Driver1_M2); //Moteur_G
  //robot.addMotor3(Driver2_ENA, Driver2_M1, Driver2_M2); //Moteur_A
  robot.arret();

 delay(2000);
}

void loop() {
  unsigned long distance=100;   // 100 cm
  
  if (chrono == 0) {
    chrono = millis();
    robot.avance();
  }
  // 1 cm = 20 ms
  else if ((millis() - chrono) > 20*distance) {
    robot.arret();
  }

  /*
  // Robot Avance
  moteur1.go_horaire();
  moteur2.go_anti_horaire();
  delay (2000);
  
  moteur1.arret();
  moteur2.arret();
  delay (500);

  // Robot Recul
  moteur1.go_anti_horaire();
  moteur2.go_horaire();
  delay (2000);

  moteur1.arret();
  moteur2.arret();
  delay (500);
  
  // Robot demi-tour gauche
  moteur1.go_horaire();
  moteur2.go_horaire();
  moteur3.go_horaire();
  delay (2000);

  moteur1.arret();
  moteur2.arret();
  moteur3.arret();
  delay (500);

    // Robot demi-tour droite
  moteur1.go_anti_horaire();
  moteur2.go_anti_horaire();
  moteur3.go_anti_horaire();
  delay (2000);

  moteur1.arret();
  moteur2.arret();
  moteur3.arret();
  delay (500);
  */
    delay(100);
}
