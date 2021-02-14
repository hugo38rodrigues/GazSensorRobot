void setup()
{
  	pinMode(9,OUTPUT);
 	pinMode(10,OUTPUT);
  	pinMode(6,OUTPUT);
 	pinMode(5,OUTPUT);
}

void loop()
{ digitalWrite(9,HIGH);
  digitalWrite(10,LOW);	
  digitalWrite(6,HIGH);
  digitalWrite(5,LOW);
  int mesure1 = analogRead (A0);
  analogWrite(11,mesure1 / 4);
  int mesure2 = analogRead (A1);
  analogWrite(3,mesure2 / 4);
}