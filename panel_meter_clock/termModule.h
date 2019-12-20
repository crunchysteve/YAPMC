#ifndef termModule_h
  #define termModule_h
  void term(){
    if(seconds == 0){
      Serial.println();
      Serial.print("The time is: ");
      Serial.print(hours);
      Serial.print(":");
      Serial.print(minutes);
      Serial.print(" ");
      if(ampm==0){
        Serial.println("AM");
      } else {
        Serial.println("PM");
      }
    } else {
      if(seconds%2==0){
        Serial.print("-");
      } else {
        Serial.print("|");
      }
    }
  }

#endif
