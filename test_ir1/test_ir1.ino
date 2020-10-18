//IR detector variables
const int PinIRTape = 7;
const int PinLed = 8;

void setup() {
    pinMode(PinIRTape, INPUT);
    pinMode(PinLed,OUTPUT );
}

void loop() {
	int val = 0;
	val = digitalRead(PinIRTape);
  	if (val == HIGH){
		digitalWrite(PinLed, HIGH);
  	}
  	else {
		digitalWrite(PinLed, LOW);
	}
   	delay(100);
}