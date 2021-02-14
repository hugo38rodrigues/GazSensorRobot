const int pinIR = 4;		
const int pinMoteur1F =9;
const int pinMoteur1B =10;
const int pinMoteur2F =6;
const int pinMoteur2B =5;
const int pinActivationH1 = 11; 
const int pinActivationH2 = 3; 

void setup()
{	pinMode(pinIR,INPUT);		
 	pinMode(pinMoteur1F,OUTPUT);
 	pinMode(pinMoteur1B,OUTPUT);
  pinMode(pinMoteur2F,OUTPUT);
	pinMode(pinMoteur2B,OUTPUT);
	pinMode(pinActivationH1,OUTPUT);
 	pinMode(pinActivationH2,OUTPUT);
 	
 	digitalWrite(pinMoteur1F,HIGH);
  digitalWrite(pinMoteur2F,HIGH);
	digitalWrite(pinMoteur1B,LOW);	
  digitalWrite(pinMoteur2B,LOW);
 	
}

void loop(){ 
    if (digitalRead(pinIR) == LOW){	//Pas de détection 
      	// le moteur avance
      	digitalWrite(11,HIGH);			
		digitalWrite(3,HIGH);
    }
  	else {	//détection
    	//les moteur s'arrete
      	digitalWrite(11,LOW);			
      	digitalWrite(3,LOW);
  	}
  	delay(100);
}
