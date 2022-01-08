#include <Ultrasonic.h>

int distance;
Ultrasonic ultraSonic(8, 9);  // Trig PIN, Echo PIN

void setup()
{
  Serial.begin(9600);
}

void loop()
{
    distance = ultraSonic.Ranging(CM);
    if (distance >= 17) {
      Serial.println("Too Long");
    } else {
      Serial.println("Too Short");
    }
    delay(1000);
}