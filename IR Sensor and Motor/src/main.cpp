// digital pin 13 - servo
// digital pin 3 - ir sensor

#include <Arduino.h>
#include <Servo.h>
int ir_threshold = 220;
int MotorAngle = 60;
int currentTime = 0;
volatile unsigned long lastInterruptTime = 0;
unsigned long previousLogTime = 0;
unsigned long previousCheckTime = 0;
Servo servoo;

void handleIRinterrupt() {
  unsigned long currentTime = millis();
  if (currentTime - lastInterruptTime > 50) {
    lastInterruptTime = currentTime;
  
    int targetAngle = (digitalRead(3) == LOW) ? 155 : 60;

  
    if (targetAngle != MotorAngle) {
      servoo.write(targetAngle);
      MotorAngle = targetAngle;
    }
  }
}

void setup() {
pinMode(13, OUTPUT);
pinMode(3, INPUT);
Serial.begin(9600);
servoo.attach(13);
attachInterrupt(digitalPinToInterrupt(3), handleIRinterrupt, CHANGE);
}

void logging() {
  unsigned long currentTime = millis();
  if (currentTime - previousLogTime >= 500) {
    if (digitalRead(3) == LOW) {
    Serial.println("Obstacle Detected");
    Serial.println(MotorAngle);
    }
    else if (digitalRead(3) == HIGH) {
    Serial.println("Clear");
    Serial.println(MotorAngle);
    }
    previousLogTime = currentTime;
    }
}
void checking() {
if (digitalRead(3) == LOW) {
  if (MotorAngle == 155) {
  servoo.write(60);
   MotorAngle = 60;

 }
 }
}


void loop() {
  logging();
}