byte LEDPin = 11;       //PWM Output pin for LED
byte capSensePin = 2;   //Pin to attach to capacitive sensor
byte mode = 0;         //Determines LED brightness. 0 is off. Varies between 0 and 255.
byte touchThreshold = 100; //Minimum capacitive touch value  in order to trigger next  mode
byte targetBrightness = 0; // Set power on brightness
byte currentBrightness = 0; //variable to compare brightness

void setup(){
  Serial.begin(9600);
  pinMode(LEDPin, OUTPUT);  //Set LEDPin to output mode
}

void loop(){
  if (readCapacitivePin(capSensePin) > touchThreshold) {  //If the value of capSensePin exceeds touchThreshold then do…
  delay(250);
  //Button Debounce. How would I remove this break using millis()??
  mode++; //If the above threshold is exceeded, then increase the value of mode by 1
  //This next section outlines the different LED brightness levels. 255 is all the way one. 128 is half brightness.
  if (mode > 3) mode = 0;  //If the value for mode is > 3 then set value of mode to 0.
  if (mode == 0) targetBrightness = 0;
  if (mode == 1) targetBrightness = 255;
  if (mode == 2) targetBrightness = 128;
  if (mode == 3) targetBrightness = 64;
  Serial.print(“The current mode is…”); //Serial monitor to bebug mode increases
  Serial.println(mode);  //print value of mode to seial monitor
}

//Fade control
if (targetBrightness > currentBrightness) currentBrightness++;
  if (targetBrightness < currentBrightness) currentBrightness–;
  analogWrite(LEDPin, currentBrightness);
  delay(3); //determines how rapidly the fade occurs.
  //Serial.println(currentBrightness);
  // THIS POINT ONWARD I DIDN’T WRITE.
  // Every 500 ms, print the value of the capacitive sensor
  if ( (millis() % 500) == 0){
  Serial.print(“Capacitive Sensor on Pin 2 reads: “);
  Serial.println(readCapacitivePin(capSensePin));
  }
}

// readCapacitivePin
//  Input: Arduino pin number
//  Output: A number, from 0 to 17 expressing
//          how much capacitance is on the pin
//  When you touch the pin, or whatever you have
//  attached to it, the number will get higher
//  In order for this to work now,
// The pin should have a 1+Megaohm resistor pulling
//  it up to +5v.
uint8_t readCapacitivePin(int pinToMeasure){
// This is how you declare a variable which
//  will hold the PORT, PIN, and DDR registers
//  on an AVR
volatile uint8_t* port;
volatile uint8_t* ddr;
volatile uint8_t* pin;
// Here we translate the input pin number from
//  Arduino pin number to the AVR PORT, PIN, DDR,
//  and which bit of those registers we care about.
byte bitmask;
if ((pinToMeasure >= 0) && (pinToMeasure <= 7)){
  port = &PORTD;
  ddr = &DDRD;
  bitmask = 1 << pinToMeasure;
  pin = &PIND;
}
if ((pinToMeasure > 7) && (pinToMeasure <= 13)){
  port = &PORTB;
  ddr = &DDRB;
  bitmask = 1 << (pinToMeasure – 8);
  pin = &PINB;
}
if ((pinToMeasure > 13) && (pinToMeasure <= 19)){
  port = &PORTC;
  ddr = &DDRC;
  bitmask = 1 << (pinToMeasure – 13);
  pin = &PINC;
}
// Discharge the pin first by setting it low and output
*port &= ~(bitmask);
*ddr  |= bitmask;
delay(1);
// Make the pin an input WITHOUT the internal pull-up on
*ddr &= ~(bitmask);
// Now see how long the pin to get pulled up
int cycles = 16000;
for(int i = 0; i < cycles; i++){
if (*pin & bitmask){
  cycles = i;
  break;
}
}
// Discharge the pin again by setting it low and output
//  It’s important to leave the pins low if you want to
//  be able to touch more than 1 sensor at a time – if
//  the sensor is left pulled high, when you touch
//  two sensors, your body will transfer the charge between
//  sensors.
*port &= ~(bitmask);
*ddr  |= bitmask;
return cycles;
}