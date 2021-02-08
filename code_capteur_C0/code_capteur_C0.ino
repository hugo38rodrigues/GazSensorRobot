const int AOUTpin=0;  // the AOUT pin of the C0 sensor goes into analog pin A0 of the Arduino
const int BOUTpin=8;  // the BOUT pin of the C0 sensor goes into analog pin B8 of the Arduino
const int ledPin=13;  // the anode of the LED connects to difgital pin D13 of the arduino

int limit;
int value;

void setup() {
Serial.begin(9600);//sets the baud rate
pinMode(BOUTpin, INPUT);//sets the pin as an input to the arduino
pinMode(ledPin, OUTPUT);//sets the pin as an output to the arduino
}

void loop() {
value= analogRead(AOUTpin);//reads the analog valuefrom the CO sensor's AOUT pin
limit= digitalRead(BOUTpin);//reads the digital value from the CO sensor's BOUT pin
Serial.print("C0 value: ");
Serial.println(value);//prints the C0 value
Serial.print("Limit: ");
Serial.println(limit);//prints the limit reached as either LOW or HIGH (above or underneath)
delay(100);
if (limit == HIGH){
  Serial.print("Allarm");//if  limit has been reached
}
else{
  Serial.print("OK"); //if threshold not reched
}
}
