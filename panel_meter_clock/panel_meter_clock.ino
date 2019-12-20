// Written by crunchysteve,
// based on code by Ruben Marc Speybrouck from
// Timekeeping on ESP8266 & Arduino Uno WITHOUT an RTC (Real Time CLock)?
// at https://www.instructables.com/id/TESTED-Timekeeping-on-ESP8266-Arduino-Uno-WITHOUT-/

#include "config.h"
#include "pins.h"
#include "time_wrap.h"
#include "input.h"
#include "output.h"
#include "termModule.h"

void setup(){
// put your setup code here, to run once
  inInit();
  outInit();
  Serial.begin(9600);
}

void loop(){
  //  time_wrap.h
  tick();       //  The main timekeeping engine.

  //  input.h functions
  mins_btn();   //  Advances the minutes value by 1 every second. (For setting time.)
  hour_btn();   //  Advances the hours value by 1 every second. (For setting time.)

  //  output.h functions
  flsSec();     //  Flashes the Seconds LED. (Optional display feature.)
  drvMns();     //  Uses PWM to drive the Minutes display meter.
  drvHrs();     //  Uses PWM to drive the Hours display meter.
  drvAmPm();    //  Sets the AM/PM LED to appropriate time of day.

  //  termModule.h function
  term();       //  Used while debugging, commented out for production build.
}
