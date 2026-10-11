#include <Arduino.h>

// Pin 2 - Button
// Pin 3 - Buzzer 1
// Pin 4 - Buzzer 2

void setup() {
    pinMode(2, INPUT_PULLUP);
    pinMode(3, OUTPUT);
    pinMode(4, OUTPUT);
}

void loop() {
    if (digitalRead(2) == LOW) {
        tone(3, 500);
        delay(210);
        tone(4, 500);
        delay(2000);
        noTone(3);
        noTone(4);
    }
}