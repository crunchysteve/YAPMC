#ifndef termModule_h
  #define termModule_h

  void term(){
    if(debug == 1){
      if(ampm == 0){
        Serial.print("AM ");
      } else {
        Serial.print("PM ");
      }
      Serial.print(hours);
      Serial.print(":");
      Serial.print(minutes);
      Serial.print(":");
      Serial.print(seconds);
      Serial.print(" ");
      if(seconds%2 == 0){
        Serial.print(" ");
      } else {
        Serial.print("*");
      }
      Serial.println();
    }
  }

#endif
