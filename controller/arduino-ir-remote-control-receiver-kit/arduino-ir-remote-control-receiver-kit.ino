#include <IRremote.h>     

int RECV_PIN =6;     
int bluePin = 11;     
int greenPin = 10;        
int redPin = 9;     

IRrecv irrecv(RECV_PIN);     
decode_results results;    
 

void setup(){     
  Serial.begin(9600);     
  irrecv.enableIRIn();     
  pinMode(redPin, OUTPUT);     
  pinMode(greenPin, OUTPUT);     
  pinMode(bluePin, OUTPUT);     
}     


void loop(){     
  if (irrecv.decode(&results)){     
	int value = results.value;     
	Serial.println(value);      
       switch(value){     
         case 12495: //Keypad button "1"     
         //set color red     
         analogWrite(redPin, 0xFF);     
         analogWrite(greenPin,0x08);     
         analogWrite(bluePin, 0xFB);     
         }     
       switch(value){     
         case -7177: //Keypad button "2"     
         //set color skyblue     
         analogWrite(redPin, 0x00);     
         analogWrite(greenPin,0xFF);     
         analogWrite(bluePin, 0xFF);     
         }     
         switch(value){     
         case 539: //Keypad button "3"     
          //set color pink     
         analogWrite(redPin, 0x1F);     
         analogWrite(greenPin,0x00);     
         analogWrite(bluePin, 0x8F);     
         }     
         switch(value){     
         case 25979: //Keypad button "4"     
         //set color light green     
         analogWrite(redPin, 0x11);     
         analogWrite(greenPin,0x5F);     
         analogWrite(bluePin, 0x01);     
         }     
       irrecv.resume();      
   }     
} 