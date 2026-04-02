int gasPin = A0; // Connect A0 of sensor to A0 of Arduino

void setup() {
  Serial.begin(9600);
  Serial.println("Warming up sensor...");
  delay(20000); // Give it a short warm-up
}

void loop() {
  int sensorValue = analogRead(gasPin); 
  
  Serial.print("Gas Level: ");
  Serial.println(sensorValue);

  if(sensorValue > 400) { // Adjust this threshold based on testing
    Serial.println("ALERT: Gas Detected!");
  }
  
  delay(500);
}
