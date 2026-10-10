#include <AFMotor.h>

// define the motors
AF_DCMotor motor_left(1);
AF_DCMotor motor_right(4);

// define the channel pins
const int channel_2 = A0;
const int channel_4 = A1;

void setup() {
  // set the pin modes
  pinMode(channel_1, INPUT);
  pinMode(channel_2, INPUT);

  // motor speed can vary from 0 to 255
  motor_left.setSpeed(255);
  motor_right.setSpeed(255);

  // initialize the serial port
  Serial.begin(9600);
}

void loop() {
  // read the values
  int propulsion = pulseIn(channel_2, HIGH);
  int steering   = pulseIn(channel_4, HIGH);

  // show the values on the serial monitor
  Serial.print("\nch1: ");
  Serial.print(value_LR);
  Serial.print("\tch2: ");
  Serial.print(value_UD);
  Serial.print("\n----------------");

  // release all motors
  motor_left.run(RELEASE);
  motor_right.run(RELEASE);
  delay(100);

  // move car based on the readings
  if(propulsion > 1700){
    // move forward
    motor_left.run(FORWARD);
    motor_right.run(FORWARD);
    Serial.println("FORWARD");
  }
  else if(propulsion < 1300){
    // move backward
    motor_left.run(BACKWARD);
    motor_right.run(BACKWARD);
    Serial.println("BACKWARD");
  }
  else if(steering > 1700){
    // turn right
    motor_left.run(FORWARD);
    motor_right.run(BACKWARD);
    Serial.println("RIGHT");
  }
  else if(steering < 1300){
    // turn left
    motor_left.run(BACKWARD);
    motor_right.run(FORWARD);
    Serial.println("LEFT");
  }

  // delay for smooth performance
  delay(1000);
}