#ifndef pins_h
  #define pins_h

  // defining the GPIO pins for D1 Mini board
  #define TX  1 // hardware serial TXD for IDE comms
  #define RX  3 // hardware serial rXD for IDE comms
  #define A0  6 // Optional LDR for backlight control
  #define D0 16 // Not currently used
  #define D1  5 // Backlight LED (output, Minutes: can be hardwired instead)
  #define D2  4 // Backlight LED (output, Hours:   can be hardwired instead)
  #define D3  0 // Minutes increment button (input)
  #define D4  2 // Hours increment button (input)
  #define D5 14 // Flash Seconds LED (output, optional)
  #define D6 12 // Minutes meter pin (output)
  #define D7 13 // Hours Meter pin (output)
  #define D8 15 // AM/PM LED (output)

#endif
