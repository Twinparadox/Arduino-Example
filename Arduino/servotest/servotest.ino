#include <Servo.h>
Servo ser;
int servoPin=9;
void setup() {
  ser.attach(servoPin,600,2400);
  ser.write(90);
}

void loop() {
}
