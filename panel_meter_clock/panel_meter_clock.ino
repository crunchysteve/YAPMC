// Written by Stephen Harold Jay (crunchysteve),
// based on code by Ruben Marc Speybrouck from
// Timekeeping on ESP8266 & Arduino Uno WITHOUT an RTC (Real Time CLock)?
// at https://www.instructables.com/id/TESTED-Timekeeping-on-ESP8266-Arduino-Uno-WITHOUT-/

#include "pins.h"
#include "meters.h"
#include "millis_reset.h"
#include "display.h"
#include "input.h"

int bl_mode = 0;            // 1 if LDR senses ambient light, 0 otherwise
int ss_mode = 0;            // 1 if flashed LED for seconds, 0 otherwise
int mtr_rt = 50;            // meter rating in microamperes

unsigned long timeNow = 0;  // time looping variables
unsigned long timeLast = 0;

//Time start Settings:
int startingHour = 12; // used to correct time daily

// set your starting hour here, not below at int hour. This ensures accurate daily correction of time
int seconds = 0;
int minutes = 33;
int hours = startingHour;
int days = 0;

//Accuracy settings
int dailyErrorFast = 0; // set the average number of milliseconds your microcontroller's time is fast on a daily basis
int dailyErrorBehind = 0; // set the average number of milliseconds your microcontroller's time is behind on a daily basis
int correctedToday = 1; // do not change this variable, one means that the time has already been corrected today for the error in your boards crystal. This is true for the first day because you just set the time when you uploaded the sketch.

void setup(){
// put your setup code here, to run once
  Serial.begin(9600);
}

void loop(){
// put your main code here, to run repeatedly:
  timeNow = millis()/1000; // the number of milliseconds that have passed since boot
  seconds = timeNow - timeLast;

//the number of seconds that have passed since the last time 60 seconds was reached.
  if (seconds == 60){
    timeLast = timeNow;
    minutes = minutes + 1;
  }

//if one minute has passed, start counting milliseconds from zero again and add one minute to the clock.
  if (minutes == 60){
    minutes = 0;
    hours = hours + 1;
  }

// if one hour has passed, start counting minutes from zero and add one hour to the clock
  if (hours == 24){
    hours = 0;
    days = days + 1;
  }

//if 24 hours have passed, add one day
  if (hours ==(24 - startingHour) && correctedToday == 0){
    delay(dailyErrorFast*1000);
    seconds = seconds + dailyErrorBehind;
    correctedToday = 1;
  }

//every time 24 hours have passed since the initial starting time and it has not
//been reset this day before, add milliseconds or delay the program with some 
//milliseconds. Change these varialbes according to the error of your board.
//The only way to find out how far off your boards internal clock is, is by 
//uploading this sketch at exactly the same time as the real time, letting 
//it run for a few days and then determining how many seconds slow/fast your 
//boards internal clock is on a daily average. (24 hours).
  if (hours == 24 - startingHour + 2) {
    correctedToday = 0;
  }
//let the sketch know that a new day has started for what concerns correction, if this line was not here the arduiono // would continue to correct for an entire hour that is 24 - startingHour.
  Serial.print("The time is: ");
  Serial.print(days);
  Serial.print(":");
  Serial.print(hours);
  Serial.print(":");
  Serial.print(minutes);
  Serial.print(":");
  Serial.println(seconds);
}
