#include <PS2X_lib.h>
// Definitions PS2 Controller Pin Setup
#define ps2_att 10
#define ps2_cmd 11
#define ps2_dat 12
#define ps2_clk 13
#define pressures true
#define rumble true

PS2X ps2x;  // create PS2 Controller Class
int ps2_error = 0;

void function_circle() {
}

void setup()
{
  Serial.begin(9600);
  // PS2 Controller Setup
  do {
    ps2_error = ps2x.config_gamepad(ps2_clk, ps2_cmd, ps2_att, ps2_dat, pressures, rumble); //GamePad(clock, command, attention, data, Pressures?, Rumble?)
    if (ps2_error == 0) {
        Serial.print("PS2 Controller Conntected.");
        break;
    }
    else {
        delay(100);
    }
  } while (1);

}


void loop()
{
    ps2x.read_gamepad(false, 0);  //read ps2 controller and set large motor to spin at vibrate speed (read_gamepad(boolean motor1, byte motor2);)
    if(ps2x.ButtonPressed(PSB_CIRCLE)){
        Serial.print("Circle is pressed");
      function_circle();
    }
    delay(10);

}