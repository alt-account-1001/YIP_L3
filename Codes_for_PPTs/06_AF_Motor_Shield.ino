#include <AFMotor.h>

// define the motors
AF_DCMotor motor(1);

void setup() {
  // motor speed can vary from 0 to 255
  motor.setSpeed(255);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // move motor forward
  motor.run(FORWARD);
  delay(2000);

  // move motor backwards
  motor.run(BACKWARD);
  delay(2000);

  // stop the motor
  motor.run(RELEASE);
  delay(2000);
}