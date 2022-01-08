#include "Servo.h"
#define SERVO_PIN 9   // Can use any PWM pin
#define POT_PIN A0    // Can use any analog pin
#define MIN_VALUE 0   // Minimum Servo position
#define MAX_VALUE 180 // Maximum Servo position

Servo servo;          // creates servo object used to control the servo motor
int value_pot = 0;    // Current value of the potentiometer
int value_servo = 0;  // Current servo position
int value_servo_old = 0; // Used to hold old servo value to look for change.
//===============================================================================
//  Initialization
//===============================================================================
void setup()
{
  servo.attach(SERVO_PIN); // assigns PWM pin to the servo object
  Serial.begin (9600);     // Set Serial Monitor window comm speed
}
//===============================================================================
//  Main
//===============================================================================
void loop()
{
  value_pot = analogRead(POT_PIN); // Reads value of the potentiometer. Return value = 0 to 1023
  value_servo = map(value_pot, 0, 1023, MIN_VALUE, MAX_VALUE); // remap pot value to servo value
  if (value_servo != value_servo_old) {   // Only do something if there's a change in the servo position
    servo.write(value_servo);        // Update servo position
    Serial.print("Pot Value: ");  // Update Serial Monitor window with what's going on
    Serial.print(value_pot);
    Serial.print("tServo Value: ");
    Serial.println(value_servo);
    value_servo_old = value_servo;
    delay(25); // give servo time to move
  }
}