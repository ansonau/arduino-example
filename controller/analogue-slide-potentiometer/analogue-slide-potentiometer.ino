int slidePot_pin = A0;
int slidePot = 0;

void setup()
{
  Serial.begin(9600);
}


void loop()
{
    slidePot = analogRead(A0);
    slidePot = (map(slidePot,0,1023,0,180));
    Serial.println(slidePot);
    delay(1000);
}