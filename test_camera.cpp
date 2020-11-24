#include <Wire.h>
#define BAUD_RATE 19200
#define CHAR_BUF 128
#include <Servo.h>
int ledPin = 11;      // select the pin for the LED
int pos_value_1 = 0;
int pos_value_2 = 0;
int pos_value_3 = 0;
int X_value = 0;  // center x
int Y_value = 0;  // center Y
int box_value = 0;  // Size box (distance)
int x_pos = 90;
int y_pos = 90;
Servo servo_x;
Servo servo_y;

void setup() {
pinMode(ledPin, OUTPUT);
servo_x.attach(8);
servo_y.attach(9);
Serial.begin(BAUD_RATE);
Serial.print("Test");
Wire.begin();

delay(1000); // Give the OpenMV Cam time to bootup.
}
void loop()
{
int32_t temp = 0;
char buff[CHAR_BUF] = {0};
Wire.requestFrom(0x12, 2);
if(Wire.available() == 2)
{
   // got length?
temp = Wire.read() | (Wire.read() << 8);
delay(1);
 // Give some setup time...
Wire.requestFrom(0x12, temp);
if(Wire.available() == temp)
{
   // got full message?
temp = 0;
while(Wire.available()) buff[temp++] = Wire.read();
