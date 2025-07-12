int ledPins[] = {11, 12, 13};  // LED pins
int btnPins[] = {2, 3, 4};     // Button pins
bool states[] = {LOW, LOW, LOW}; // LED states

void setup() {
  for (int i = 0; i < 3; i++) {
    pinMode(ledPins[i], OUTPUT);
    pinMode(btnPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(btnPins[i]) == LOW) {  // Button pressed (active LOW)
      delay(10);  // Debounce delay
      if (digitalRead(btnPins[i]) == LOW) {
        while (digitalRead(btnPins[i]) == LOW); // Wait for button release
        delay(10); // Debounce delay after release
        while (digitalRead(btnPins[i]) == LOW); // Extra check (optional)

        states[i] = !states[i];  // Toggle LED state
        digitalWrite(ledPins[i], states[i]);
      }
    }
  }
}
