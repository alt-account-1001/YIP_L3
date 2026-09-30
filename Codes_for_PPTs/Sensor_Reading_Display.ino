#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int sensorPin = A0;
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
    pinMode(sensorPin, INPUT);
    Serial.begin(9600);
    lcd.init();
    lcd.backlight();
}

void loop() {
    // Reading the value from the sensor
    int sensorValue = digitalRead(sensorPin);   // for digital sensor
    int analogValue = analogRead(sensorPin);    // for analog sensor
    
    // Printing the value to the serial monitor
    Serial.print("Value = ");
    Serial.println(sensorValue);
    
    // Displaying the value on the LCD
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Value = ");
    lcd.print(sensorValue);

    // Delay for smooth performance
    delay(100);
}