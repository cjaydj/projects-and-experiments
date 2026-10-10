#include <Arduino.h>

// Pin 52 - Button
// Pin 50 - Buzzer 1
// Pin 53 - Buzzer 2

void setup() {
    pinMode(52, INPUT_PULLUP);
    pinMode(50, OUTPUT);
    pinMode(53,OUTPUT);
}

void loop() {
    if (digitalRead(52) == LOW) {
        tone(50, 500);
        delay(200);
        tone(53, 500);
        delay(2000);
        noTone(50);
        noTone(53);
    }
}