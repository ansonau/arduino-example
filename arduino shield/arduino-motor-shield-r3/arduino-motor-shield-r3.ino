// Definitions L298P Full Bridge to connect arduino input pins
// Init for arduino motor shield left channel
const int dirL = 12;
const int brakeL = 9;
const int pmwL = 3;
// Init for arduino motor shield right channel
const int dirR = 13;
const int brakeR = 8;
const int pmwR = 11;

void setup()
{
  // Set L298P to output pins
pinMode(dirL, OUTPUT);
pinMode(brakeL, OUTPUT);
pinMode(pmwL, OUTPUT);
pinMode(dirR, OUTPUT);
pinMode(brakeR, OUTPUT);
pinMode(pmwR, OUTPUT);
}

void loop()
{
    // Forward
    digitalWrite(dirL, LOW);
    digitalWrite(dirR, HIGH);
    digitalWrite(brakeL, LOW);
    digitalWrite(brakeR, LOW);
    analogWrite(pmwL, 255); // Sets speed variable via PWM (0-255)
    analogWrite(pmwR, 255); // Sets speed variable via PWM (0-255)
    delay(1000);

    // Backward
    digitalWrite(dirL, HIGH);
    digitalWrite(dirR, LOW);
    digitalWrite(brakeL, LOW);
    digitalWrite(brakeR, LOW);
    analogWrite(pmwL, 255); // Sets speed variable via PWM (0-255)
    analogWrite(pmwR, 255); // Sets speed variable via PWM (0-255)
    delay(1000);

    // Turn Left
    digitalWrite(dirL, HIGH);
    digitalWrite(dirR, HIGH);
    analogWrite(pmwL, 255); // Sets speed variable via PWM (0-255)
    analogWrite(pmwR, 255); // Sets speed variable via PWM (0-255)
    delay(1000);

    // Turn Right
    digitalWrite(dirL, LOW);
    digitalWrite(dirR, LOW);
    analogWrite(pmwL, 255); // Sets speed variable via PWM (0-255)
    analogWrite(pmwR, 255); // Sets speed variable via PWM (0-255)
    delay(1000);

    // Turn Right
    digitalWrite(dirL, LOW);
    digitalWrite(dirR, LOW);
    analogWrite(pmwL, 255); // Sets speed variable via PWM (0-255)
    analogWrite(pmwR, 255); // Sets speed variable via PWM (0-255)
    delay(1000);
}