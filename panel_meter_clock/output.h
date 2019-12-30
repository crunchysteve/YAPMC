#ifndef output_h
  #define output_h

  void flsSec(){              //  If ssMode is active, writes pin D5 high when seconds are an even number,
    if(ssMode==1 && seconds%2==1){
      digitalWrite(D5,HIGH);
    } else {
      digitalWrite(D5,LOW);   //  and low when they are an odd number.
    }
  }

  void drvMns(){            //  Uses PWM to drive the minutes meter to a value proportional to minutes.
    analogWrite(D6,minFctr*minutes/5);
  }

  void drvHrs(){            //  Uses PWM to drive the hours meter to a value proportionate to hours.
    // drives meters with PWM
    analogWrite(D7,hrsFctr*hours);
  }

  void drvAmPm(){            //  Writes the D5 pin high when seconds are an even number.
    digitalWrite(D8,ampm);
  }

  void outInit(){
    hours = hours-1;        //  Corrects analog hours to digital hours. (1 to 12 becomes 0 to 11.)
    
    if(blMode == 1){
      pinMode(D1,OUTPUT);   //  Initialises the backlight outputs only if blMode is enabled.
      pinMode(D2,OUTPUT);   //  If blMode is 0, wirebacklights directly to 5V via a resistor each.
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
