//capteur variable
int capteurAV=6;
int capteurAR=7;
int capteurAVG=8;
int capteurAVD=9;

//configuration des I/O
void setup(){
  pinMode(capteurAV, INPUT);
  pinMode(capteurAR, INPUT);
  pinMode(capteurAVG, INPUT);
  pinMode(capteurAVD, INPUT);
}

void loop()
{
  if (digitalRead(capteurAV) == HIGH || digitalRead(capteurAVG) == HIGH || digitalRead(capteurAVD) == HIGH) // les 3 capteur avant en état haut 
    reculer(1);
  else if (digitalRead(capteurAR) == HIGH) // capteur arriere en etat haut
    StopMoteur();
    else
      avancer();
    delay(100);
  }
  
// activer le moteur en sens inverse pendant la durée indiquer en parametre
void reculer(int duree){  
  // stop moteur 
  //marche arriere
  delay(duree)
  
}
// couper le Moteur (desactiver le pont H)
void StopMoteur()
{
  
}
// activer le moteur (pont en H sur on)
void avancer(){
  } 
