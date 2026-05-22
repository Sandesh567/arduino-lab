// Speed Control Pins (Must be connected to PWM Pins 6 and 9)
const int ENA = 6; 
const int ENB = 9; 

// Direction Control Pins
const int IN1 = 2; 
const int IN2 = 3; 
const int IN3 = 4; 
const int IN4 = 5; 

// Default starting speed (0 to 255)
int carSpeed = 200; 

char command; 

void setup() {
  // Initialize all pins as outputs
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  
  // Make sure car is stopped on boot
  stopMotors();

  // Start hardware serial communication line at 9600 baud rate
  Serial.begin(9600);
}

void loop() {
  // Read cleanly from the native hardware serial port
  if (Serial.available() > 0) {
    command = Serial.read(); 

    // Handle Speed Sliders first ('0' to '9', and 'q' for 100% max speed)
    if (command >= '0' && command <= '9') {
      // Maps app values '0'-'9' smoothly to PWM values 0-250
      carSpeed = (command - '0') * 25; 
    }
    else if (command == 'q') {
      carSpeed = 255; // Maximum velocity
    }

    // Handle Directional Control Commands
    switch (command) {
      case 'F': moveForward();      break;
      case 'B': moveBackward();     break;
      case 'L': turnLeft();         break;
      case 'R': turnRight();        break;
      case 'G': forwardLeft();      break;
      case 'I': forwardRight();     break;
      case 'H': backwardLeft();     break;
      case 'J': backwardRight();    break;
      case 'S': stopMotors();       break;
    }
  }
}

// ---- Direction Logic Blocks ----

void moveForward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void moveBackward() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void turnLeft() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void turnRight() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

// ---- Diagonal / Smooth Turning Logic ----

void forwardLeft() {
  analogWrite(ENA, carSpeed / 2); // Slow down inner wheel
  analogWrite(ENB, carSpeed);     // Keep outer wheel fast
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void forwardRight() {
  analogWrite(ENA, carSpeed);     // Keep outer wheel fast
  analogWrite(ENB, carSpeed / 2); // Slow down inner wheel
  digitalWrite(IN1, HIGH); digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH); digitalWrite(IN4, LOW);
}

void backwardLeft() {
  analogWrite(ENA, carSpeed / 2);
  analogWrite(ENB, carSpeed);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void backwardRight() {
  analogWrite(ENA, carSpeed);
  analogWrite(ENB, carSpeed / 2);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, HIGH);
}

void stopMotors() {
  analogWrite(ENA, 0);
  analogWrite(ENB, 0);
  digitalWrite(IN1, LOW);  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);  digitalWrite(IN4, LOW);
}
