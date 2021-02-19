const int ledIr = A3;
const int led=13;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledIr,INPUT);
  pinMode(led,OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int val = 0;
  
  val = analogRead(ledIr);

  // 1.3 V for 10, from sensor abaque
  if (val > 1023*1.3/5)
    digitalWrite(led,HIGH);
  else
    digitalWrite(led,LOW);

  Serial.print("value : ");
  Serial.print(val);
  
  delay(100);
  
}
