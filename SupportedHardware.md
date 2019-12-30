* Currently Supported and Tested Hardware *

Wemos D1 mini, D1 mini Pro, D1. (ESP8266 modules) Most ESP8266 boards should work with, at most, minor tweaks to pins.h.

May be supported with little or no change on various arduinos but not yet tested. Please feel free to add your firmware commits to this project (please branch or add a new folder) to support any boards you may have tested this on. Most compatibility changes should only need changes to pins.h but you mileage may vary. The panel meters are driven by analogueWrite() commands, so an Arduino Uno will need the hours and minutes output pins changed for sure.
