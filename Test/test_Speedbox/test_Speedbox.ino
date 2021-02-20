#include <SpeedBox.h>

SpeedBox speedBox = SpeedBox();

void setup() {
  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  speedBox.setPins(10, 11, 12);
  speedBox.addMotor1(7);
  speedBox.addMotor2(8);
  speedBox.addMotor3(9);
}

void loop() {
  speedBox.avance();
  Serial.print("Moteur 1 status : ");
  Serial.println(speedBox.getMoteur1Status());
  delay(100);
}
