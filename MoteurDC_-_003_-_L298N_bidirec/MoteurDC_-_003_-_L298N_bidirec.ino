// Ardwinner Moteur DC-003-L298N bidirectionnel.
// code Arduino pour contrôler un moteur continu à partir d'un module L298N et de le faire tourner dans un sens pendant 5 secondes, puis l'arrête pendant 2 secondes, et le fait 
// repartir dans l'autre sens pendant 5 secondes ; le tout à une vitesse de 200 sur 255.

// Déclaration des variables et des constantes ------------------------------------------------------------------------------------------------------------------------------------
int enA = 10;                   // crée une variable de type "int", nommée "enA" et attachée à la Broche 10, qui permet de gérer la vitesse du moteur.
int in1 = 9;                    // crée une variable de type "int", nommée "in1" et attachée à la Broche 9, qui permet de gérer le sens de rotation.
int in2 = 8;                    // crée une variable de type "int", nommée "in2" et attachée à la Broche 8, qui permet de gérer l'autre sens de rotation.


void setup() {              // Void Setup ------------------------------------------------------------------------------------------------------------------------------------------
  pinMode(enA, OUTPUT);         // indique que la broche de la variable "enA" donc ici la PIN 10, est une sortie.
  pinMode(in1, OUTPUT);         // indique que la broche de la variable "in1" donc ici la PIN 9, est une sortie.
  pinMode(in2, OUTPUT);         // indique que la broche de la variable "in2" donc ici la PIN 8, est une sortie.
}


void loop() {               // Void Loop -------------------------------------------------------------------------------------------------------------------------------------------
  digitalWrite(in1,HIGH);      // envoie l'électricité dans la broche in1 (donc la PIN 9)ce qui fait donc tourner le moteur dans le sens de rotation de in1.
  digitalWrite(in2,LOW);       // en mettant la broche in2 à l'état bas, la carte n'injecte pas d'électricité, le moteur peut donc continuer à tourner dans le sens de in1.
  analogWrite(enA,200);        // défini la vitesse du moteur, ici 200 sur un maximum de 255 (échélle comprise entre 0 et 255, car cela correspond à 8 bits soit 1 octet).
  delay(5000);                 // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes.

  digitalWrite(in1,LOW);       // en mettant la broche in1 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
  digitalWrite(in2,LOW);       // en mettant la broche in2 à l'état bas, la carte n'injecte pas d'électricité, le moteur est donc à l'arrêt.
  delay(2000);                 // créer un delais où le moteur ne tourne pas pendant 2 secondes. 
 
  digitalWrite(in1,LOW);       // met la broche in1 à l'état bas, la carte n'injecte pas d'électricité, le moteur ne tourne pas dans le sens de in1.
  digitalWrite(in2,HIGH);      // envoie l'électricité dans la broche in2 (donc la PIN 8)ce qui fait donc tourner le moteur dans le sens de rotation de in2.
  analogWrite(enA,200);        // défini la vitesse du moteur, ici 200 sur un maximum de 255 (échélle comprise entre 0 et 255, car cela correspond à 8 bits soit 1 octet).
  delay(5000);                 // créer un delais de 5 secondes, donc le moteur tourne pendant 5 secondes. 
}

