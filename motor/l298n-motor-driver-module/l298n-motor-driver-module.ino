// Definitions L298N H Bridge to connect arduino input pins
#define in1 4 // Motor Left - Negative
#define in2 5 // Motor Left - Positive
#define in3 6 // Motor Right - Negative
#define in4 7 // Motor Right - Positive
#define enA 8 // Needs to be a PWM pin to be able to control motor speed
#define enB 9 // Needs to be a PWM pin to be able to control motor speed

void setup()
{
  // Set L298N to output pins
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  pinMode(enA, OUTPUT);
  pinMode(enB, OUTPUT);
}

void loop()
{
    // Forward
    digitalWrite(in1, HIGH); // Motor Right - clockwise
    digitalWrite(in2, LOW);
    digitalWrite(in3, LOW); // Motor Left - counter-clockwise
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255); // Sets speed variable via PWM (0-255)
    analogWrite(enB, 255); // Sets speed variable via PWM (0-255)
    delay(1000);
    // Backward
    digitalWrite(in1, LOW); // Motor Right - counter-clockwise
    digitalWrite(in2, HIGH);
    digitalWrite(in3, HIGH); // Motor Left - clockwise
    digitalWrite(in4, LOW);
    analogWrite(enA, 255); // Sets speed variable via PWM (0-255)
    analogWrite(enB, 255); // Sets speed variable via PWM (0-255)
    delay(1000);
    // Turn Left
    digitalWrite(in1, HIGH); // Motor Right - clockwise
    digitalWrite(in2, LOW);
    digitalWrite(in3, HIGH); // Motor Left - clockwise
    digitalWrite(in4, LOW);
    analogWrite(enA, 255); // Sets speed variable via PWM (0-255)
    analogWrite(enB, 255); // Sets speed variable via PWM (0-255)
    delay(1000);
    // Turn Right
    digitalWrite(in1, LOW); // Motor Right - counter-clockwise
    digitalWrite(in2, HIGH);
    digitalWrite(in3, LOW); // Motor Left - counter-clockwise
    digitalWrite(in4, HIGH);
    analogWrite(enA, 255); // Sets speed variable via PWM (0-255)
    analogWrite(enB, 255); // Sets speed variable via PWM (0-255)
    delay(1000);
}