#include <AFMotor.h>

// define the motors
AF_DCMotor motor_left(1);
AF_DCMotor motor_right(4);

void setup() {
  // motor speed can vary from 0 to 255
  motor_left.setSpeed(255);
  motor_right.setSpeed(255);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // make the car go forward
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
  Serial.println("FORWARD");
  delay(2000);

  // make the car turn left
  motor_left.run(BACKWARD);
  motor_right.run(FORWARD);
  Serial.println("LEFT");
  delay(2000);

  // make the car go backward
  motor_left.run(BACKWARD);
  motor_right.run(BACKWARD);
  Serial.println("BACKWARD");
  delay(2000);

  // make the car turn right
  motor_left.run(FORWARD);
  motor_right.run(BACKWARD);
  Serial.println("RIGHT");
  delay(2000);

  // make the car stop
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
  Serial.println("STOP");
  delay(2000);
}