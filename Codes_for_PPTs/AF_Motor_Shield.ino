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
  Serial.println("FORWARD");
  motor_left.run(FORWARD);
  motor_right.run(FORWARD);
  delay(2000);

  // make the car turn left
  Serial.println("LEFT");
  motor_left.run(BACKWARD);
  motor_right.run(FORWARD);
  delay(2000);

  // make the car go backward
  Serial.println("BACKWARD");
  motor_left.run(BACKWARD);
  motor_right.run(BACKWARD);
  delay(2000);

  // make the car turn right
  Serial.println("RIGHT");
  motor_left.run(FORWARD);
  motor_right.run(BACKWARD);
  delay(2000);

  // make the car stop
  Serial.println("STOP");
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
  delay(2000);
}