const int AOUTpin=0;  // la broche AOUT du capteur C0 va dans la broche analogique A0 de l'Arduino
const int DOUTpin=8;  // la broche DOUT du capteur C0 va dans la broche analogique D8 de l'Arduino
const int ledPin=13;  // l'anode de la LED se connecte à la broche D13 de l'Arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//fixe le débit en bauds
pinMode(DOUTpin, INPUT);//définit la broche comme une entrée pour l'arduino
pinMode(ledPin, OUTPUT);//met la broche en sortie de l'arduino
}

void loop() {
value= analogRead(AOUTpin);//lit la valeur analogique à partir de la broche AOUT du capteur de CO
limit= digitalRead(DOUTpin);//lit la valeur numérique à partir de la broche DOUT du capteur de CO
Serial.print("C0 value: ");
Serial.println(value);//imprime la valeur C0
Serial.print("Limit: ");
Serial.println(limit);//imprime la limite atteinte comme BASSE ou HAUTE (au-dessus ou en dessous)
delay(100);
if (limit == HIGH){
  Serial.print("Allarm");//si la limite a été atteinte
}
else{
  Serial.print("OK"); //si le seuil n'est pas revu à la baisse
}
}
