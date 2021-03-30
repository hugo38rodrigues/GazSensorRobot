//Moteur variable IR variable Pont H variable
//const int pinIR = 4;    

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

// PIN de pilotage du sens de rotation
const int moteur1_H = Driver1_IN1;
const int moteur1_A = Driver1_IN2;

const int moteur2_H = Driver2_IN3;
const int moteur2_A = Driver2_IN4;

const int moteur3_H = Driver2_IN1;  
const int moteur3_A = Driver2_IN2;

// PIN d'activation des ponts en H
const int pinActivation1 = Driver1_ENA;
const int pinActivation2 = Driver2_ENB;
const int pinActivation3 = Driver2_ENA;

// configuration des I/O
void setup()
{   
   // Déclaration des types d'I/O
  //pinMode(pinIR,INPUT);   
    pinMode(moteur1_H,OUTPUT);
    pinMode(moteur1_A,OUTPUT);
    pinMode(moteur2_H,OUTPUT);
    pinMode(moteur2_A,OUTPUT);
    pinMode(moteur3_H,OUTPUT);
    pinMode(moteur3_A,OUTPUT);

    pinMode(pinActivation1,OUTPUT);
    pinMode(pinActivation2,OUTPUT);
    pinMode(pinActivation3,OUTPUT);
  
    // Marche avant
    digitalWrite(moteur1_H,LOW);
    digitalWrite(moteur1_A,HIGH);
    
    digitalWrite(moteur2_H,LOW);  
    digitalWrite(moteur2_A,HIGH);

    digitalWrite(moteur3_H,LOW);  
    digitalWrite(moteur3_A,HIGH);

   // Désactivation des moteurs
    digitalWrite(pinActivation1,LOW);
    digitalWrite(pinActivation2,LOW);
    digitalWrite(pinActivation3,LOW);
    
    delay(2000);
}

// Programme principal
void loop(){ 
    digitalWrite(pinActivation1,HIGH);
    digitalWrite(pinActivation2,HIGH);
    digitalWrite(pinActivation3,HIGH);
    delay(2000);
    
    digitalWrite(pinActivation1,LOW);
    digitalWrite(pinActivation2,LOW);
    digitalWrite(pinActivation3,LOW);
    
    delay(2000);
}


void moteur1_go (bool horaire) {
  if (horaire) {
    digitalWrite(moteur1_H,LOW);
    digitalWrite(moteur1_A,HIGH);
  }
  else {
    digitalWrite(moteur1_H,HIGH);
    digitalWrite(moteur1_A,LOW);
  }
  digitalWrite(pinActivation1,HIGH);
}

void moteur1_stop () {
  digitalWrite(pinActivation1,LOW);
}
