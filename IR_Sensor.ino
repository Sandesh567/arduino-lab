const int irSensorPin = 3;  // IR Sensor OUT connected to D3
const int buzzerPin = 10;   // Buzzer (+) connected to D10

void setup() {
  pinMode(irSensorPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Social Distancing Alarm Active...");
}

void loop() {
  // Read the IR sensor state
  int isTooClose = digitalRead(irSensorPin);

  // In IR modules: LOW means 'Object Detected'
  if (isTooClose == LOW) {
    Serial.println("ALARM: Someone is too close!");
    
    // Sound a continuous 1000Hz tone
    tone(buzzerPin, 1000); 
  } 
  else {
    // Stop the sound when the person moves away
    noTone(buzzerPin);
  }
  
  delay(50); // Small delay for stability
}
