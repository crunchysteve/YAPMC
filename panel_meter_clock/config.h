/*
 * config.h contains constants and variables for the package
 */
#ifndef config_h
  #define config_h

  #define tckLen 100            // Length of "ticks"
  #define tikCnt 1000 / tckLen  // Number of "ticks" per second

  #define blMode 0              // 1 if LDR senses ambient light, 0 if backlight always on
  #define ssMode 0              // 1 if flashed LED for seconds, 0 otherwise
  #define mtrRte 50             // meter rating in microamperes
  #define resistor 3300         // meter buffer resistor in ohms
  #define float vcc 3.3         // logic pin HIGH voltage

  // initiate timer looping variables
  unsigned long timeNow = 0;    // used to count ticks and minimise inaccuracy of millis() reset
  unsigned long timePrv = 0;    // used to count ticks and minimise inaccuracy of millis() reset

  // Initiate Time Variables:
  int ticks = 0;
  int seconds = 0;
  int minutes = 0;
  int hours = 0;
  int ampm = 0;

#endif
