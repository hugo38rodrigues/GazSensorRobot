//IR detector variables
const int PinIRTape1 = 10;
const int PinIRTape2 = 9;
const int PinIRTape3 = 8;

const int PinLed1 = 5;
const int PinLed2 = 6;
const int PinLed3 = 7;

void setup() {
  pinMode(PinIRTape1, INPUT);
  pinMode(PinIRTape2, INPUT);
  pinMode(PinIRTape3, INPUT);
  pinMode(PinLed1, OUTPUT );
  pinMode(PinLed2, OUTPUT );
  pinMode(PinLed3, OUTPUT );
}

void loop() {
  int val1 = 0;
  int val2 = 0;
  int val3 = 0;

  val1 = digitalRead(PinIRTape1);
  val2 = digitalRead(PinIRTape2);
  val3 = digitalRead(PinIRTape3);

  if (val1 == LOW ) {
    digitalWrite(PinLed1, HIGH);
  }
  if (val2 == LOW ) {
    digitalWrite(PinLed2, HIGH);
  }

  if ( val3 == LOW) {
    digitalWrite(PinLed3, HIGH);
  }

  delay(100);
}
