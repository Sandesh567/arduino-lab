// Define the pins
int ledPin = 13;
int buzzerPin = 10;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  // --- ON PHASE ---
  digitalWrite(ledPin, HIGH);   // LED turns on
  tone(buzzerPin, 1500);        // Buzzer makes a high-pitch sound
  delay(300);                   // Wait 0.3 seconds

  // --- OFF PHASE ---
  digitalWrite(ledPin, LOW);    // LED turns off
  noTone(buzzerPin);            // Buzzer goes silent
  delay(300);                   // Wait 0.3 seconds
}
