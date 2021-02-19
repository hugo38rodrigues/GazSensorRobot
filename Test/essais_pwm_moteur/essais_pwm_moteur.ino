const int pinActivation=5;
const int pinMoteurM1=6;
const int pinMoteurM2=7;

void setup() {
  pinMode(pinActivation, OUTPUT);
  pinMode(pinMoteurM1, OUTPUT);
  pinMode(pinMoteurM2, OUTPUT);
}

void loop() {
  
 
  //analogWrite(pinActivation,map(100, 0, 100, 0, 255));
  digitalWrite(pinActivation, HIGH);
  digitalWrite(pinMoteurM1, LOW);
  digitalWrite(pinMoteurM2,HIGH);
 
  delay(1000);
}
