#include <Servo.h>

const int joyXPin = A1;    // Joystick Left/Right
const int goalieServoPin = 3; // Goalie Servo on Pin 3

Servo goalieServo;

// Goalie limits so it doesn't smash into the cardboard posts!
const int LEFT_LIMIT = 45;   // Adjust if needed
const int RIGHT_LIMIT = 135;  // Adjust if needed
const int CENTER_POS = 90;

void setup() {
  goalieServo.attach(goalieServoPin);
  goalieServo.write(CENTER_POS); // Start in the middle of the goal
  
  Serial.begin(9600);
}

void loop() {
  int xVal = analogRead(joyXPin); // Read joystick (0 to 1023)

  // Map joystick movement to the goalie sweep range
  int goalieAngle = map(xVal, 0, 1023, LEFT_LIMIT, RIGHT_LIMIT);

  // Send angle to the Goalie Servo
  goalieServo.write(goalieAngle);

  // Print position to check in Serial Monitor
  Serial.print("Goalie Position (Degrees): ");
  Serial.println(goalieAngle);

  delay(15); // Smooth mechanical movement
}
