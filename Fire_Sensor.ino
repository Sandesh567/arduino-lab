const int flamePin = 2; // Flame sensor connected to Digital Pin 2
const int redPin = 9;   // Red LED connected to Digital Pin 9
const int greenPin = 10; // Green LED connected to Digital Pin 10

void setup() {
  pinMode(flamePin, INPUT);
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  
  Serial.begin(9600); // Opens the serial monitor so you can see readings
}

void loop() {
  int flameStatus = digitalRead(flamePin);

  // Note: Most IR flame sensors send a LOW (0) signal when they see fire!
  if (flameStatus == LOW) { 
    Serial.println("🔥 FLAME DETECTED! Lights are RED");
    digitalWrite(redPin, HIGH);   // Turn Red On
    digitalWrite(greenPin, LOW);  // Turn Green/Blue Off
  } else {
    Serial.println("✅ Safe. Lights are GREEN");
    digitalWrite(redPin, LOW);    // Turn Red Off
    digitalWrite(greenPin, HIGH); // Turn Green/Blue On
  }
  
  delay(200); // A tiny pause to keep the Arduino happy
}
