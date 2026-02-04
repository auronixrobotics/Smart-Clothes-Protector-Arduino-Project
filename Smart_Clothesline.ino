#include <Servo.h>

Servo myServo;

const int rainSensorPin = 2;   // Digital pin from rain sensor
const int servoPin = 9;

int rainState = 0;

void setup() {
  pinMode(rainSensorPin, INPUT);
  myServo.attach(servoPin);
  
  myServo.write(0);  // Start servo at 0 degree
}

void loop() {
  rainState = digitalRead(rainSensorPin);

  // Most rain sensors output LOW when rain is detected
  if (rainState == LOW) {
    myServo.write(90);   // Move servo to 90 degrees
  } else {
    myServo.write(0);    // Move servo back to 0 degrees
  }

  delay(500); // Small delay for stability
}
