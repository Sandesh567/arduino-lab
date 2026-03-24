const int trigPin = 11;
const int echoPin = 12;
const int buzzerPin = 8;

// Musical Frequencies (Hz)
const int NOTE_C = 262;
const int NOTE_D = 294;
const int NOTE_E = 330;
const int NOTE_F = 349;
const int NOTE_G = 392;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH);
  int distance = duration * 0.034 / 2;

  // Height brackets for specific piano notes
  if (distance >= 5 && distance < 10) {
    tone(buzzerPin, NOTE_C); // 5-10cm
  } else if (distance >= 10 && distance < 15) {
    tone(buzzerPin, NOTE_D); // 10-15cm
  } else if (distance >= 15 && distance < 20) {
    tone(buzzerPin, NOTE_E); // 15-20cm
  } else if (distance >= 20 && distance < 25) {
    tone(buzzerPin, NOTE_F); // 20-25cm
  } else if (distance >= 25 && distance < 30) {
    tone(buzzerPin, NOTE_G); // 25-30cm
  } else {
    noTone(buzzerPin); // Silence outside bounds
  }

  delay(100); 
}
