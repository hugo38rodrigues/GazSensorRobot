int  InfraBarrier = A5;
int relayPin = 9;                        // the number of the replay pin 

int  InfraBarrier = HIGH;                // Record InfraBarrier, and initial the state to high level
int relayPin = LOW;                      //Record replay state,and intitial the state to low level
int InfraBarrier = HIGH;                //record the InfraBarrier of last detection
long intlastChangeTime = 0; 


void setup() {  
pinMode(InfraBarrier, INPUT);
pinMode(relayPin, OUTPUT):              //set replay pin into output mode
digitalWrite(relayPin, replayState);    //Set the initial state of replay into "off"
Serial.begin(9600);                     //Initialize serial port, and set baud rate to 9600
}

void loop() {
  

}
