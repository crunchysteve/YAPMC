#ifndef input_h
  #define input_h

  // Initialise time setting button functions
  
  void mins_btn(){      //  Increment minutes by 1 each second.
    int waitTime = 1;
    unsigned long nowTime = millis()/1000;
    if(digitalRead(D3) == LOW && nowTime > actTime){
      minutes++;
      if(minutes > 59){
        minutes = 0;
      }
      actTime = nowTime;
    }
  }
  
  void hour_btn(){      //  Increment hours by 1 each second.
    int nowTime = millis()/1000;
    if(digitalRead(D4) == LOW && nowTime > actTime){
      hours++;
      if(hours > 11){
        hours=0;
        ampm=!ampm;
      }
      actTime = nowTime;
    }
  }

  void inInit(){
    pinMode(D3,INPUT_PULLUP);  //  Initialise minutes increment button input.
    pinMode(D4,INPUT_PULLUP);  //  Initialise hours increment button input.
  }

#endif
