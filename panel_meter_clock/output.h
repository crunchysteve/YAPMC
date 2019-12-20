#ifndef output_h
  #define output_h

  void flsSec(){            //  Writes the D5 pin high when seconds are an even number.
    // drives meters with PWM
    if(ssMode==1 && seconds%2==1){
      digitalWrite(D5,LOW);
    } else {
      digitalWrite(D5,HIGH);
    }
  }

  void drvMns(){            //  Uses PWM to drive the minutes meter to a value proportionate to minutes.
    if(ssMode==1){
      
    }
  }

  void drvHrs(){            //  Uses PWM to drive the hours meter to a value proportionate to hours.
    // drives meters with PWM
  }

  void drvAmPm(){            //  Writes the D5 pin high when seconds are an even number.
    digitalWrite(D8,ampm);
  }

  void outInit(){
    if(blMode == 1){
      pinMode(D0,OUTPUT);   //  Initialises the backlight outputs only if blMode is enabled.
      pinMode(D1,OUTPUT);   //  If blMode is 0, wirebacklights directly to 5V via a resistor each.
    }
    if(ssMode == 1){
      pinMode(D5,OUTPUT);   //  Initialises the seconds pin only if ssMode is enabled.
                            //  If ssMode is 0, no seconds LED is used.
    }
    pinMode(D6,OUTPUT);     //  Initialises the minutes pin.
    pinMode(D7,OUTPUT);     //  Initialises the hours pin.
    pinMode(D8,OUTPUT);     //  Initialises the AM/PM pin.
  }

#endif
