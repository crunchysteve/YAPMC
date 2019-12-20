#ifndef time_wrap_h
  #define time_wrap_h
  
  void tick(){
    timeNow = millis(); // the number of milliseconds that have passed since boot
    if(timeNow >= timePrv + tckLen || timeNow < timePrv){
      ticks += 1;
      timePrv = timeNow;
    }
    
  //the number of ticks that have passed since the last time a second was reached.
    if (ticks > tikCnt - 1){
      seconds += 1;
      ticks = 0;
    }

  //the number of seconds that have passed since the last time 60 seconds was reached.
    if (seconds > 59){
      minutes += 1;
      seconds = 0;
    }

  //if one minute has passed, start counting milliseconds from zero again and add one minute to the clock.
    if (minutes > 59){
      hours += 1;
      minutes = 0;
    }

  // if one hour has passed, start counting minutes from zero and add one hour to the clock
    if (hours >= 12){
      ampm = !ampm;
      hours = 0;
    }
  }

#endif
