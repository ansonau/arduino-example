/*
  Exercise 360 degree Servo motor
  Simply runs servo in one direction for 2 seconds and then reverses direction
  Uses built-in Servo.h library
*/
#include "Servo.h"
#define SERVO_PIN 9   // Can use any PWM pin

Servo servo;          // creates servo object used to control the servo motor
//===============================================================================
//  Initialization
//===============================================================================
void setup()
{
  servo.attach(SERVO_PIN); // assigns PWM pin to the servo object
}
//===============================================================================
//  Main
//===============================================================================
void loop()
{
  servo.write(0); //Spin in one direction
  delay(3000);
  servo.write(90); // Stop
  delay(500);
  servo.write(180);  // Spin in opposite direction
  delay(3000);
  servo.write(90);  // Stop
  delay(500);
}