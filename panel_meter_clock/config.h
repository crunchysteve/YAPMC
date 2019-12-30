/*
 * config.h contains constants and variables for the package
 */
#ifndef config_h
  #define config_h

  #define tckLen 100            // Length of "ticks"
  #define tikCnt 1000 / tckLen  // Number of "ticks" per second

  #define debug    1            // Enables debug mode, allowing the terminal to display time 1 = debug, 0 = production
  #define blMode   0            // 1 if LDR senses ambient light, 0 if backlight always on
  #define ssMode   1            // 1 if flashed LED for seconds, 0 otherwise
  #define minFctr 79            // panel meter correction factor
  #define hrsFctr 84            // panel meter correction factor

  // initiate timer looping variables
  unsigned long timeNow = 0;    // used to count ticks and minimise inaccuracy of millis() reset
  unsigned long timePrv = 0;    // used to count ticks and minimise inaccuracy of millis() reset

  // Initiate Time Variables:
  int ticks = 0;                // counting ticks minimises effects of millis() rollover
  int seconds = 0;              // count seconds
  int minutes = 36;             // count minutes
  int hours = 4;                // count hours
  int ampm = 1;                 // set AM/PM light state
  int secsThen = 0;
  int actTime = 0;

#endif
