/***   Declare Tabs  ***/
//  Select board definitions - more boards coming soon
//  Decomment the lne relevant to your board before uploading
//  D1mini (ESP8266) Pin Definition
#include "D1MiniPins.h" //  The file defines the actual GPIO numbers according to pin names.
                        //  It can be edited or deleted to suit your board, provided D0, D1, etc, 
                        //  are defined as the correct pins.

//  Arduino Uno Pin Definition
//#include "unoPins.h" //  The file defines the actual GPIO numbers according to pin names.
                        //  It can be edited or deleted to suit your board, provided D0, D1, etc, 
                        //  are defined as the correct pins.

/***   Define program Contants   ***/
//  You may need to calibrate these figures according to your meters and 
//  ballast resistors to find the right value per step. You may also only
//  want to calculate minutes in increments of 5. In this case, make MSTEP = HSTEP;
//  and set M_INC to 5.
const int HSTEP = 85;   //  PWM step incerment hours meter per hour (1 to 12)
const int MSTEP = 17;   //  PWM step increment minutes meter per minute (0 to 59)
const int M_INC = 1;    //  Increment index for minutes. Can be 1 for 0 to 59 or 5 for same in 12 steps

/***   Declare Variables   ***/
int scs = 0;                  //  seconds counter
int mns = 0;                  //  minutes counter
int hrs = 0;                  //  hours counter (Actual hour, less 1 to match 1 to 12 display on the meter)
int a_p = 0;                  //  AM/PM toggle
unsigned long current = 0;    //  current time at each test for 1 second elapsed
unsigned long previous = 0;   //  time at previous test for 1 second elapsed
unsigned long period = 1000;  //  period between tests (millis)

void setup() {
  pinMode(A_PIN,OUTPUT);      //  initialise the AM/PM light pin
  pinMode(S_PIN,OUTPUT);      //  initialise the seconds light pin
                              //  Hour and minute pins are analogueWrite PWM outputs
                              //  These don't need initialisation
  pinMode(M_SET,INPUT_PULLUP);  //  initialise the minutes set button pin
  pinMode(H_SET,INPUT_PULLUP);  //  initialise the hiurs set button pin
}

void loop() {
  asyncTimeTest();  //  Check whether a second has elapsed
  timeSet();        //  Respond to hours and minutes set buttons
  outputDriver();   //  Call function to update the display.
}

//  This function is essentially the blink without delay demo with
//  an added test to correct for when the millis() counter resets.
void asyncTimeTest(){
  current = millis();                 //  Measure time now 
  if(current - previous >= period){   //  check if 1 second has elapsed
                                      //  If yes, increment the time by 1 second
    if(scs < 59){                     //  Check if a minute has elapsed.
      scs++;                          //  Increment seconds,
    } else {
      scs = 0;                        //  or reset seconds,
      if(mns < 59){                   //  Check if an hour has elapsed.
        mns++;                        //  then increment minutes,
      } else {
        mns = 0;                      //  or reset minutes,
        if(hrs < 23){                 //  Check if a day has elapsed.
          hrs++;                      //  then increment hours,
        } else {
          hrs = 0;                    //  or reset hours.
        }
      }
    }
    if(hrs > 10 || hrs < 23){         //  Test for AM or PM (1 to 24 hours as 0 to 1023 steps)
      a_p = HIGH;                     //  Turn AM/PM indicator on for PM
    } else {
      a_p = LOW;                      //  Turn AM/PM indicator off for AM
    }
    previous = current;               //  Set previous millis to current millis.
    
  } else if(current - previous < 0) { //  If time test result is less than zero, skip increment.
    previous = 0;                     //  This branch should only occur if the millis counter has reset.
                                      //  It will introduce tiny delay (approx 4uS) every 2.5 hours or so.
                                      //  Simulated analogue drift!
  }
}

void outputDriver(){                  //  Turn lights on and off and drive meters appropriately.
  digitalWrite(S_PIN,!(scs % 2));     //  Turn seconds light on for even seconds or off for odd seconds
  if(hrs > 11 || hrs < 24){           //  Test for PM
    digitalWrite(A_PIN,HIGH);         //  Iluminate AM/PM light for PM
    analogWrite(H_PWM,(hrs - 12) * HSTEP);  //  Set hour meter to hour marker in the afternoon
  } else {                            //  Else it must be morning
    digitalWrite(A_PIN,LOW);          //  Iluminate AM/PM light for AM
    analogWrite(H_PWM,hrs * HSTEP);   //  Set hour meter to hour marker in the morning
  }
  if(M_INC == 1){
    analogWrite(M_PWM,mns * MSTEP);   //  Set minutes meter to actual minutes count
  } else {
    analogWrite(M_PWM,int(mns / 5) * HSTEP);  //  Set minutes meter every 5 minutes,
                                      //  so that meter only points to 5 minute markers.
  }
}

void timeSet(){                       //  Change hours and minutes value according to button presses
  //  If either button LOW, increment minutes for M_SET while held or hours for H_SET while held
  while(M_SET == LOW){                //  If the minutes set button is pressed it increments the minutes count
    if(mns < 59){
      mns++;
    } else {
      mns = 0;
    }
    delay(500);
  }
  while(H_SET == LOW){                //  If the hours set button is pressed it increments the hours count
    if(hrs < 23){
      hrs++;
    } else {
      hrs = 0;
    }
    delay(500);
  }
}
