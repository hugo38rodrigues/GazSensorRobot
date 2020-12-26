#include <Moteur.h>
#include <Robot.h>

// Configuration des PIN Driver 1
const int Driver1_ENA = 11;   // Marron
const int Driver1_IN1 = 12;   // Rouge
const int Driver1_IN2 = 13;   // Orange

const int Driver1_ENB = 0;    // N/A
const int Driver1_IN3 = 0;    // N/A
const int Driver1_IN4 = 0;    // N/A

// Configuration des PIN Driver 2
const int Driver2_ENA = 7;    // Noir
const int Driver2_IN1 = 6;    // Blanc
const int Driver2_IN2 = 5;    // Gris

const int Driver2_ENB = 2;    // Vert
const int Driver2_IN3 = 4;    // Violet
const int Driver2_IN4 = 3;    // Bleu

Moteur moteur1(Driver1_ENA, Driver1_IN1, Driver1_IN2);
Moteur moteur2(Driver2_ENB, Driver2_IN3, Driver2_IN4);
Moteur moteur3(Driver2_ENA, Driver2_IN1, Driver2_IN2);
Robot robot (moteur1, moteur2, moteur3);

void setup() {
/*  moteur1.arret();
  moteur2.arret();
  moteur3.arret();
*/
  robot.arret();

 delay(2000);
}

void loop() {
  delay(500);

  robot.avance(100);

  robot.arret();

  delay(2000);

  robot.recule(50);

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
}
