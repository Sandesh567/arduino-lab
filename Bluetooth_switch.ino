int relayPin = 7; 
char incomingData; 

void setup() {
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
  
  // Set relay to OFF initially (Active Low)
  digitalWrite(relayPin, HIGH); 
  
  Serial.println("Bluetooth System Ready. Send '1' for ON, '0' for OFF.");
}

void loop() {
  if (Serial.available() > 0) {
    incomingData = Serial.read(); // Read the character from Bluetooth
    
    if (incomingData == '1') {
      digitalWrite(relayPin, LOW);  // Turn Bulb ON
      Serial.println("Bulb: ON");
    } 
    else if (incomingData == '0') {
      digitalWrite(relayPin, HIGH); // Turn Bulb OFF
      Serial.println("Bulb: OFF");
    }
  }
}
