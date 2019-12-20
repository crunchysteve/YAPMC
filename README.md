# YAPMC: Yet Another Panel Meter Clock
Using panel meters, driven by an Arduino or compatible, to tell time without an RTC, using SO-45, Class 2.5, panel meters easily found on "teh bays."

![s-l1600](s-l1600.jpg) ![Meter Case](panel-meter-clock-case/meter-clock-case-sml.png)
          
## Basics
The idea of this project is to develop a clock which gives the illusion of being analog, despite being very digital inside. Even the drift resulting from not having a real time clock module is a deliberate choice. Using two SO-45 panel meters like the one above to display Hours and Minutes via PWM output (This meter needs its ballast resistor removed and a new scale, of course) on an ESP8266 (D1 mini, particularly), or any other class of microcontroller, gives an easy-to-read, general time, accurate to the minute.

With the addition of an AM/PM light, LED backlighting within the meters (done while removing the ballast) and 2 buttons, for setting hours and minutes respectively, the clock is as familiar to operate as any retro bedside clock from the 70s or 80s. By using a millis() reset and time correction factors should minimise the need to reset the time. Optionally, the any small amount of drift can be corrected with the buttons.

## Scope

(more to come)
