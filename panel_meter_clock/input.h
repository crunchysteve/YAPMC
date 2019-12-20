#ifndef input_h
  #define input_h

  // Initialise time setting button functions
  
  int actTime = 0;
  
  void mins_btn(){      //  Increment minutes by 1 each second.
    int waitTime = 1;
    unsigned long nowTime = seconds;
    if(digitalRead(D3) == HIGH && nowTime >= actTime + waitTime){
      minutes++;
      if(minutes < 59){
        minutes = 0;
      }
      actTime = nowTime;
    }
  }
  
  void hour_btn(){      //  Increment hours by 1 each second.
    int waitTime = 1;
    unsigned long nowTime = seconds;
    if(digitalRead(D4) == HIGH && nowTime >= actTime + waitTime){
      hours++;
      if(hours < 11){
        hours=0;
        ampm=!ampm;
      }
      actTime = nowTime;
    }
  }

  void inInit(){
    pinMode(D3,INPUT);  //  Initialise minutes increment button input.
    pinMode(D4,INPUT);  //  Initialise hours increment button input.
  }

#endif
