#include <Servo.h>
#include <Adafruit_MotorShield.h>

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Connect a stepper motor with 200 steps per revolution (1.8 degree)
// to motor port #2 (M3 and M4)
Adafruit_StepperMotor *myStepper = AFMS.getStepper(200, 2);
Adafruit_DCMotor *myMotor = AFMS.getMotor(1);

Servo servo1;

void setup() {
  Serial.begin(9600);           // set up Serial library at 9600 bps
  Serial.println("MMMMotor party!");

  if (!AFMS.begin()) {         // create with the default frequency 1.6KHz
  // if (!AFMS.begin(1000)) {  // OR with a different frequency, say 1KHz
    Serial.println("Could not find Motor Shield. Check wiring.");
    while (1);
  }
  Serial.println("Motor Shield found.");

  // Attach a servo to pin #10
  servo1.attach(10);

  // turn on motor M1
  myMotor->setSpeed(200);
  myMotor->run(RELEASE);

  // setup the stepper
  myStepper->setSpeed(10);  // 10 rpm
}

int i;
void loop() {
  myMotor->run(FORWARD);
  for (i=0; i<255; i++) {
    servo1.write(map(i, 0, 255, 0, 180));
    myMotor->setSpeed(i);
    myStepper->step(1, FORWARD, INTERLEAVE);
    delay(3);
 }

 for (i=255; i!=0; i--) {
    servo1.write(map(i, 0, 255, 0, 180));
    myMotor->setSpeed(i);
    myStepper->step(1, BACKWARD, INTERLEAVE);
    delay(3);
 }

  myMotor->run(BACKWARD);
  for (i=0; i<255; i++) {
    servo1.write(map(i, 0, 255, 0, 180));
    myMotor->setSpeed(i);
    myStepper->step(1, FORWARD, DOUBLE);
    delay(3);
 }

  for (i=255; i!=0; i--) {
    servo1.write(map(i, 0, 255, 0, 180));
    myMotor->setSpeed(i);
    myStepper->step(1, BACKWARD, DOUBLE);
    delay(3);
 }
}